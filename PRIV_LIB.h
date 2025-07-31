#ifndef PRIV_LIB_H
#define PRIV_LIB_H

#include "SDB.h"

#define errorI01()  printf("\n!! Invalid Input Format !!\n")
#define errorI02()  printf("\n!! Invalid Input Range !!\n")
#define errorM01()  printf("\n!! Couldn't Allocate Memory !!\n")
#define errorD01()  printf("\n!! Datebase is full; Max %d Entries !!\n",MAX_SIZE)
#define errorD02()  printf("\n!! Entry Not Found !!\n")
#define errorD03()  printf("\n!! Database is at Min (%d Entries) !!\n",ELEMENTS_NUM)
#define errorD04()  printf("\n!! Empty Database !!\n")
#define errorD05()  printf("\n!! An Entry Already Exists With The Same Info !!\n")

extern uint8 SDB_GetUsedSize();
extern bool SDB_IsFull();
extern bool SDB_IsIdExist(uint32 id);
extern bool SDB_AddEntry();
extern bool SDB_ReadEntry(uint32 id);
extern bool isUInt(char* str);
extern bool Fetch_Validate_Uint(char* input_name,uint32* input_value);
extern void SDB_DeleteEntry(uint32 id);
extern void SDB_GetList(uint8* count, uint32* list);
extern void fetch_str(char* str,const int byte_size);
extern void DEL_DB();

#endif

