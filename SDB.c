#include "PRIV_LIB.h"
#include <math.h>
#include <ctype.h>
#include <string.h>

#if HT_SIZE >= MAX_SIZE 

// tracks number of elements (incremented during successful insertion) and decremented durin successful deletions
uint8 ELEMENTS_NUM = 0;

//initial DB (HASH Table Based)
student* DB[MAX_SIZE] = {NULL};

const char Tompstone_Char;
const void* Tompstone = (void*)&Tompstone_Char;

/**
 * @brief Allocates memory for a new student structure and initializes its members to zero.

 * @return student* A pointer to the newly allocated and initialized student structure, or NULL if memory allocation fails.
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
 * @brief Deallocates memory for all student entries in the database and sets their pointers to NULL.
 * */
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
 * @brief Checks if a given string contains only unsigned integer characters (digits and spaces).
 * 
 * @param str The string to be checked.
 * 
 * @return true If the string contains only digits and spaces, and is not empty.
 * @return false Otherwise.
 */
bool isUInt(char* str)
{
    if(str)
    {
        if(strcasecmp(str,"")==0)
            return false;

        for(int i=0;str[i]!='\0';i++)
            if(!isdigit(str[i])&&str[i]!=' ')
                return false;
                
        return true;
    }
    return false;
}

/**
 * @brief Reads a string from standard input, handling newline characters.
 * 
 * @param str The character array to store the fetched string.
 * @param byte_size The maximum number of bytes to read, including the null terminator.
 */
void fetch_str(char* str,const int byte_size)
{
    if(str)
    {
        fgets(str,byte_size,stdin);
        if(str[strlen(str)-1]=='\n')
            str[strlen(str)-1]='\0';
        else
        {
            int temp_char;
            while ((temp_char = getchar()) != '\n' && temp_char != EOF);
        }
    }
}

/**
 * @brief Implements a linear probing hash function for a hash table.
 * 
 * @param x The input key (student ID).
 * @param i The probe number (0 for the first attempt, 1 for the second, and so on).
 * 
 * @return uint8 The calculated hash index for the given key and probe number.
 */
uint8 HASH_FN_LINEAR_PROP(uint32 x,int i)
{
    return ((x%HT_SIZE)+i)%HT_SIZE;
}

/**
 * @brief Inserts a student entry into the hash table using linear probing for collision resolution.
 * 
 * @param s A pointer to the student structure to be inserted.
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
 * @brief Fetches the index of a student entry in the hash table by their ID.
 * 
 * @param id The student ID to search for.
 * 
 * @return int The index of the student entry in the hash table if found, otherwise -1.
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
 * @brief Prompts the user for a unsigned integer input, validates it, and stores it.
 * 
 * @param input_name A string representing the name of the input field (e.g., "Student ID", "Student Year").
 * @param input_val A pointer to the uint32 variable where the validated input will be stored.
 * 
 * @return true If a valid unsigned integer is entered and saved.
 * @return false If the user chooses to return to the previous menu or an invalid input is repeatedly entered.
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
 * @brief Compares the number of elements currently in the database to its maximum capacity.
 * 
 * @attention This function must be used before any insertion process.
 * 
 * @return true If the database is full (number of elements equals maximum capacity).
 * @return false If the database has available space.
 */
bool SDB_IsFull()
{
    return ELEMENTS_NUM==MAX_SIZE;
}

/**
 * @brief Returns the current number of student entries stored in the database.
 * 
 * @return uint8 The current population (number of used entries) in the database.
 */
uint8 SDB_GetUsedSize()
{
    return ELEMENTS_NUM;
}

/**
 * @brief Adds a new student entry to the database, prompting the user for all necessary details.
 * 
 * @return true If the student entry is successfully added.
 * @return false If the database is full, memory allocation fails, or the user cancels the input process.
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
    int temp_id;

    if (!Fetch_Validate_Uint("Student ID",&temp_id))
    {    free(s);    return false;  }
    
    if(SDB_IsIdExist(temp_id))
    {
        errorD05();
        free(s);   
        return false;  
    }
    
    s->Student_ID = temp_id;

    if(!Fetch_Validate_Uint("Student Year",&s->Student_year)        ||
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
 * @brief Deletes a student entry from the database based on their ID.
 * 
 * @param id The ID of the student to be deleted.
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
    ELEMENTS_NUM--;
    printf("\n%d is deleted successfully..\n",id);
}

/**
 * @brief Reads and displays the details of a student entry based on their ID.
 * 
 * @param id The ID of the student whose details are to be displayed.
 * 
 * @return true If the student entry is found and its details are displayed.
 * @return false If the student entry with the given ID is not found.
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
 * @brief Retrieves a list of all student IDs currently in the database.
 * 
 * @param count A pointer to a uint8 variable that will store the number of student IDs retrieved.
 * @param list A pointer to a uint32 array where the student IDs will be stored.
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
 * @brief Checks if a student with the given ID exists in the database.
 * 
 * @param id The student ID to check for existence.
 * 
 * @return true If a student with the given ID exists in the database.
 * @return false If no student with the given ID is found.
 */
bool SDB_IsIdExist(uint32 id)
{
    return Fetch_INDEX_BY_ID(id)!=-1;
}

#endif
