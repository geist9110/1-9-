#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

void add_new(void); // ���ο� ����ó �߰�
void list(void); // ����ó �����ֱ�
void search(void); // ����ó �˻�
void edit(void); // ����ó ����
void delete_contact(void); // ����ó ����
void Exit(int* a); // ������
void start(int* a); // ���� ȭ�� �Լ�
void D_C(char* name); // contact list���� name ������ ����
int S_C(char* name); // contact list���� name�� ������ 1 ������ 0�� ��ȯ
void Design1(char* title); // Ÿ��Ʋ ������
void Design2(void); // = ������
void clearFile(void); // �̽��Ϳ��� 6�� �Է½� contact list �ʱ�ȭ

main(void) {
	int a = 1; // �ݺ��� �� a
	while (a == 1) { // ���� ȭ�� �Լ�
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
	scanf_s("%d", &b); // ���� ȭ�鿡�� ������ ȭ������ �Ѿ�� ���� üũ
	printf("\n");

	if (b == 1) {
		add_new(); // ����Ʈ �ۼ����� �̵�
	}
	else if (b == 2) {
		list(); // ����Ʈ ���� ������
	}
	else if (b == 3) {
		search(); // ����Ʈ���� ����̸� �˻�
	}
	else if (b == 4) {
		edit(); // ����Ʈ���� ���� ����
	}
	else if (b == 5) {
		delete_contact(); // ����Ʈ���� ���� ����
	}
	else if (b == 0) {
		Exit(*a); // ����
	}
	else if (b == 6) {
		clearFile(); // ����Ʈ �ʱ�ȭ
	}
}

void add_new(void) { // ���ο� ����ó �߰�

	char title[] = "ADD A NEW CONTACT";
	char temp[100]; // �ӽ������

	Design1(title);
	printf("\n");
	Design2();
	FILE* fp = fopen("contact list.txt", "a"); // contact list.txt ��� �޸����� ��

	printf(" Name : ");
	scanf("%s", &temp); // �̸����� temp�� ����
	fputs(temp, fp); // temp���� txt���Ͽ� ����
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

	fclose(fp); // ���� �ݱ�
	printf("\n");
	Design2();
}

void list(void) { // ����ó �����ֱ�
	char title[] = "LIST OF CONTACTS";
	char temp[100]; // �ӽ� ����
	int i; // �ݺ����� i

	FILE* fp = fopen("contact list.txt", "r"); // contact list�� �б���� ��

	if (!fp) { // fopen�� r��忡�� ���� ����
		Design2();
		perror(" contact list�� �������� �ʽ��ϴ�.\n");
		printf("\n");
		Design2();
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

void search(void) { // ����ó �˻�
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

	if (!strcmp(name, "999")) { // 999 �̽��Ϳ���
		printf(" Name : ��ѱ�\n");
		printf(" Define : ��ѱ���� ���� ��Ʋ�� �̸��� ��\n");
		printf(" Address : ������ �뷮 ������\n");
		printf(" Characteristic : �ɾ�ٴϴ°� ������\n\n");
		Design2();
	}

	else if (!strcmp(name, "easter_egg")) { // easter egg �̽��Ϳ���
		printf(" Name : ��\n");
		printf(" Define : �Ӹ��� ���� ���� �ְ� ������ ��ȭ�Ͽ� �� ���� ���ϸ� �ٸ��� ưư�ϴ�\n");
		printf(" Address : ���� ��\n");
		printf(" Characteristic : ������\n\n");
		Design2();
	}

	else {
		FILE* f1 = fopen("contact list.txt", "r"); // contact list�� �б���� ��

		if (!f1) {  // fopen�� r��忡�� ���� ����
			perror(" contact list�� �������� �ʽ��ϴ�.\n");
			printf("\n");
			Design2();
		}
		else {
			fclose(f1);
			if (S_C(name)) {

				FILE* ff = fopen("contact list.txt", "r"); // contact.txt�� ���� ���� ����
				while (fgets(temp, 100, ff) != NULL) {
					col++;
				}
				fclose(ff);

				FILE* fp = fopen("contact list.txt", "r");

				strcat(name, "\n"); // strcmp�� ���ؼ� \n�� ������

				for (i = 0; i < col; i++) {
					fgets(temp, 100, fp);

					if (!strcmp(temp, name)) { // check �� contact�� ��
						printf(" Name : %s", temp);

						fgets(temp, 100, fp);
						printf(" Phone : %s", temp);

						fgets(temp, 100, fp);
						printf(" Address : %s", temp);

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
	}
}

void edit(void) { // ����ó ����
	char title[] = "EDIT A CONTACT";
	char name[101]; // �̸� �޾ƿ��� �뵵
	char temp[100]; // contact���� �޾ƿ��� �뵵

	Design1(title);
	printf("\n");
	Design2();

	printf(" The name of the person whose information you want to change : "); // �����ϰ� ���� ����� �̸�
	scanf("%s", &name);

	FILE* f1 = fopen("contact list.txt", "r"); // contact list�� �б���� ��

	if (!f1) {
		perror(" contact list�� �������� �ʽ��ϴ�.\n");
		printf("\n");
		Design2();
	}
	else {
		fclose(f1);
		if (S_C(name)) {
			D_C(name); // contact list���� ���ϴ� ����� �̸� ����

			FILE* fh = fopen("contact list.txt", "a"); // �������� ���ϴ� ����� ������ �߰� �Է�
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
}

void delete_contact(void) { // ����ó ����
	char title[] = "DELETE A CONTACT";
	char name[101]; // �̸� �޾ƿ��� �뵵

	Design1(title);
	printf("\n");
	Design2();
	printf(" The name of the person who wants to delete the information : "); // �����ϰ� ���� ��� �̸�
	scanf("%s", &name);

	FILE* f1 = fopen("contact list.txt", "r"); // contact list�� �б���� ��

	if (!f1) {
		perror(" contact list�� �������� �ʽ��ϴ�.\n");
		printf("\n");
		Design2();
	}
	else {
		fclose(f1);
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
}

void Exit(int* a) { // ������
	*a = 2;
}

void D_C(char* name) {

	char check[100]; // üũ��
	char temp[100]; // contact���� �޾ƿ��� �뵵
	int i = 0, j = 0, k = 1, col = 0;

	strcpy(check, name);
	strcat(check, "\n"); // strcmp�� ���ؼ� \n�� ������

	FILE* fa = fopen("temp.txt", "w"); // temp.txt �ʱ�ȭ
	fclose(fa);

	FILE* ff = fopen("contact list.txt", "r"); // contact.txt�� ���� ���� ����
	while (fgets(temp, 100, ff) != NULL) {
		col++;
	}
	fclose(ff);

	for (i; i < col - 3; i++) { // ã�� �̸� ������ �������� temp�� ����

		FILE* fc = fopen("contact list.txt", "r"); // contact.txt�� �� ���� ���ڿ��� ������
		for (j = 0; j < k; j++) {
			fgets(temp, 100, fc);
		}

		if (!strcmp(temp, check)) { // check �� contact�� ��
			fclose(fc);
			k += 3;
		}

		else {
			fclose(fc);
			FILE* fd = fopen("temp.txt", "a"); // ������ ���ڿ��� �ӽ� ���Ͽ� �������
			fputs(temp, fd);
			fclose(fd);
		}
		k += 1;
	}

	k = 1, i = 0; // k�� i �ʱ�ȭ
	FILE* fb = fopen("contact list.txt", "w"); // contact list �ʱ�ȭ
	fclose(fb);


	for (i; i < col - 4; i++) { // temp.txt���� contact.txt�� �̵�

		FILE* fe = fopen("temp.txt", "r"); // temp.txt�� �� ���� ���ڿ��� ������
		for (j = 0; j < k; j++) {
			fgets(temp, 100, fe);
		}
		fclose(fe);

		FILE* fg = fopen("contact list.txt", "a"); // ������ ���ڿ��� �ӽ� ���Ͽ� �������
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
	strcat(check, "\n"); // strcmp�� ���ؼ� \n�� ������

	FILE* ff = fopen("contact list.txt", "r"); // contact.txt�� ���� ���� ����
	while (fgets(temp, 100, ff) != NULL) {
		col++;
	}
	fclose(ff);

	FILE* fp = fopen("contact list.txt", "r");

	for (i = 0; i < col; i++) {
		fgets(temp, 100, fp);

		if (!strcmp(temp, check)) { // check �� contact�� ��
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
	FILE* fb = fopen("contact list.txt", "w"); // contact list �ʱ�ȭ
	fclose(fb);

	Design2();
	printf(" Contact list is cleard\n\n");
	Design2();
}