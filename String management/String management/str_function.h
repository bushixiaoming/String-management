#pragma once
int Find_free(const char *string1);
//��ch1�����ַ���ch2
void Insert(char ch1[], const char *ch2);
//ɾ��ch1������Ԫ�أ���ch1[n]��ʼֱ����־λ��\0��
void Delete(int string_mark);
//��ch1������Ƭ����
void Defarg();
//�޸�ָ����ŵ��ַ���
void Update(int string_num, const char *update_string);
//ͳ�Ƴ��ֵ���ĸ����
int Count(char char_const);
//����string1���ͷŴ��ڷ���string2���ַ���
int mystring_cmp(const char *string1,const char *string2);
