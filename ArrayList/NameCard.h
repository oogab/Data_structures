#pragma once
#define NAME_LEN	30
#define PHONE_LEN	30

typedef struct _nameCard {
	char name[NAME_LEN];
	char phone[PHONE_LEN];
} NameCard;

// NameCard ����ü ������ ���� �Ҵ� �� �ʱ�ȭ �� �ּ� �� ��ȯ
NameCard* MakeNameCard(char* name, char* phone);

// NameCard ����ü ������ ���� ���
void ShowNameCardInfo(NameCard* pcard);

// �̸��� ������ 0, �ٸ��� 0�� �ƴ� �� ��ȯ
int NameCompare(NameCard* pcard, char* phone);

// ��ȭ��ȣ ������ ����
void ChangePhoneNumber(NameCard* pcard, char* phone);