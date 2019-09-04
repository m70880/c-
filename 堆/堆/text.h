#ifndef _TEXT_H_
#define _TEXT_H_

#include<stdio.h>
#include<Windows.h>

#define MAXSIZE 100

typedef int HPDataType;
typedef struct Heap {
	HPDataType* data;
	int size;
	int capacity;
}Heap;

void HeapInit(Heap* ph,HPDataType* a,int n);  //ok
void HeapDestory(Heap* ph);                   //ok
void HeapPush(Heap*ph, HPDataType x);         //ok
void HeapPop(Heap*ph);                        //ok
HPDataType HeapTop(Heap* ph);                 //return top
void HeapSort(Heap* ph);                      //����
void TestHeap();
void DownAdjust(Heap*ph, int n);              //���µ���

#endif // !_TEXT_H_
