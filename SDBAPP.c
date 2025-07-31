#include "PRIV_LIB.h"


/**
 * @brief 
 * 
 * @param choice 
 */
void SDB_action(uint8 choice)
{
    uint32 temp;
    switch(choice)
    {
        case 1:
            if(SDB_AddEntry())
                printf("\nEntry Has Been Added Successfully");
            else
                printf("\nEntry Hasn't Been Added\n");    
            break;

        case 2:
            printf("\nNumber of Entries: %d\n",SDB_GetUsedSize());
            break;

        case 3:
            if(Fetch_Validate_Uint("Student's ID",&temp))
            {
                if(!SDB_ReadEntry(temp))
                {
                    errorD02();
                    printf("\nreturning...\n");
                }
            }
            else
                printf("\nreturning..\n.");

            break;
        case 4:
            uint32 list[MAX_SIZE]={0};
            uint8 count;
            SDB_GetList(&count,list);
            if(count==0)
                errorD04();
            else
            {
                printf("\n----------------------------");
                for(int i=0;i<count;i++)
                    printf("\nID No. (%d):%d",i+1,list[i]);
                printf("\n----------------------------");
            }
            break;

        case 5:
            if(Fetch_Validate_Uint("Student's ID",&temp))
                printf("\nID %s\n",SDB_IsIdExist(temp)?"Exists":"Doesn't Exist");
            else
                printf("\nreturning...\n");
            break;

        case 6:
            if(Fetch_Validate_Uint("Student's ID",&temp))
                SDB_DeleteEntry(temp);
            else
                printf("\nreturning...\n");
            break;

        case 7:
            printf("\nDatabase is %sFull\n",SDB_IsFull()?"":"Not ");
            break;

        default:
            return;
    }
}

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
        char choice[10];
        printf("\nChoose from the menu below:");
        printf("\nEnter (1) To add entry"  
               "\nEnter (2) To get used size in database"
               "\nEnter (3) To read student data"  
               "\nEnter (4) To get the list of all student IDs" 
               "\nEnter (5) To check if ID exists"
               "\nEnter (6) To delete student data"
               "\nEnter (7) To check is database is full" 
               "\nEnter (0) To exit");
        printf("\n--> ");
        fetch_str(choice,sizeof(choice));
        uint8 temp = (uint8)atoi(choice);
        if(!isUInt(choice)||temp > 7||temp<0)
        {   
            errorI02(); 
            continue;
        }
        if(temp)
            SDB_action(temp);
        else
        {    
            printf("\n------------------------------");
            printf("\n   Thanks for using our API   ");
            printf("\n------------------------------");
            DEL_DB();
            return;
        }
    }
}
