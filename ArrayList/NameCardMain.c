#include <stdio.h>
#include <stdlib.h>
#include "NameCard.h"
#include "ArrayList.h"

int main(void) {
	List list;
	NameCard* pcard;

	ListInit(&list);

	// 3���� NameCard ���� ���� �� ���� ///////
	pcard = MakeNameCard("����", "010-3221-0000");
	LInsert(&list, pcard);

	pcard = MakeNameCard("��μ�", "010-8844-2222");
	LInsert(&list, pcard);

	pcard = MakeNameCard("�̼���", "010-4535-1111");
	LInsert(&list, pcard);

	// ��μ� ���� ���
	if (LFirst(&list, &pcard)) {
		if (!NameCompare(pcard,"��μ�"))
			ShowNameCardInfo(pcard);
		else {
			while (LNext(&list, &pcard)) {
				if (!NameCompare(pcard, "��μ�")) {
					ShowNameCardInfo(pcard);
					break;
				}
			}
		}
	}

	// �̼��� ��ȭ��ȣ ���� ����
	if (LFirst(&list, &pcard)) {
		if (!NameCompare(pcard, "�̼���"))
			ChangePhoneNumber(pcard, "010-3842-1212");
		else {
			while (LNext(&list, &pcard)) {
				if (!NameCompare(pcard, "�̼���")) {
					ChangePhoneNumber(pcard, "010-3842-1212");
					break;
				}
			}
		}
	}

	// ��μ� ���� ����
	if (LFirst(&list, &pcard)) {
		if (!NameCompare(pcard, "��μ�")) {
			LRemove(&list);
			free(pcard);
		}
		else {
			while (LNext(&list, &pcard)) {
				if (!NameCompare(pcard, "��μ�")) {
					LRemove(&list);
					free(pcard);
					break;
				}
			}
		}
	}

	// �����ִ� ��� ����� ���� ���
	printf("���� �������� ��: %d \n\n", LCount(&list));

	if (LFirst(&list, &pcard)) {
		ShowNameCardInfo(pcard);
		while (LNext(&list, &pcard))
			ShowNameCardInfo(pcard);
	}

	return 0;
}