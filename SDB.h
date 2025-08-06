#ifndef SDB_H
#define SDB_H

#include "STD.h"
#define MAX_SIZE 10
#define MIN_SIZE 3
#define HT_SIZE 11

typedef struct
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

void SDB_APP();

#endif