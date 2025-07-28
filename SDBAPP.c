#include "PRIV_LIB.h"

/**
 * @brief 
 * 
 */
void SDB_APP()
{
    printf("\n------------------------------");
    printf("\n  Welcome To Student Database ");
    printf("\n------------------------------");
    while(true)
    {
        char choice[2];
        printf("\nChoose from the menu below:");
        printf("\nEnter (1) To add entry"  
               "\nEnter (2) To get used size in database"
               "\nEnter (3) To read student data"  
               "\nEnter (4) To get the list of all student IDs" 
               "\nEnter (5) To check is ID is existed"
               "\nEnter (6) To delete student data"
               "\nEnter (7) To check is database is full" 
               "\nEnter (0) To exit");
        printf("\n--> ");
        fetch_str(choice,sizeof(choice));
        uint8 temp = (uint8)atoi(choice);
        if(temp > 7||temp<0)
        {   
            errorI02(); 
            continue;
        }
        if(temp)
            SDB_action(temp);
        else
        {    
            DEL_DB();
            return;
        }
    }
}

/**
 * @brief 
 * 
 * @param choice 
 */
void SDB_action(uint8 choice)
{
    char str[20];
    switch(choice)
    {
        case 1:
            if(SDB_AddEntry())
                printf("\nEntry Has Been Added Successfully");
            else
                printf("Entry Hasn't Been Added");    
            break;
        case 2:
            printf("\nNumber of Entries: %d",SDB_GetUsedSize());
            break;
        case 3:
            printf("\nEnter Student's ID\n--> ");
            fetch_str(str,sizeof(str));
            if(!isUInt(str))
            {
                errorI01();
                printf("\nreturning...");
            }
            else if(!SDB_ReadEntry((uint32)atoi(str)))
            {
                errorD02();
                printf("\nreturning...");
            }
            break;
        case 4:
            uint32 list[MAX_SIZE]={0};
            int count;
            SDB_GetList(&count,list);
            if(count==0)
                errorD04();
            else
            {
                printf("\n----------------------------");
                for(int i;i<count;i++)
                    printf("\nID No. (%d):%d",i+1,list[i]);
                printf("\n----------------------------");
            }
            break;
        case 5:
            printf("\nEnter Student's ID\n--> ");
            fetch_str(str,sizeof(str));
            if(!isUInt(str))
            {
                errorI01();
                printf("\nreturning...");
            }
            else
            {
                printf("\nID %s",SDB_IsIdExist((uint32)atoi(str))?"Exists":"Doesn't Exist");
            }
            break;
        case 6:
            printf("\nEnter Student's ID\n--> ");
            fetch_str(str,sizeof(str));
            if(!isUInt(str))
            {
                errorI01();
                printf("\nreturning...");
            }
            else
            {
                SDB_DeleteEntry((uint32)atoi(str));
            }
            break;
        case 7:
            printf("Database is %sFull",SDB_IsFull()?"":"Not ");
            break;
        default:
            return;
    }
}