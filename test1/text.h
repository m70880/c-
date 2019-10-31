#ifndef _TEXT_H
#define _TEXT_H
#define _CRT_SECURE_NO_WARNINGS 1
#pragma warning(disable:4996)

#include<stdio.h>
#include<Windows.h>
#include<string.h>

#define arrmax 20
#define MAXDATA 32     
//结构体中最大的字符串


enum ST {
	NAME = 32,
	SEX = 10,
	PHNUM=11,
	ADDRESS=32,
};
typedef struct {
	char name[NAME];
	char sex[SEX];
	int age;
	char phnum[PHNUM];
	char address[ADDRESS];
}Contact;
typedef Contact SLDataType;
typedef struct SListNode {
	SLDataType data;
	struct SListNode *_prev;
	struct SListNode *_next;
}SListNode;
typedef struct List {
	SListNode*_head;
}List;

void Muen();
void Exit(int *p);
SLDataType getifmn();
void ListInit(List*plist);    //初始化
void ListDestory(List*plist); //销毁

void ListPushBack(List*plist, SLDataType x);//尾插
void ListPopBack(List*plist);//尾删
void ListPushFront(List*plist, SLDataType x);//头插
void ListPopFront(List*plist);//头删
SListNode**ListFind(List*plist, char*x);//查找x，并返回其地址

void ListInsert(SListNode*pos, SLDataType x);  //在pos后面插入x
void ListErase(SListNode*pos);               //删除pos位置的节点
void ListRemove(List*plist, SLDataType x);//删除x
void ListPrint(List*plist);

void ListSave(List*plist);
void ListFindContact(List*plist);
void ListDelectContact(List*plist);


#endif