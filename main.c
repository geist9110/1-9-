#include <stdio.h>

void add_new(void); // 새로운 연락처 추가
void list(void); // 연락처 보여주기
void search(void); // 연락처 검색
void edit(void); // 연락처 수정
void delete_contact(void); // 연락처 삭제
void Exit(int *a); // 나가기
void start(int *a); // 메인 화면 함수

main(void) {
	int a = 1; // 반복문 용 a
	while (a == 1) { // 메인 화면 함수
		start(a);
	}
}

void start(int *a) {
	int b = 0;

	printf(" **** Welcome to Contact Management System ****\n\n");
	printf("                 MAIN MENU\n");
	printf("          ==========================\n");
	printf("          [1] Add a new Contact\n");
	printf("          [2] List all Contact\n");
	printf("          [3] Search for contacr\n");
	printf("          [4] Edit a Contact\n");
	printf("          [5] Delete a Contacr\n");
	printf("          [0] Exit\n");
	printf("          ==========================\n");
	printf("          Enter the choice:");
	scanf_s("%d", &b); // 메인 화면에서 각각의 화면으로 넘어가기 위해 체크
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");

	if (b == 1) {
		add_new();
	}
	else if (b == 2) {
		list();
	}
	else if (b == 3) {
		search();
	}
	else if (b == 4) {
		edit();
	}
	else if (b == 5) {
		delete_contact();
	}
	else if (b == 0) {
		Exit(*a);
	}


}

void add_new(void) { // 새로운 연락처 추가
	printf("1");
}

void list(void) { // 연락처 보여주기
	printf("          ==========================\n");
	printf("              LIST OF CONTACTS\n");
	printf("          ==========================\n\n");
	printf(" Name          Phone No          Address          E-maid ad\n");
	printf(" ===========================================================\n");

	printf(" ===========================================================\n");
}

void search(void) { // 연락처 검색
	printf("3");
}

void edit(void) { // 연락처 수정
	printf("          ==========================\n");
	printf("               EDIT A CONTACTS\n");
	printf("          ==========================\n\n");
	printf(" Name          Phone No          Address          E-maid ad\n");
	printf(" ===========================================================\n");

	printf(" ===========================================================\n");
}

void delete_contact(void) { // 연락처 삭제
	printf("5");
}

void Exit(int *a) { // 나가기
	*a = 2;
}