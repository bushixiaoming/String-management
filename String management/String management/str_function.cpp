#include "pch.h"
#include <stdio.h>
#include <string.h>
#include "UI.h"
#include "str_function.h"

char gcv_Buf[STRMAX] = "";
int Find_free(const char *string1)
{
    int liv_string_len = 0;
    int liv_buf = 0;
    int liv_isfree = 0;
    liv_string_len = strlen(string1);
    int liv_string_number = 0x2000;
    for( ; liv_buf <= liv_string_len && 
        liv_string_number <= STRMAX - 1; liv_string_number++)
    {
        if(liv_isfree == 1 && gcv_Buf[liv_string_number] == 0)
        {
            liv_isfree = 0;
        }
        else if(liv_isfree == 0 && gcv_Buf[liv_string_number] == 0)
        {
            liv_buf++;
        }
        else
        {
            liv_isfree = 1;
            liv_buf = 0;
        }
    }
    if(liv_string_number >= 0xffff )
    {
        return 0;
    }
    else
    {
        return (liv_string_number - liv_buf);
    }
}

//��ch1�����ַ���ch2
void Insert(char *ch1, const char *ch2)
{
    strcpy(ch1,ch2);
    return;
}
//ɾ��ch1������Ԫ�أ���ch1[n]��ʼֱ����־λ��\0��
void Delete(int string_mark)
{
    for ( int i = 0; gcv_Buf[string_mark + i] != '\0'; i++)
    {
        gcv_Buf[string_mark + i] = 0;
    }    
    return;
}
//�޸�ָ������ַ���
void Update(int string_num,const char *update_string)
{
    int liv_string_len = 0;
    int liv_buf = 0;
    int liv_string_mark = *((short int *)gcv_Buf + (string_num - 1));
    liv_string_len = strlen(update_string);
    for (; gcv_Buf[liv_string_mark + liv_buf] == 0 && liv_buf <= 255; liv_buf++)
    {
        ;
    }
    if(liv_buf < liv_string_len + 1)
    {
        liv_string_mark = Find_free(update_string);
        if(liv_string_mark == 0)
        {
            printf("�ڴ�ռ䲻��!\r\n");
            printf("������ڴ��������ɾ�������ַ���!\r\n");
        }
        else
        {
            printf("ԭ�ַ�����ַ���пռ䲻�㣬�Ѹ�����ַ�洢��\r\n");
            *((short int *)gcv_Buf + (string_num - 1)) = liv_string_mark;
            Insert(gcv_Buf + liv_string_mark, update_string);
        }
    }
    else
    {
        Insert(gcv_Buf + liv_string_mark, update_string);
    }
}
//ͳ�Ƴ��ֵ���ĸ����
int Count(char char_count)
{
    int liv_count_num = 0;
    for (int i = 0x2000; i < STRMAX; i++)
    {
        if(gcv_Buf[i] == char_count || gcv_Buf[i] == char_count + 0x20)
        {
            liv_count_num++;
        }
    }
    return liv_count_num;
}
//��string1�н���ģ������������Ϊstring2
int mystring_cmp(const char *string1, const char *string2)
{
    int liv_string1_len = 0;
    int liv_string2_len = 0;
    int liv_is_string = 0;
    liv_string1_len = strlen(string1);
    liv_string2_len = strlen(string2);
    if(liv_string1_len < liv_string2_len)
    {
        return 0;
    }
    for(int i = 0; i <= liv_string1_len - liv_string2_len || liv_is_string != 0; i++)
    {
        if(string1[i] == string2[liv_is_string])
        {
            liv_is_string++;
            if(liv_is_string >= liv_string2_len)
            {
                break;
            }
        }
        else
        {
            liv_is_string = 0;
        }
    }
    if(liv_is_string >= liv_string2_len)
    {
        return 1;
    }
    return 0;
}
//��Ƭ����
void Defarg()
{
    int liv_isfree = 1;
    int liv_string_mark = 0;
    int liv_free_memory = 0;
    for( int i = 0x2000; i < 0x10000; i++)
    {
        if(gcv_Buf[i] == 0 && liv_isfree == 0)      
        {
            i = i - liv_free_memory;
            gcv_Buf[i] = 0;
            liv_isfree = 1;
            liv_free_memory = 0;
        }
        else if(gcv_Buf[i] == 0 && liv_isfree == 1)
        {
            liv_free_memory++;
        }
        else if (liv_isfree == 1 && liv_free_memory == 0)
        {
            liv_isfree = 0;
        }
        else if(liv_isfree == 1 && liv_free_memory > 0)
        {
            liv_isfree = 0;
            liv_string_mark = i - liv_free_memory;
            for( int j = 0; j < 0x1000; j++)
            {
                if(*((short int *)gcv_Buf +j) == i)
                {
                    *((short int *)gcv_Buf + j) = liv_string_mark;
                    break;
                }
            }
            gcv_Buf[i - liv_free_memory] = gcv_Buf[i];
            gcv_Buf[i] = 0;
        }
        else if (liv_isfree == 0 && liv_free_memory > 0)
        {
            gcv_Buf[i - liv_free_memory] = gcv_Buf[i];
            gcv_Buf[i] = 0;
        }
    }
    return;
    
}
