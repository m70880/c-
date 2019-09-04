#include"text.h"
void swap(HPDataType*a, HPDataType*b) {
	HPDataType tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}
void HeapInit(Heap* ph, HPDataType* a, int n) {
	ph->data = (HPDataType*)malloc(sizeof(HPDataType)*MAXSIZE);
	ph->capacity = MAXSIZE;

	memcpy(ph->data, a, sizeof(HPDataType) * n);
	ph->size = n;

	for (int i = n / 2 - 1;i>=0; i--) {   //从最后一个非叶子节点开始排序
		DownAdjust(ph, i);
	}


}

void DownAdjust(Heap*ph,int n) {   //n为调整的节点
	int cur = n;
	while (cur * 2 + 1 < ph->size) {              //
		if (ph->data[cur] < ph->data[cur * 2 + 1]) {
			if (ph->data[cur*2+2]>=ph->size||ph->data[cur * 2 + 1] > ph->data[cur * 2 + 2]) {
				swap(&ph->data[cur], &ph->data[cur * 2 + 1]);
				cur = cur * 2 + 1;
			}
			else {
				swap(&ph->data[cur], &ph->data[cur * 2 + 2]);
				cur = cur * 2 + 2;
			}
		}
		else if (ph->data[cur] < ph->data[cur * 2 + 2]) {
			swap(&ph->data[cur], &ph->data[cur * 2 + 2]);
			cur = cur * 2 + 2;
		}
		else {
			break;
		}
	}
}

void HeapPush(Heap*ph, HPDataType x) {
	ph->data[ph->size] = x;
	ph->size++;
	HPDataType*cur = ph->data;
	int tmp = ph->size-1;
	while (ph->data[tmp] > ph->data[(tmp-1)/2]) {

		swap(&ph->data[tmp], &ph->data[(tmp - 1) / 2]);
		tmp = (tmp - 1) / 2;

	}
}

void HeapPop(Heap*ph) {
	if (ph->size <= 0) {
		return;
	}
	swap(ph->data, ph->data + ph->size - 1);
	ph->size--;
	DownAdjust(ph, 0);
}
void HeapDestory(Heap* ph) {
	free(ph->data);
	ph->size = 0;
	ph->capacity = 0;
}
void HeapSort(Heap* ph) {

	int tmp = ph->size;

	while (ph->size >= 1) {
		HeapPop(ph);

		//int flag = 0;
		//int sum = 1;
		//for (int i = 0;i < ph->size;i++) {
		//	printf("%d ", ph->data[i]);

		//	if (i == flag) {
		//		printf("\n");
		//		sum *= 2;
		//		flag += sum;
		//	}
		//}
		//printf("\n");
		//printf("\n");
		//printf("\n");
		//printf("\n");
	}
	ph->size = tmp;
}

