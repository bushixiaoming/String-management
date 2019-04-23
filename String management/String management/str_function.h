#pragma once
int Find_free(const char *string1);
//向ch1插入字符串ch2
void Insert(char ch1[], const char *ch2);
//删除ch1数组中元素，从ch1[n]开始直到标志位‘\0’
void Delete(int string_mark);
//对ch1进行碎片整理
void Defarg();
//修改指定编号的字符串
void Update(int string_num, const char *update_string);
//统计出现的字母数量
int Count(char char_const);
//检索string1中释放存在符合string2的字符串
int mystring_cmp(const char *string1,const char *string2);
