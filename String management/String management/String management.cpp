#include "pch.h"
#include <iostream>
#include <string.h>
#include "UI.h"
#include "str_function.h"
#include <stdio.h>



int main()
{
    int liv_Mean_number = 0;
    while(1)
    {
        liv_Mean_number = 0;
        Get_menu();
        rewind(stdin);
        scanf("%d", &liv_Mean_number);
        switch(liv_Mean_number)
        {
            case 1:
                Get_insert_menu();
                break;
            case 2:
                Get_delete_menu();
                break;
            case 3:
                Get_update_menu();
                break;
            case 4:
                Get_find_menu();
                break;
            case 5:
                Get_count_menu();
                break;
            case 6:
                Get_memory_menu();
                break;
            case 7:
                printf("Bye!");
                return 0;
                break;
            default:
                printf("输入错误，请重试\r\n");
                break;
        }
        system("pause");
        system("cls");
    }
    return 0;
}
