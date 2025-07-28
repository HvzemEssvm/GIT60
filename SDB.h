#ifndef SDB_H
#define SDB_H

#include "STD.h"

typedef struct SimpleDB
{
    uint32 Student_ID;
    uint32 Student_year;
    uint32 Course1_ID;
    uint32 Course1_grade;
    uint32 Course2_ID;
    uint32 Course2_grade;
    uint32 Course3_ID;
    uint32 Course3_grade;
    
}student;

extern uint8 SDB_GetUsedSize();
extern bool SDB_IsFull();
extern bool SDB_IsIdExist(uint32 id);
extern bool SDB_AddEntry();
extern bool SDB_ReadEntry(uint32 id);
extern void SDB_DeleteEntry(uint32 id);
extern void SDB_GetList(uint8* count, uint32* list);
extern void SDB_APP();

#endif