#include"text.h"

int main() {
	Heap hp;
	HPDataType arr[] = { 6,4,5,6,7,8,9,6,3,5,7 };
	HeapInit(&hp,arr,sizeof(arr)/sizeof(arr[0]));

	HeapPush(&hp,100);
	HeapPop(&hp);
	HeapSort(&hp);
	int flag = 0;
	int sum = 1;
	for (int i = 0;i < hp.size;i++) {
		printf("%d ", hp.data[i]);
		if (i == flag) {
			printf("\n");
			sum *= 2;
			flag+=sum;
		}
	}
	system("pause");
	return 0;
}