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
void D_C(char* name); // contact list에서 name 정보를 삭제
int S_C(char* name); // contact list에서 name이 있으면 1 없으면 0을 반환
void Design1(char* title); // 타이틀 디자인
void Design2(void); // = 디자인
void clearFile(void); // 이스터에그 6번 입력시 contact list 초기화

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

	switch (b) {
	case 1:
		add_new();
		break;

	case 2:
		list();
		break;

	case 3:
		search();
		break;

	case 4:
		edit();
		break;

	case 5:
		delete_contact();
		break;

	case 6:
		clearFile();
		break;

	case 0:
		Exit(*a);
		break;
	}
}

void add_new(void) { // 새로운 연락처 추가

	char title[] = "ADD A NEW CONTACT";
	char temp[100]; // 임시저장용

	Design1(title);
	printf("\n");
	Design2();
	FILE* fp = fopen("contact list.txt", "a"); // contact list.txt 라는 메모장을 엶

	printf(" Name : ");
	scanf("%s", &temp); // 이름값을 temp에 받음
	fputs(temp, fp); // temp값을 txt파일에 넣음
	fputs("\n", fp);

	printf(" Phone Number : ");
	scanf("%s", &temp);
	fputs(temp, fp);
	fputs("\n", fp);

	printf(" Address : ");
	scanf("%s", &temp);
	fputs(temp, fp);
	fputs("\n", fp);

	printf(" Email : ");
	scanf("%s", &temp);
	fputs(temp, fp);
	fputs("\n", fp);

	fclose(fp); // 파일 닫기
	printf("\n");
	Design2();
}

void list(void) { // 연락처 보여주기
	char title[] = "LIST OF CONTACTS";
	char temp[100]; // 임시 변수
	int i; // 반복문용 i

	FILE* fp = fopen("contact list.txt", "r"); // contact list를 읽기모드로 엶

	if (!fp) {
		perror(" contact list가 존재하지 않습니다.\n");
	}

	else {
		Design1(title);
		printf("\n");
		printf(" Name          Phone No          Address          E-mail\n");
		Design2();

		while (fgets(temp, 100, fp) != NULL) {
			printf("Name      : %s", temp);

			fgets(temp, 100, fp);
			printf("Phone     : %s", temp);

			fgets(temp, 100, fp);
			printf("Address   : %s", temp);

			fgets(temp, 100, fp);
			printf("Email     : %s", temp);
			printf("\n");
		}
		fclose(fp);
		Design2();
	}
}

void search(void) { // 연락처 검색
	char title[] = "SEARCH THE CONTACT";
	char name[100];
	char temp[100];
	char check[100];
	int i, col = 0;

	Design1(title);
	printf("\n");
	Design2();
	printf(" Name of the person you want to find : ");
	scanf("%s", &name);

	if (S_C(name)) {

		FILE* ff = fopen("contact list.txt", "r"); // contact.txt의 행의 개수 세기
		while (fgets(temp, 100, ff) != NULL) {
			col++;
		}
		fclose(ff);

		FILE* fp = fopen("contact list.txt", "r");

		strcat(name, "\n"); // strcmp를 위해서 \n를 더해줌

		for (i = 0; i < col; i++) {
			fgets(temp, 100, fp);

			if (!strcmp(temp, name)) { // check 와 contact를 비교
				printf(" Name : %s", temp);

				fgets(temp, 100, fp);
				printf(" Phone : %s", temp);

				fgets(temp, 100, fp);
				printf(" Adress : %s", temp);

				fgets(temp, 100, fp);
				printf(" Email : %s\n", temp);
				Design2();
				break;
			}
		}
		fclose(fp);
	}
	else {
		printf(" Name does not exist.\n\n");
		Design2();
	}
}

void edit(void) { // 연락처 수정
	char title[] = "EDIT A CONTACT";
	char name[101]; // 이름 받아오는 용도
	char temp[100]; // contact에서 받아오는 용도

	Design1(title);
	printf("\n");
	Design2();

	printf(" The name of the person whose information you want to change : "); // 변경하고 싶은 사람의 이름
	scanf("%s", &name);

	if (S_C(name)) {
		D_C(name); // contact list에서 원하는 사람의 이름 삭제

		FILE* fh = fopen("contact list.txt", "a"); // 마지막에 원하는 사람의 정보를 추가 입력
		fputs(name, fh);
		fputs("\n", fh);
		printf(" %s's Phone Number : ", name);
		scanf("%s", &temp);
		fputs(temp, fh);
		fputs("\n", fh);

		printf(" %s's Address : ", name);
		scanf("%s", &temp);
		fputs(temp, fh);
		fputs("\n", fh);

		printf(" %s's Email : ", name);
		scanf("%s", &temp);
		fputs(temp, fh);
		fputs("\n", fh);
		fclose(fh);

		printf("\n");
		Design2();
	}

	else {
		printf(" Name does not exist.\n\n");
		Design2();
	}
}

void delete_contact(void) { // 연락처 삭제
	char title[] = "DELETE A CONTACT";
	char name[101]; // 이름 받아오는 용도

	Design1(title);
	printf("\n");
	Design2();
	printf(" The name of the person who wants to delete the information : "); // 삭제하고 싶은 사람 이름
	scanf("%s", &name);

	if (S_C(name)) {
		D_C(name);

		printf("\n");
		Design2();
	}
	else {
		printf(" Name does not exist.\n\n");
		Design2();
	}
}

void Exit(int* a) { // 나가기
	*a = 2;
}

void D_C(char* name) {

	char check[100]; // 체크용
	char temp[100]; // contact에서 받아오는 용도
	int i = 0, j = 0, k = 1, col = 0;

	strcpy(check, name);
	strcat(check, "\n"); // strcmp를 위해서 \n를 더해줌

	FILE* fa = fopen("temp.txt", "w"); // temp.txt 초기화
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
}

int S_C(char* name) {
	char temp[100];
	char check[100];
	int i, col = 0;

	strcpy(check, name);
	strcat(check, "\n"); // strcmp를 위해서 \n를 더해줌

	FILE* ff = fopen("contact list.txt", "r"); // contact.txt의 행의 개수 세기
	while (fgets(temp, 100, ff) != NULL) {
		col++;
	}
	fclose(ff);

	FILE* fp = fopen("contact list.txt", "r");

	for (i = 0; i < col; i++) {
		fgets(temp, 100, fp);

		if (!strcmp(temp, check)) { // check 와 contact를 비교
			return 1;
		}
	}
	fclose(fp);
}

void Design1(char* title) {
	printf("          ==========================\n");
	printf("              %s\n", title);
	printf("          ==========================\n");
}

void Design2(void) {
	printf(" ===========================================================\n\n");
}

void clearFile(void) {
	FILE* fb = fopen("contact list.txt", "w"); // contact list 초기화
	fclose(fb);

	Design2();
	printf(" Contact list is cleard\n\n");
	Design2();
}