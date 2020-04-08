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

void add_new(void) { // ���ο� ����ó �߰�

	char temp[100]; // �ӽ������

	FILE* fp = fopen("contact list.txt", "a"); // contact list.txt ��� �޸����� ��

	printf("Name : ");
	scanf("%s", &temp); // �̸����� temp�� ����
	fputs(temp, fp); // temp���� txt���Ͽ� ����

	fputs("\n", fp); // �ٹٲ�

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

	fclose(fp); // ���� �ݱ�
	printf("\n\n");
}

void list(void) { // ����ó �����ֱ�
	char temp[100]; // �ӽ� ����
	int i; // �ݺ����� i

	FILE* fp = fopen("contact list.txt", "r"); // contact list�� �б���� ��

	if (!fp) {
		perror(" contact list�� �������� �ʽ��ϴ�.\n");
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

void search(void) { // ����ó �˻�
	printf("3");
}

void edit(void) { // ����ó ����

	char check[100]; // üũ��
	char temp[100]; // contact���� �޾ƿ��� �뵵
	char name[101]; // �̸� �޾ƿ��� �뵵
	int i = 0, j = 0, k = 1, col = 0;

	printf("The name of the person whose information you want to change : "); // �����ϰ� ���� ����� �̸�
	scanf("%s", &name);

	strcpy(check, name);
	strcat(check, "\n"); // strcmp�� ���ؼ� \n�� ������


	FILE* fa = fopen("temp.txt", "w");
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

void delete_contact(void) { // ����ó ����
	printf("5");
}

void Exit(int* a) { // ������
	*a = 2;
}