#pragma once
#define STRMAX 0x10000
//0x0~0x1fff��Ϊ��Ź���ϵͳ���±�Ϊ��ţ�����Ϊ�ַ������ȡ�0x2000~0xffffΪ���ݴ������
extern char gcv_Buf[STRMAX] ;

//���˵�
void Get_menu();
//���
void Get_insert_menu();
//ɾ��
void Get_delete_menu();
//�޸�
void Get_update_menu();
//����
void Get_find_menu();
//ͳ��
void Get_count_menu();
//�ڴ���Ƭ����
void Get_memory_menu();
//��ʾ�����Ѵ洢���ַ���
void Show_all_string();
//���ձ�Ų��Ҷ�Ӧ�ַ���
void Search_number(short int string_num);
//�����ַ����ݽ���ģ������
void Search_string(const char *srting);
