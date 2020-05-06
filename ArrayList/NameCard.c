#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "NameCard.h"

// NameCard ����ü ������ ���� �Ҵ� �� �ʱ�ȭ �� �ּ� �� ��ȯ
NameCard* MakeNameCard(char* name, char* phone) {
	NameCard* ncard = (NameCard*)malloc(sizeof(NameCard));
	strcpy(ncard->name, name);
	strcpy(ncard->phone, phone);
	return ncard;
}

// NameCard ����ü ������ ���� ���
void ShowNameCardInfo(NameCard* pcard) {
	printf("��    ��: %s \n", pcard->name);
	printf("��ȭ��ȣ: %s \n\n", pcard->phone);
}

// �̸��� ������ 0, �ٸ��� 0�� �ƴ� �� ��ȯ
int NameCompare(NameCard* pcard, char* name) {
	return strcmp(pcard->name, name);
}

// ��ȭ��ȣ ������ ����
void ChangePhoneNumber(NameCard* pcard, char* phone) {
	strcpy(pcard->phone, phone);
}