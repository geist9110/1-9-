#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

void add_new(void); // 새로운 연락처 추가
void list(void); // 연락처 보여주기
void search(void); // 연락처 검색
void edit(void); // 연락처 수정
void delete_contact(void); // 연락처 삭제
void Exit(int* a); // 나가기
void start(int* a); // 메인 화면 함수

main(void) {
	int a = 1; // 반복문 용 a
	while (a == 1) { // 메인 화면 함수
		start(a);
	}
}

void start(int* a) {
	int b = 0;

	printf(" **** Welcome to Contact Management System ****\n\n");
	printf("                 MAIN MENU\n");
	printf("          ==========================\n");
	printf("          [1] Add a new Contact\n");
	printf("          [2] List all Contact\n");
	printf("          [3] Search for contact\n");
	printf("          [4] Edit a Contact\n");
	printf("          [5] Delete a Contact\n");
	printf("          [0] Exit\n");
	printf("          ==========================\n");
	printf("          Enter the choice : ");
	scanf_s("%d", &b); // 메인 화면에서 각각의 화면으로 넘어가기 위해 체크
	printf("\n");

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

	char temp[100]; // 임시저장용

	FILE* fp = fopen("contact list.txt", "a"); // contact list.txt 라는 메모장을 엶

	printf("Name : ");
	scanf("%s", &temp); // 이름값을 temp에 받음
	fputs(temp, fp); // temp값을 txt파일에 넣음

	fputs("\n", fp); // 줄바꿈

	printf("Phone Number : ");
	scanf("%s", &temp);
	fputs(temp, fp);
	fputs("\n", fp);

	printf("Address : ");
	scanf("%s", &temp);
	fputs(temp, fp);
	fputs("\n", fp);

	printf("Email : ");
	scanf("%s", &temp);
	fputs(temp, fp);
	fputs("\n", fp);

	fclose(fp); // 파일 닫기
	printf("\n\n");
}

void list(void) { // 연락처 보여주기
	char temp[100]; // 임시 변수
	int i; // 반복문용 i

	FILE* fp = fopen("contact list.txt", "r"); // contact list를 읽기모드로 엶

	if (!fp) {
		perror(" contact list가 존재하지 않습니다.\n");
	}
	
	else {
		printf("          ==========================\n");
		printf("              LIST OF CONTACTS\n");
		printf("          ==========================\n\n");
		printf(" Name          Phone No          Address          E-mail\n");
		printf(" ===========================================================\n\n");


		while (fgets(temp, 100, fp) != NULL) {
			printf("Name      : %s", temp);

			fgets(temp, 100, fp);
			printf("Phone     : %s", temp);

			fgets(temp, 100, fp);
			printf("Address   : %s", temp);

			fgets(temp, 100, fp);
			printf("Email     : %s\n", temp);
		}

		fclose(fp);
		printf(" ===========================================================\n\n");
	}
}

void search(void) { // 연락처 검색
	printf("3");
}

void edit(void) { // 연락처 수정

	char check[100]; // 체크용
	char temp[100]; // contact에서 받아오는 용도
	char name[101]; // 이름 받아오는 용도
	int i = 0, j = 0, k = 1, col = 0;

	printf("The name of the person whose information you want to change : "); // 변경하고 싶은 사람의 이름
	scanf("%s", &name);

	strcpy(check, name);
	strcat(check, "\n"); // strcmp를 위해서 \n를 더해줌


	FILE* fa = fopen("temp.txt", "w");
	fclose(fa);

	FILE* ff = fopen("contact list.txt", "r"); // contact.txt의 행의 개수 세기
	while (fgets(temp, 100, ff) != NULL) {
		col++;
	}
	fclose(ff);

	for (i; i < col - 3; i++) { // 찾는 이름 제외한 나머지를 temp로 복사

		FILE* fc = fopen("contact list.txt", "r"); // contact.txt의 각 행의 문자열을 가져옴
		for (j = 0; j < k; j++) {
			fgets(temp, 100, fc);
		}

		if (!strcmp(temp, check)) { // check 와 contact를 비교
			fclose(fc);
			k += 3;
		}

		else {
			fclose(fc);
			FILE* fd = fopen("temp.txt", "a"); // 가져온 문자열을 임시 파일에 집어넣음
			fputs(temp, fd);
			fclose(fd);
		}
		k += 1;
	}

	k = 1, i = 0; // k와 i 초기화
	FILE* fb = fopen("contact list.txt", "w"); // contact list 초기화
	fclose(fb);


	for (i; i < col - 4; i++) { // temp.txt에서 contact.txt로 이동

		FILE* fe = fopen("temp.txt", "r"); // temp.txt의 각 행의 문자열을 가져옴
		for (j = 0; j < k; j++) {
			fgets(temp, 100, fe);
		}
		fclose(fe);

		FILE* fg = fopen("contact list.txt", "a"); // 가져온 문자열을 임시 파일에 집어넣음
		fputs(temp, fg);
		fclose(fg);

		k += 1;
	}

	FILE* fh = fopen("contact list.txt", "a");
	fputs(name, fh);
	fputs("\n", fh);
	printf("%s's Phone Number : ", name);
	scanf("%s", &temp);
	fputs(temp, fh);
	fputs("\n", fh);

	printf("%s's Address : ", name);
	scanf("%s", &temp);
	fputs(temp, fh);
	fputs("\n", fh);

	printf("%s's Email : ", name);
	scanf("%s", &temp);
	fputs(temp, fh);
	fputs("\n", fh);
	fclose(fh);
}

void delete_contact(void) { // 연락처 삭제
	printf("5");
}

void Exit(int* a) { // 나가기
	*a = 2;
}