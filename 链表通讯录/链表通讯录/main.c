#include"text.h"
int main() {
	//printf("#########################################\n");
	//printf("##### 1.��ʼ��      2.�����ϵ��    #####\n");
	//printf("##### 3.������ϵ��  4.ɾ����ϵ��    #####\n");
	//printf("##### 5.�鿴��ϵ��  6.������ϵ��    #####\n");
	//printf("##### 7.�˳�����                    #####\n");
	//printf("#########################################\n");
	//printf("sizeof:%d\nsizeof:%d", sizeof(SLDataType), sizeof(Contact));
	List plist;
	ListInit(&plist);
	int flag = 1;
	int select;
	while (flag) {
		Muen();
		scanf("%d", &select);
		switch (select) {
		case 1:
			ListInit(&plist);
			break;
		case 2:
			ListPushBack(&plist, getifmn());
			break;
		case 3:
			ListFindContact(&plist);
		//	ListFind(&plist,)
			break;
		case 4:
			ListDelectContact(&plist);
			break;
		case 5:
			ListPrint(&plist);
			break;
		case 6:
			ListSave(&plist);
			break;
		case 7:
			Exit(&flag);
			break;
		}

	}

	//ListPushBack(&plist, getifmn());
	//ListPrint(&plist);

	system("pause");
	return 0;
}