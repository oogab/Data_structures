#include <stdio.h>
#include <stdlib.h>
#include "NameCard.h"
#include "ArrayList.h"

int main(void) {
	List list;
	NameCard* pcard;

	ListInit(&list);

	// 3¸íÀÇ NameCard Á¤º¸ »ý¼º ¹× ÀúÀå ///////
	pcard = MakeNameCard("¹é»ó¿í", "010-3221-0000");
	LInsert(&list, pcard);

	pcard = MakeNameCard("±è¹Î¼·", "010-8844-2222");
	LInsert(&list, pcard);

	pcard = MakeNameCard("ÀÌ¼ºÇö", "010-4535-1111");
	LInsert(&list, pcard);

	// ±è¹Î¼· Á¤º¸ Ãâ·Â
	if (LFirst(&list, &pcard)) {
		if (!NameCompare(pcard,"±è¹Î¼·"))
			ShowNameCardInfo(pcard);
		else {
			while (LNext(&list, &pcard)) {
				if (!NameCompare(pcard, "±è¹Î¼·")) {
					ShowNameCardInfo(pcard);
					break;
				}
			}
		}
	}

	// ÀÌ¼ºÇö ÀüÈ­¹øÈ£ Á¤º¸ º¯°æ
	if (LFirst(&list, &pcard)) {
		if (!NameCompare(pcard, "ÀÌ¼ºÇö"))
			ChangePhoneNumber(pcard, "010-3842-1212");
		else {
			while (LNext(&list, &pcard)) {
				if (!NameCompare(pcard, "ÀÌ¼ºÇö")) {
					ChangePhoneNumber(pcard, "010-3842-1212");
					break;
				}
			}
		}
	}

	// ±è¹Î¼· Á¤º¸ »èÁ¦
	if (LFirst(&list, &pcard)) {
		if (!NameCompare(pcard, "±è¹Î¼·")) {
			LRemove(&list);
			free(pcard);
		}
		else {
			while (LNext(&list, &pcard)) {
				if (!NameCompare(pcard, "±è¹Î¼·")) {
					LRemove(&list);
					free(pcard);
					break;
				}
			}
		}
	}

	// ³²¾ÆÀÖ´Â ¸ðµç »ç¶÷ÀÇ Á¤º¸ Ãâ·Â
	printf("ÇöÀç µ¥ÀÌÅÍÀÇ ¼ö: %d \n\n", LCount(&list));

	if (LFirst(&list, &pcard)) {
		ShowNameCardInfo(pcard);
		while (LNext(&list, &pcard))
			ShowNameCardInfo(pcard);
	}

	return 0;
}