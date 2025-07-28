#include "SDB.h"
#include <math.h>

#define MAX_SIZE 10
#define MIN_SIZE 3
#define HT_SIZE 11

#if HT_SIZE >= MAX_SIZE

uint8 ELEMENTS_NUM=0;
student* DB[10]={NULL};

const char Tompstone_Char;
const void* const Tompstone = (void*)&Tompstone_Char;

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

uint8 HASH_FN_QUAD_PROP(uint8 x,int i)
{
    return ((x%MAX_SIZE)+(int)pow(i,2))%MAX_SIZE;
}

void INS_CLOSE_HASH(student* s)
{
    int temp = s->Student_ID;
    int i = 0;
    uint8 temp = HASH_FN_QUAD_PROP(s->Student_ID,i);
    while(DB[temp]!=NULL&&DB[temp]!=Tompstone)
        temp = HASH_FN_QUAD_PROP(s->Student_ID,++i);

    DB[temp]=s;
    ELEMENTS_NUM++;
}

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

bool SDB_AddEntry()
{
;
}

void SDB_DeleteEntry(uint32 id)
{
;
}

bool SDB_ReadEntry(uint32 id)
{
;
}

void SDB_GetList(uint8* count, uint32* list)
{
;
}

bool SDB_IsIdExist(uint32 id)
{
;
}

#endif