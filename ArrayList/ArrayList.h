#pragma once
#include "Point.h"
#include "NameCard.h"
#define TRUE		1
#define FALSE		0
#define LIST_LEN	100

//typedef Point* LData;
typedef NameCard* LData;

typedef struct _arrayList {	// �迭��� ����Ʈ�� ������ ����ü
	LData arr[LIST_LEN];	// ����Ʈ�� ������� �迭
	int numOfData;			// ����� �������� ��
	int curPosition;		// ������ ������ġ ���
} ArrayList;

typedef ArrayList List;

void ListInit(List* plist);				// �ʱ�ȭ
void LInsert(List* plist, LData data);  // ������ ����

int LFirst(List* plist, LData* pdata);  // ù ������ ����
int LNext(List* plist, LData* pdata);   // �� ��° ���� ������ ����

LData LRemove(List* plist);				// ������ ������ ����
int LCount(List* plist);				// ����� �������� �� ��ȯ