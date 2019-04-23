#include "pch.h"
#include <stdio.h>
#include "UI.h"
#include "str_function.h"
#include <stdlib.h>
#include <string.h>

void Get_menu()
{
    printf("欢迎来到字符串动态管理系统\r\n");
    printf("请按照所需功能输入相应编号\r\n");
    printf("1.添加\r\n");
    printf("2.删除\r\n");
    printf("3.修改\r\n");
    printf("4.查找\r\n");
    printf("5.统计\r\n");
    printf("6.内存管理\r\n");
    printf("7.退出\r\n");
    return;
}


void Get_insert_menu()
{
    int liv_string_mark = 0;
    char lucv_buf[256] = "";
    int liv_string_num = 0;
    int liv_isfree = 0;
    printf("请输入:\r\n");
    rewind(stdin);
    scanf("%255s", lucv_buf);
    liv_string_mark = Find_free(lucv_buf);
    if ( liv_string_mark == 0)
    {
        printf("内存空间不足!\r\n");
        printf("请进行内存整理或者删除部分字符串!\r\n");
        return;
    }
    else
    {
        for (; liv_string_num < 0x1000; liv_string_num++)            //查找空闲编号，并写入。
        {
            if (*((short int *)gcv_Buf + liv_string_num) == 0)
            {
                liv_isfree = 1;
                *((short int *)gcv_Buf + liv_string_num) = liv_string_mark;
                break;
            }
        }
        if( liv_isfree == 0)
        {
            printf("编号已经全部使用，请清理空间\r\n");
        }
        else
        {
            printf("该字符串编号为%d\r\n", (liv_string_num + 1));
            Insert(gcv_Buf + liv_string_mark, lucv_buf);
            printf("添加成功");
        }
    }
    return;
}


void Get_delete_menu()
{
    int liv_string_num = 0;
    printf("请输入想要删除的字符串的编号\r\n");
    rewind(stdin);
    scanf("%d", &liv_string_num);
    if(liv_string_num > 0x1000 || liv_string_num < 1)
    {
        printf("输入错误\r\n");
    }
    else if(*((short int *)gcv_Buf + (liv_string_num - 1)) != 0)
    {
        Delete(*((short int *)gcv_Buf + (liv_string_num - 1)));
        *((short int *)gcv_Buf + (liv_string_num - 1)) = 0;
        printf("删除成功");
    }
    else
    {
        printf("该编号并未存储字符串。\r\n");
    }
    return;
}


void Get_update_menu()
{
    char lcv_string[256] = "";
    int liv_string_num = 0;
    printf ("请输入想要修改的字符串编号:\r\n");
    rewind (stdin);
    scanf("%d", &liv_string_num);
    if (liv_string_num < 1 || liv_string_num > 0x1000)
    {
        printf("输入错误！\r\n");
    }
    else if (*((short int *)gcv_Buf + (liv_string_num - 1)) != 0)
    {
        Delete(*((short int *)gcv_Buf + (liv_string_num - 1)));
        printf("请输入修改后的字符串内容:\r\n");
        rewind(stdin);
        scanf("%255s",lcv_string);
        Update(liv_string_num,lcv_string);
    }
    else
    {
        printf("该编号并未存储字符串。\r\n");
    }
    return;
}


void Get_find_menu()
{
    int liv_find_type = 0;
    int liv_string_num = 0;
    char lcv_string[256] = "";
    while(1)
    {
        liv_find_type = 0;
        printf ("请根据所需要的查找方式,输入对应编号：\r\n");
        printf ("1.查看全部字符串\r\n");
        printf ("2.按照编号进行查找\r\n");
        printf ("3.按照字符串内容进行查找\r\n");
        printf ("4.退出\r\n");
        rewind(stdin);
        scanf ("%d",&liv_find_type);
        switch(liv_find_type)
        {
            case 1:
                Show_all_string();
                break;
            case 2:
                printf("请输入字符串编号\r\n");
                rewind(stdin);
                scanf("%d",&liv_string_num);
                if(liv_string_num < 1 || liv_string_num > 0x1000 )
                {
                    printf("输入错误，请重试\r\n");
                }
                else if(*((short int *)gcv_Buf + (liv_string_num - 1)) != 0)
                {
                    Search_number(liv_string_num);
                }
                else
                {
                    printf("该编号并未存储字符串。\r\n");
                }
                break;
            case 3:
                printf("请输入查找的字符串内容\r\n");
                rewind(stdin);
                scanf("%255s", lcv_string);
                Search_string(lcv_string);
                break;
            case 4:
                return;
                break;
            default:
                printf("输入错误");
        }
        system("pause");
        system("cls");
    }
    return;
}



void Get_count_menu()
{
    int liv_count_num = 0;
    char lcv_char_const = 0;
    int liv_char_sum = 0;
    for(int i = 0x2000; i < STRMAX;i++)
    {
        if(gcv_Buf[i] != 0)
        {
            liv_char_sum++;
        }
    }
    printf("目前已经存储的字符串中，各字母出现的次数以及比例如下：");
    for(int j = 0; j < 26; j++)
    {
        liv_count_num = Count('A'+j);
        printf("  %c,%c",('A' + j),('A' + j + 0x20));
        printf(" %d, %.2f;",liv_count_num , ((float)liv_count_num) / liv_char_sum);
        if( j % 5 == 0)
        {
            printf("\r\n");
        }
    }
    return;
}


void Get_memory_menu()
{
    char lcv_is_continue = 0;
    char lcv_is_word = 0;
    printf("目前系统内已使用内存情况如下:\r\n");
    for( int i = 0x2000; i < 0x10000; i++)
    {
        if( gcv_Buf[i]!= 0)
        {
            lcv_is_word = 1;
        }
        else if(lcv_is_word == 1 && gcv_Buf[i] == 0)
        {
            lcv_is_word = 2;
        }
        else
        {
            lcv_is_word = 0;
        }
        if(lcv_is_word == 0)
        {
            printf("F");
        }
        else
        {
            printf("U");
        }
        if( i % 0x20 == 0x1f)
        {
            printf("\r\n");
            lcv_is_continue = 0;
            printf("若要继续显示请输入y.\r\n");
            rewind(stdin);
            scanf("%1c", &lcv_is_continue);
            if( lcv_is_continue != 'y')
            {
                break;
            }
        }
    }
    lcv_is_continue = 0;
    printf("若要进行内存碎片整理，请输入y.\r\n");
    rewind(stdin);
    scanf("%1c", &lcv_is_continue);
    if (lcv_is_continue != 'y')
    {
        return;
    }
    else
    {
        Defarg();
    }
    return;
}

void Search_number(short int string_num)
{
    short int liv_string_mark = 0;
    char lcv_string[256] = "";
    liv_string_mark = *((short int *)gcv_Buf + (string_num - 1));
    strcpy(lcv_string,(gcv_Buf + liv_string_mark));
    printf("编号:%d,字符串:%s\r\n", string_num,lcv_string);
    return;
}
void Search_string(const char *srting)
{
    int liv_buf = 0;
    int liv_string_mark = 0;
    for(int i = 0; i < 0x1000; i++)
    {
        liv_string_mark = *((short int *)gcv_Buf + i);
        if(liv_string_mark != 0)
        {
            liv_buf = mystring_cmp(gcv_Buf + liv_string_mark, srting);
            if(liv_buf == 1)
            {
                printf("编号:%d,字符串:%s\r\n",i + 1, (gcv_Buf + liv_string_mark));
            }
        }
    }
    return;
}
void Show_all_string()
{
    int liv_buf = 0;
    int liv_string_mark = 0;
    for (int i = 0; i < 0x1000; i++)
    {
        liv_string_mark = *((short int *)gcv_Buf + i);
        if (liv_string_mark != 0)
        {
            printf("编号:%d,字符串:%s\r\n", i + 1, (gcv_Buf + liv_string_mark));

        }
    }
    return;
}