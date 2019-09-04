#ifndef _TEXT_H
#define _TEXT_H
#define _CRT_SECURE_NO_WARNINGS 1
#pragma warning(disable:4996)

#include<stdio.h>
#include<Windows.h>
#include<string.h>

#define arrmax 20
#define MAXDATA 32     
//�ṹ���������ַ���


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
void ListInit(List*plist);    //��ʼ��
void ListDestory(List*plist); //����

void ListPushBack(List*plist, SLDataType x);//β��
void ListPopBack(List*plist);//βɾ
void ListPushFront(List*plist, SLDataType x);//ͷ��
void ListPopFront(List*plist);//ͷɾ
SListNode**ListFind(List*plist, char*x);//����x�����������ַ

void ListInsert(SListNode*pos, SLDataType x);  //��pos�������x
void ListErase(SListNode*pos);               //ɾ��posλ�õĽڵ�
void ListRemove(List*plist, SLDataType x);//ɾ��x
void ListPrint(List*plist);

void ListSave(List*plist);
void ListFindContact(List*plist);
void ListDelectContact(List*plist);


#endif