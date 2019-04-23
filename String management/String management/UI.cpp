#include "pch.h"
#include <stdio.h>
#include "UI.h"
#include "str_function.h"
#include <stdlib.h>
#include <string.h>

void Get_menu()
{
    printf("��ӭ�����ַ�����̬����ϵͳ\r\n");
    printf("�밴�����蹦��������Ӧ���\r\n");
    printf("1.���\r\n");
    printf("2.ɾ��\r\n");
    printf("3.�޸�\r\n");
    printf("4.����\r\n");
    printf("5.ͳ��\r\n");
    printf("6.�ڴ����\r\n");
    printf("7.�˳�\r\n");
    return;
}


void Get_insert_menu()
{
    int liv_string_mark = 0;
    char lucv_buf[256] = "";
    int liv_string_num = 0;
    int liv_isfree = 0;
    printf("������:\r\n");
    rewind(stdin);
    scanf("%255s", lucv_buf);
    liv_string_mark = Find_free(lucv_buf);
    if ( liv_string_mark == 0)
    {
        printf("�ڴ�ռ䲻��!\r\n");
        printf("������ڴ��������ɾ�������ַ���!\r\n");
        return;
    }
    else
    {
        for (; liv_string_num < 0x1000; liv_string_num++)            //���ҿ��б�ţ���д�롣
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
            printf("����Ѿ�ȫ��ʹ�ã�������ռ�\r\n");
        }
        else
        {
            printf("���ַ������Ϊ%d\r\n", (liv_string_num + 1));
            Insert(gcv_Buf + liv_string_mark, lucv_buf);
            printf("��ӳɹ�");
        }
    }
    return;
}


void Get_delete_menu()
{
    int liv_string_num = 0;
    printf("��������Ҫɾ�����ַ����ı��\r\n");
    rewind(stdin);
    scanf("%d", &liv_string_num);
    if(liv_string_num > 0x1000 || liv_string_num < 1)
    {
        printf("�������\r\n");
    }
    else if(*((short int *)gcv_Buf + (liv_string_num - 1)) != 0)
    {
        Delete(*((short int *)gcv_Buf + (liv_string_num - 1)));
        *((short int *)gcv_Buf + (liv_string_num - 1)) = 0;
        printf("ɾ���ɹ�");
    }
    else
    {
        printf("�ñ�Ų�δ�洢�ַ�����\r\n");
    }
    return;
}


void Get_update_menu()
{
    char lcv_string[256] = "";
    int liv_string_num = 0;
    printf ("��������Ҫ�޸ĵ��ַ������:\r\n");
    rewind (stdin);
    scanf("%d", &liv_string_num);
    if (liv_string_num < 1 || liv_string_num > 0x1000)
    {
        printf("�������\r\n");
    }
    else if (*((short int *)gcv_Buf + (liv_string_num - 1)) != 0)
    {
        Delete(*((short int *)gcv_Buf + (liv_string_num - 1)));
        printf("�������޸ĺ���ַ�������:\r\n");
        rewind(stdin);
        scanf("%255s",lcv_string);
        Update(liv_string_num,lcv_string);
    }
    else
    {
        printf("�ñ�Ų�δ�洢�ַ�����\r\n");
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
        printf ("���������Ҫ�Ĳ��ҷ�ʽ,�����Ӧ��ţ�\r\n");
        printf ("1.�鿴ȫ���ַ���\r\n");
        printf ("2.���ձ�Ž��в���\r\n");
        printf ("3.�����ַ������ݽ��в���\r\n");
        printf ("4.�˳�\r\n");
        rewind(stdin);
        scanf ("%d",&liv_find_type);
        switch(liv_find_type)
        {
            case 1:
                Show_all_string();
                break;
            case 2:
                printf("�������ַ������\r\n");
                rewind(stdin);
                scanf("%d",&liv_string_num);
                if(liv_string_num < 1 || liv_string_num > 0x1000 )
                {
                    printf("�������������\r\n");
                }
                else if(*((short int *)gcv_Buf + (liv_string_num - 1)) != 0)
                {
                    Search_number(liv_string_num);
                }
                else
                {
                    printf("�ñ�Ų�δ�洢�ַ�����\r\n");
                }
                break;
            case 3:
                printf("��������ҵ��ַ�������\r\n");
                rewind(stdin);
                scanf("%255s", lcv_string);
                Search_string(lcv_string);
                break;
            case 4:
                return;
                break;
            default:
                printf("�������");
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
    printf("Ŀǰ�Ѿ��洢���ַ����У�����ĸ���ֵĴ����Լ��������£�");
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
    printf("Ŀǰϵͳ����ʹ���ڴ��������:\r\n");
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
            printf("��Ҫ������ʾ������y.\r\n");
            rewind(stdin);
            scanf("%1c", &lcv_is_continue);
            if( lcv_is_continue != 'y')
            {
                break;
            }
        }
    }
    lcv_is_continue = 0;
    printf("��Ҫ�����ڴ���Ƭ����������y.\r\n");
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
    printf("���:%d,�ַ���:%s\r\n", string_num,lcv_string);
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
                printf("���:%d,�ַ���:%s\r\n",i + 1, (gcv_Buf + liv_string_mark));
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
            printf("���:%d,�ַ���:%s\r\n", i + 1, (gcv_Buf + liv_string_mark));

        }
    }
    return;
}