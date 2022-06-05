// LinkList.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;
typedef struct Node {
	int data;
	struct Node* next;


}Node,*LinkList;
void CreateNode(Node *&node,int data) {
	node = (Node*)malloc(sizeof(Node));
	node->data = data;
	node->next = NULL;
}
bool InitList(LinkList &list) {
	list = (Node*)malloc(sizeof(Node));
	list->data = 0;
	list->next = NULL;
	return true;
}
bool ListInsert(LinkList &list, int i, int e) {
	LinkList p = list;
	for (int j = 0; j < i; j++) {
		if (p->next == NULL) { break; }
		else {
			p = p->next;

		}
	}
	Node *newNode = (Node*)malloc(sizeof(Node));
	CreateNode(newNode,e);
	newNode->next = p->next;
	p->next = newNode;
	return true;


}
bool DeleteNode(LinkList &list, int i, int &e) {
	LinkList p = list;
	for (int j = 0; j < i; j++) {
		if (p->next == NULL) { return false; }
		else {
			p = p->next;

		}
	}
	if (p->next->next == NULL) { return false; }
	p->data = p->next->data;
	Node *q = p->next;
	p->next = p->next->next;
	free(q);

	return true;
}
bool InsertByHead(LinkList l , int e) {
	Node *newNode;
	CreateNode(newNode,e);
	newNode->next = l->next;
	l->next = newNode;
	return true;

}
bool InsertByTail(LinkList l, int e) {
	LinkList p = l;
	Node *newNode;
	CreateNode(newNode, e);
	//找到最后一个结点
	while (p->next!=NULL)
	{
		p = p->next;
	}
	newNode->next = p->next;
	p->next = newNode;
	return true;
}
void ShowLinklist(LinkList l) {
	LinkList p = l;
	while (p!=NULL)
	{
		cout << p->data << endl;
		p = p->next;
	}

}
int main()
{
	LinkList l1;
	InitList(l1);
	ListInsert(l1, 0, 1);
	ListInsert(l1,1, 2);
	ListInsert(l1, 1, 3);
	InsertByTail(l1, 5);
	InsertByHead(l1, 7);
	ShowLinklist(l1);
	int i;
	DeleteNode(l1, 1, i);

	ShowLinklist(l1);
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
