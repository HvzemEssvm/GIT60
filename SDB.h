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

/**
 * @note about "Create SDB.h to have the function declaration that’s you use in the project"
 * I only added the function to be shared between main.c and and SDB.c file here, To apply
 * the "Encapsulation Principle".
 */
extern void SDB_APP();
#endif