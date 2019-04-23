#pragma once
#define STRMAX 0x10000
//0x0~0x1fff作为编号管理系统，下标为编号，内容为字符串长度。0x2000~0xffff为数据存放区域
extern char gcv_Buf[STRMAX] ;

//主菜单
void Get_menu();
//添加
void Get_insert_menu();
//删除
void Get_delete_menu();
//修改
void Get_update_menu();
//查找
void Get_find_menu();
//统计
void Get_count_menu();
//内存碎片管理
void Get_memory_menu();
//显示所有已存储的字符串
void Show_all_string();
//按照编号查找对应字符串
void Search_number(short int string_num);
//按照字符内容进行模糊查找
void Search_string(const char *srting);
