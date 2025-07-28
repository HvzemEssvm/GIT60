#include "PRIV_LIB.h"

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

void SDB_action(uint8 choice)
{
    switch(choice)
    {
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            break;
        case 7:
            break;
        default:
            return;
    }
}