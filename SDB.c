#include "PRIV_LIB.h"
#include <math.h>
#include <ctype.h>
#include <string.h>

#if HT_SIZE >= MAX_SIZE

uint8 ELEMENTS_NUM=0;
student* DB[10]={NULL};

const char Tompstone_Char;
const void* Tompstone = (void*)&Tompstone_Char;

/**
 * @brief 
 * 
 * @return student* 
 */
student* INIT_STUDENT()
{
    student* s = (student*)malloc(sizeof(student));
    if(s)
    {
        s->Course1_grade    =   s->Course2_grade    =   s->Course3_grade=0;
        s->Course1_ID       =   s->Course2_ID       =   s->Course3_ID=0;
        s->Student_ID       =   s->Student_year=0;
    }
    return s;
}

/**
 * @brief 
 * 
 */
void DEL_DB()
{
    for(int i=0;i<HT_SIZE;i++)
    {
        if(DB[i]!=NULL&&DB[i]!=Tompstone)
        {    
            free(DB[i]);
            DB[i]=NULL;
        }
    }
}

/**
 * @brief 
 * 
 * @param str 
 * @return true 
 * @return false 
 */
bool isUInt(char* str)
{
    if(str)
    {
        for(int i=0;str[i]!='\0';i++)
            if(!isdigit(str[i])&&str[i]!=' ')
                return false;
        return true;
    }
    return false;
}

/**
 * @brief 
 * 
 * @param str 
 * @param byte_size 
 */
void fetch_str(char* str,const int byte_size)
{
    if(str)
    {
        fgets(str,byte_size,stdin);
        if(str[strlen(str)-1]=='\n')
            str[strlen(str)-1]='\0';
    }
}

/**
 * @brief 
 * 
 * @param x 
 * @param i 
 * @return uint8 
 */
uint8 HASH_FN_LINEAR_PROP(uint32 x,int i)
{
    return ((x%HT_SIZE)+i)%HT_SIZE;
}

/**
 * @brief 
 * 
 * @param s 
 */
void INS_CLOSE_HASH(student* s)
{
    int i = 0;
    uint8 temp = HASH_FN_LINEAR_PROP(s->Student_ID,i);
    while(i<HT_SIZE&&DB[temp]!=NULL&&DB[temp]!=Tompstone)
        temp = HASH_FN_LINEAR_PROP(s->Student_ID,++i);

    DB[temp]=s;
    ELEMENTS_NUM++;
}

/**
 * @brief 
 * 
 * @param id 
 * @return uint8 
 */
int Fetch_INDEX_BY_ID(uint32 id)
{
    int i=0;
    uint8 temp = HASH_FN_LINEAR_PROP(id,i);
    while(DB[temp]!=NULL&&i<HT_SIZE)
    {
        if(DB[temp]!=Tompstone)
            if(DB[temp]->Student_ID==id)
                return temp;
        temp = HASH_FN_LINEAR_PROP(id,++i);
    }
    return -1;
}

/**
 * @brief 
 * 
 * @param input_name 
 * @param input_val 
 * @return true 
 * @return false 
 */
bool Fetch_Validate_Uint(char* input_name,uint32* input_val)
{
    char temp[20];
    while(true)
    {
        printf("\nEnter (r) to return to previous menu without saving"
               "\nOr Enter %s\n--> ",input_name);
        fetch_str(temp,20);
        if(strcasecmp(temp,"r")==0)
            return false;
        if(!isUInt(temp))
        {
            errorI01();
            continue;
        }
        break;
    }
    if(strstr(input_name,"year")!=NULL||strstr(input_name,"Year")!=NULL)
    {
        int temp_int = atoi(temp);
        if(temp_int<1900||temp_int>3000)
        {
            errorI02();
            return Fetch_Validate_Uint(input_name,input_val);
        }
    }
    *input_val = atoi(temp);
    return true;
}

// ------------------------------> Required Methods <------------------------------

/**
 * @brief it compares the number of elements in the DB which is updated real-time to the fixed maximum capacity.
 * @attention this function must be used before any insertion process
 * 
 * @return true in case of reaching the 
 * @return false 
 */
bool SDB_IsFull()
{
    return ELEMENTS_NUM==MAX_SIZE;
}

/**
 * @return uint8 as the current population in the DB
 */
uint8 SDB_GetUsedSize()
{
    return ELEMENTS_NUM;
}

/**
 * @brief 
 * 
 * @return true 
 * @return false 
 */
bool SDB_AddEntry()
{
    if(SDB_IsFull())
    {   
        errorD01();
        return false;
    }

    student* s = INIT_STUDENT();
    if(!s)
    {
        errorM01();
        return false;
    }

    if (!Fetch_Validate_Uint("Student ID",&s->Student_ID)           ||
       !Fetch_Validate_Uint("Student Year",&s->Student_year)        ||
       !Fetch_Validate_Uint("1st Course ID",&s->Course1_ID)         ||
       !Fetch_Validate_Uint("1st Course Grade",&s->Course1_grade)   ||
       !Fetch_Validate_Uint("2nd Course ID",&s->Course2_ID)         ||
       !Fetch_Validate_Uint("2nd Course Grade",&s->Course2_grade)   ||
       !Fetch_Validate_Uint("3rd Course ID",&s->Course3_ID)         ||
       !Fetch_Validate_Uint("3rd Course Grade",&s->Course3_grade))
    {   free(s);    return false; }
    
    INS_CLOSE_HASH(s);
    return true;
}

/**
 * @brief 
 * 
 * @param id 
 */
void SDB_DeleteEntry(uint32 id)
{
    if(ELEMENTS_NUM<MIN_SIZE+1)
    {
        errorD03();
        printf("\n%d is NOT deleted..\n",id);
        return;
    }

    int temp=Fetch_INDEX_BY_ID(id);
    if(temp==-1)
    {
        errorD02();
        return;
    }
    char confirm[10];
    while(true)
    {
        printf("\nAre you sure you want to delete student with id (%d)? (Y/N)\n--> ",id);
        fetch_str(confirm,sizeof(confirm));
        if(strcasecmp(confirm,"y")==0||strcasecmp(confirm,"n")==0)
            break;
        errorI01();
    }
    if(strcasecmp(confirm,"n")==0)
    {printf("\n%d is NOT deleted..\n",id);    return;}
    free(DB[temp]);
    DB[temp]=Tompstone;
    printf("\n%d is deleted successfully..\n",id);
}

/**
 * @brief 
 * 
 * @param id 
 * @return true 
 * @return false 
 */
bool SDB_ReadEntry(uint32 id)
{
    int temp=Fetch_INDEX_BY_ID(id);
    if(temp==-1)
        return false;
    printf("\n---------------------------------------------------");
    printf("\n - Student ID : %d"
           "\n - Student Year: %d"
           "\n - 1st Course ID: %d"
           "\n - 1st Course Grade: %d"
           "\n - 2nd Course ID: %d"
           "\n - 2nd Course Grade: %d"
           "\n - 3rd Course ID: %d"
           "\n - 3rd Course Grade: %d",
           DB[temp]->Student_ID,DB[temp]->Student_year,DB[temp]->Course1_ID,
           DB[temp]->Course1_grade,DB[temp]->Course2_ID,DB[temp]->Course2_grade,
           DB[temp]->Course3_ID,DB[temp]->Course3_grade);
    printf("\n---------------------------------------------------");
    return true;   
}

/**
 * @brief 
 * 
 * @param count 
 * @param list 
 */
void SDB_GetList(uint8* count, uint32* list)
{
    int i=0;
    for(i=0,*count=0;i<HT_SIZE;i++)
    {
        student* temp = DB[i];
        if(temp!=NULL&&temp!=Tompstone)
            list[(*count)++]=temp->Student_ID;
    }
}

/**
 * @brief 
 * 
 * @param id 
 * @return true 
 * @return false 
 */
bool SDB_IsIdExist(uint32 id)
{
    return Fetch_INDEX_BY_ID(id)!=-1;
}

#endif