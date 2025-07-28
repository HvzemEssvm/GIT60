#ifndef PRIV_LIB_H
#define PRIV_LIB_H

#include "STD.h"
#include "SDB.h"

#define errorI01()  printf("\nInvalid Input Format\n")
#define errorI02()  printf("\nInvalid Input Range\n")
#define errorM01()  printf("\nCouldn't Allocate Memory\n")
#define errorD01()  printf("\nDatebase is full; Max %d Entries\n",MAX_SIZE)
#define errorD02()  printf("\nEntry Not Found\n")
#define errorD03()  printf("\nDatabase is at Min; %d Entries\n",MIN_SIZE)
#define errorD04()  printf("\nEmpty Database")

extern uint8 SDB_GetUsedSize();
extern bool SDB_IsFull();
extern bool SDB_IsIdExist(uint32 id);
extern bool SDB_AddEntry();
extern bool SDB_ReadEntry(uint32 id);
extern bool isUInt(char* str);
extern void SDB_DeleteEntry(uint32 id);
extern void SDB_GetList(uint8* count, uint32* list);
extern void fetch_str(char* str,const int byte_size);
extern void DEL_DB();

#endif

