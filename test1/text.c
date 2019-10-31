#include"text.h"

SListNode*arfinddumenglin[arrmax] = { 0 };


void Muen() {
	printf("#########################################\n");
	printf("##### 1.��ʼ��      2.�����ϵ��    #####\n");
	printf("##### 3.������ϵ��  4.ɾ����ϵ��    #####\n");
	printf("##### 5.�鿴��ϵ��  6.�����ļ���ϵ��#####\n");
	printf("##### 7.�˳�����                    #####\n");
	printf("#########################################\n");
	printf("���������ѡ��\n");
}
void ListSave(List*plist) {

	FILE*fp = fopen("text.txt", "wb");

	if (fp == NULL) {
		printf("�洢ʧ��\n");
		return;
	}
	
	SListNode*cur = plist->_head->_next;     //�ӵ�һ�����ݿ�ʼд��

	for (;cur!= plist->_head;cur = cur->_next) {
		fwrite(&(cur->data), sizeof(SLDataType), 1, fp);
		/*fwrite(cur->data.sex, SEX, 1, fp);
		fwrite(&cur->data.age, 4, 1, fp);
		fwrite(cur->data.phnum, PHNUM, 1, fp);
		fwrite(cur->data.address, ADDRESS, 1, fp);*/
	}
	fclose(fp);
}
void ListInit(List*plist)   //��ʼ��
{
	//if (plist->_head||&plist->_head->_next == plist->_head) {
	//	return;
	//}
	plist->_head = (SListNode*)malloc(sizeof(SListNode));
	plist->_head->_next = plist->_head;
	plist->_head->_prev = plist->_head;

	SLDataType tmp;
	FILE*fp = fopen("text.txt", "rb");
	if (fp == NULL) {
		return;
	}
	while (fread(&tmp, sizeof(SLDataType),1, fp) >= 1) {  //----------  ע��  ----------------------
		ListPushBack(plist, tmp);
	}
	
	fclose(fp);
	//free(fp);
}
void ListDestory(List*plist)//����
{
	////��ʽ1
	while (plist->_head != plist->_head->_next)
	{
		ListPopFront(plist);
	}
	free(plist->_head);
	plist->_head = NULL;

	//��ʽ2
	//SListNode*cur = plist->_head->_next;
	//SListNode*tmp;
	//for (;cur!= plist->_head;cur = cur->_next) {
	//	ListErase(cur);
	//	cur = plist->_head;        //cur�Ѿ������٣�����cur��Ȼָ����������Ը�cur���¸�ֵ
	//}
	//free(plist->_head);
	//plist->_head = NULL;
}

void ListPushBack(List*plist, SLDataType x)//β��
{
	SListNode*cur = (SListNode*)malloc(sizeof(SListNode));
	cur->data = x;

	cur->_next = plist->_head;
	cur->_prev = plist->_head->_prev;
	plist->_head->_prev->_next = cur;
	plist->_head->_prev = cur;

}

void ListPopBack(List*plist)//βɾ
{
	SListNode*cur = plist->_head->_prev;
	plist->_head->_prev = cur->_prev;
	cur->_prev->_next = plist->_head;
	free(cur);


}
void ListPushFront(List*plist, SLDataType x)        //ͷ��
{
	SListNode*cur = (SListNode*)malloc(sizeof(SListNode));
	cur->data = x;

	cur->_next = plist->_head->_next;  //�½ڵ��Ⱥ�ͷ����
	cur->_prev = plist->_head;         //�½ڵ�͵�һ��Ԫ������

	plist->_head->_next = cur;         //ͷ���½ڵ�����
	cur->_next->_prev = cur;           //ԭ����1�Žڵ���½ڵ�����

}
void ListPopFront(List*plist)//ͷɾ
{
	ListErase(plist->_head->_next);
	//SListNode*cur;
	//cur = plist->_head->_next;
	//plist->_head->_next = plist->_head->_next->_next;//head��2������
	//plist->_head->_next->_prev = plist->_head;       //2�ź�head����
	//free(cur);                                        //ɾ��ԭ��1��

}

void ListInsert(SListNode*pos, SLDataType x)  //��pos�������x
{
	SListNode*cur = (SListNode*)malloc(sizeof(SListNode));
	cur->data = x;

	cur->_next = pos->_next;
	cur->_prev = pos;
	pos->_next = cur;
	cur->_next->_prev = cur;
}
void ListErase(SListNode*pos)              //ɾ��posλ�õĽڵ�
{
	pos->_prev->_next = pos->_next;
	pos->_next->_prev = pos->_prev;
	free(pos);

}
void ListRemove(List*plist, SLDataType x)//ɾ��x
{

	SListNode*cur = plist->_head->_next;
	SListNode*tmp;
	for (;cur != plist->_head;cur = cur->_next) {
		tmp = cur->_prev;
		//if (cur->data == x) {
		//	ListErase(cur);
		//	cur = tmp->_next->_prev; //cur�Ѿ������٣�����cur��Ȼָ����������Ը�cur���¸�ֵ
		//}
	}
}
void ListPrint(List*plist) {
	SListNode*cur = plist->_head->_next;
	for (;cur != plist->_head;cur = cur->_next) {

		printf("%-6s %5s %-3d %-11s %-s\n", 
			cur->data.name,
			cur->data.sex,
			cur->data.age,
			cur->data.phnum,
			cur->data.address);
	}
}
void Exit(int*p) {
	*p = 0;
}
//����һ�����ݣ������䷵��
SLDataType getifmn() {
	SLDataType st;
	printf("����������:");
	scanf("%s[^\n]", st.name);

	printf("�������Ա�:");
	scanf("%s[^\n]", st.sex);
	getchar();

	printf("����������:");
	scanf("%d", &st.age);
	getchar();

	printf("������绰����:");
	scanf("%s[^\n]", st.phnum);

	printf("�������ס��ַ:");
	scanf("%s[^\n]", st.address);
	getchar();
	return st;
}
//ģ������
void ListFindContact(List*plist) {
	memset(arfinddumenglin, 0, sizeof(SListNode*));
	printf("��������Ҫ���ҵ�Ŀ��\n");
	char arr[MAXDATA];
	scanf("%s", arr);
	getchar();
	SListNode**arrfind = ListFind(plist, arr);
	for (int i = 0;arrfind[i];i++) {
		printf("%-6s %5s %-3d %-11s %-s\n",
			arrfind[i]->data.name,
			arrfind[i]->data.sex,
			arrfind[i]->data.age,
			arrfind[i]->data.phnum,
			arrfind[i]->data.address);
	}
}
//���й���Ŀ�洢������
SListNode**ListFind(List*plist, char*x)//����x�����������ַ
{
	memset(arfinddumenglin, 0, sizeof(arfinddumenglin));
	SListNode*cur = plist->_head->_next;
	char age[5];
	int i = 0;
	for (;cur != plist->_head;cur = cur->_next) {
		sprintf(age, "%d", cur->data.age);
		if (strstr(cur->data.name, x)) {
			arfinddumenglin[i] = cur;
			i++;
		}
		else if (strstr(cur->data.sex, x)) {
			arfinddumenglin[i] = cur;
			i++;
		}
		else if (strstr(age,x)) {
			arfinddumenglin[i] = cur;
			i++;
		}
		else if (strstr(cur->data.phnum, x)) {
			arfinddumenglin[i] = cur;
			i++;
		}
		else if (strstr(cur->data.address, x)) {
			arfinddumenglin[i] = cur;
			i++;
		}
	}
	if (arfinddumenglin[0]->_next != NULL)
		return arfinddumenglin;
	else {
		return NULL;
	}
	/*SListNode*cur = plist->_head->_next;
	for (;cur != plist->_head;cur = cur->_next) {
		if (strcmp(cur->data.name, x.name) == 0) {
			return cur;
		}
	}*/
	//for (;cur != plist->_head;cur = cur->_next) {
	//	if (cur->data.name == x) {
	//		return cur;
	//	}
	//}

}
//ɾ��
void ListDelectContact(List*plist) {
	ListFindContact(plist);
	int x;
	printf("������Ҫɾ������Ŀ��ţ�\n");
	scanf("%d", &x);
	ListErase(arfinddumenglin[x - 1]);
}
