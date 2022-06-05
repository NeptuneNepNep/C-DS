// SqList.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#define MAXSIZE 10
using namespace std;
typedef struct {
	int *data;
	int length;
	int maxSize;


}sqList;
bool InitList(sqList &l) {
	
	l.data = (int*)malloc(sizeof(int)*MAXSIZE);
	l.maxSize = MAXSIZE;
	for (int i = 0; i < MAXSIZE; i++) {
		l.data[i] = 3;

	}
	l.length = MAXSIZE;
	return true;
}
bool ListInsert(sqList &l, int i, int e) {
	if (i<1 || i>l.length + 1) {
		return false;
	}
	for (int j = l.length; j >= i; j--) {
		l.data[j] = l.data[j - 1];
	
	}
	l.data[i-1] = e;
	return true;
}
bool ListDelete(sqList &l, int i, int &e) {
	if (i<1 || i>l.length + 1) {
		return false;
	}
	e = l.data[i-1];
	for (int j = i; j < l.length; j++) {
		l.data[j-1] = l.data[j];

	}

	
	l.length--;
	return true;

}
int GetItem(sqList l, int i) {
	if (i<1 || i>l.length + 1) {
		return -1;
	}
	return l.data[i-1];
}
int Locate(sqList l, int e) {

	for (int i = 0; i < l.length; i++) {
		if (l.data[i] == e) {
			return i + 1;
		}
	
	}
	return -1;
}
int main() {
	sqList l;
	InitList(l);
	ListInsert(l, 2, 2);
	int e;
	ListDelete(l, 1, e);
	int p = Locate(l, 2);
	cout << e <<" " <<p<< endl;
	for (int i = 0; i < MAXSIZE; i++) {
		cout << l.data[i] << endl;
	
	}


}