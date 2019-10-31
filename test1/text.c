#include"text.h"

SListNode*arfinddumenglin[arrmax] = { 0 };


void Muen() {
	printf("#########################################\n");
	printf("##### 1.初始化      2.添加联系人    #####\n");
	printf("##### 3.查找联系人  4.删除联系人    #####\n");
	printf("##### 5.查看联系人  6.更新文件联系人#####\n");
	printf("##### 7.退出程序                    #####\n");
	printf("#########################################\n");
	printf("请输入你的选择：\n");
}
void ListSave(List*plist) {

	FILE*fp = fopen("text.txt", "wb");

	if (fp == NULL) {
		printf("存储失败\n");
		return;
	}
	
	SListNode*cur = plist->_head->_next;     //从第一个数据开始写入

	for (;cur!= plist->_head;cur = cur->_next) {
		fwrite(&(cur->data), sizeof(SLDataType), 1, fp);
		/*fwrite(cur->data.sex, SEX, 1, fp);
		fwrite(&cur->data.age, 4, 1, fp);
		fwrite(cur->data.phnum, PHNUM, 1, fp);
		fwrite(cur->data.address, ADDRESS, 1, fp);*/
	}
	fclose(fp);
}
void ListInit(List*plist)   //初始化
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
	while (fread(&tmp, sizeof(SLDataType),1, fp) >= 1) {  //----------  注意  ----------------------
		ListPushBack(plist, tmp);
	}
	
	fclose(fp);
	//free(fp);
}
void ListDestory(List*plist)//销毁
{
	////方式1
	while (plist->_head != plist->_head->_next)
	{
		ListPopFront(plist);
	}
	free(plist->_head);
	plist->_head = NULL;

	//方式2
	//SListNode*cur = plist->_head->_next;
	//SListNode*tmp;
	//for (;cur!= plist->_head;cur = cur->_next) {
	//	ListErase(cur);
	//	cur = plist->_head;        //cur已经被销毁，但是cur仍然指向该区域，所以给cur重新赋值
	//}
	//free(plist->_head);
	//plist->_head = NULL;
}

void ListPushBack(List*plist, SLDataType x)//尾插
{
	SListNode*cur = (SListNode*)malloc(sizeof(SListNode));
	cur->data = x;

	cur->_next = plist->_head;
	cur->_prev = plist->_head->_prev;
	plist->_head->_prev->_next = cur;
	plist->_head->_prev = cur;

}

void ListPopBack(List*plist)//尾删
{
	SListNode*cur = plist->_head->_prev;
	plist->_head->_prev = cur->_prev;
	cur->_prev->_next = plist->_head;
	free(cur);


}
void ListPushFront(List*plist, SLDataType x)        //头插
{
	SListNode*cur = (SListNode*)malloc(sizeof(SListNode));
	cur->data = x;

	cur->_next = plist->_head->_next;  //新节点先和头握手
	cur->_prev = plist->_head;         //新节点和第一个元素握手

	plist->_head->_next = cur;         //头向新节点握手
	cur->_next->_prev = cur;           //原来的1号节点和新节点握手

}
void ListPopFront(List*plist)//头删
{
	ListErase(plist->_head->_next);
	//SListNode*cur;
	//cur = plist->_head->_next;
	//plist->_head->_next = plist->_head->_next->_next;//head和2号握手
	//plist->_head->_next->_prev = plist->_head;       //2号和head握手
	//free(cur);                                        //删除原配1号

}

void ListInsert(SListNode*pos, SLDataType x)  //在pos后面插入x
{
	SListNode*cur = (SListNode*)malloc(sizeof(SListNode));
	cur->data = x;

	cur->_next = pos->_next;
	cur->_prev = pos;
	pos->_next = cur;
	cur->_next->_prev = cur;
}
void ListErase(SListNode*pos)              //删除pos位置的节点
{
	pos->_prev->_next = pos->_next;
	pos->_next->_prev = pos->_prev;
	free(pos);

}
void ListRemove(List*plist, SLDataType x)//删除x
{

	SListNode*cur = plist->_head->_next;
	SListNode*tmp;
	for (;cur != plist->_head;cur = cur->_next) {
		tmp = cur->_prev;
		//if (cur->data == x) {
		//	ListErase(cur);
		//	cur = tmp->_next->_prev; //cur已经被销毁，但是cur仍然指向该区域，所以给cur重新赋值
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
//输入一个数据，并将其返回
SLDataType getifmn() {
	SLDataType st;
	printf("请输入姓名:");
	scanf("%s[^\n]", st.name);

	printf("请输入性别:");
	scanf("%s[^\n]", st.sex);
	getchar();

	printf("请输入年龄:");
	scanf("%d", &st.age);
	getchar();

	printf("请输入电话号码:");
	scanf("%s[^\n]", st.phnum);

	printf("请输入居住地址:");
	scanf("%s[^\n]", st.address);
	getchar();
	return st;
}
//模糊查找
void ListFindContact(List*plist) {
	memset(arfinddumenglin, 0, sizeof(SListNode*));
	printf("请输入需要查找的目标\n");
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
//将有关条目存储在数组
SListNode**ListFind(List*plist, char*x)//查找x，并返回其地址
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
//删除
void ListDelectContact(List*plist) {
	ListFindContact(plist);
	int x;
	printf("请输入要删除的条目序号：\n");
	scanf("%d", &x);
	ListErase(arfinddumenglin[x - 1]);
}
