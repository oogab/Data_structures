#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "NameCard.h"

// NameCard 구조체 변수의 동적 할당 및 초기화 후 주소 값 반환
NameCard* MakeNameCard(char* name, char* phone) {
	NameCard* ncard = (NameCard*)malloc(sizeof(NameCard));
	strcpy(ncard->name, name);
	strcpy(ncard->phone, phone);
	return ncard;
}

// NameCard 구조체 변수의 정보 출력
void ShowNameCardInfo(NameCard* pcard) {
	printf("이    름: %s \n", pcard->name);
	printf("전화번호: %s \n\n", pcard->phone);
}

// 이름이 같으면 0, 다르면 0이 아닌 값 반환
int NameCompare(NameCard* pcard, char* name) {
	return strcmp(pcard->name, name);
}

// 전화번호 정보를 변경
void ChangePhoneNumber(NameCard* pcard, char* phone) {
	strcpy(pcard->phone, phone);
}