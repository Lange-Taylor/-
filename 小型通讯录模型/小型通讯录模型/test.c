#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
//ͨѶ¼���������洢1000���˵���Ϣ��ÿ���˵���Ϣ������
//�������Ա����䡢�绰��סַ
//1.	�����ϵ����Ϣ
//2.	ɾ��ָ����ϵ����Ϣ
//3.	����ָ����ϵ����Ϣ
//4.	�޸�ָ����ϵ����Ϣ
//5.	��ʾ������ϵ����Ϣ
//6.	���������ϵ��
//7.	����������������ϵ��
//8. ������ϵ�˵��ļ�
//9. ������ϵ��

typedef struct PersonInfo {
	char name[1024];
	char sex[1024];
	int age[1024];
	char phone[1024];
	char address[1024];
}PersonInfo;

typedef struct AddressBook {
	PersonInfo* persons;
	int size;//��ʾ��ЧԪ��
	int capacity;
}AddressBook,*Pc;
AddressBook g_address_book;
int Menu() {
	printf("*************************\n");
	printf("*****1.������ϵ��********\n");
	printf("*****2.ɾ��ָ����ϵ��****\n");
	printf("*****3.����ָ����ϵ��****\n");
	printf("*****4.�޸�ָ����ϵ��****\n");
	printf("*****5.��ʾ������ϵ��****\n");
	printf("*****6.���������ϵ��****\n");
	printf("*****7.������������ϵ��**\n");
	printf("*****8.������ϵ�˵��ļ�**\n");
	printf("*****9.������ϵ��********\n");
	printf("*************************\n");
	int choice = 0;
	printf("����������ѡ��:");
	scanf("%d", &choice);
	return choice;
}
void Empty() {
}
void Init() {
	g_address_book.size = 0;
	g_address_book.capacity = 100;
	g_address_book.persons = (PersonInfo*)malloc(100 * sizeof(PersonInfo));
	for (int i = 0; i < g_address_book.capacity; ++i) {
		g_address_book.persons[i].name[0] = '\0';
		g_address_book.persons[i].sex[0] = '\0';
		g_address_book.persons[i].age[0] = '\0';
		g_address_book.persons[i].phone[0] = '\0';
		g_address_book.persons[i].address[0] = '\0';
	}
}
void AddPersonInfo() {
	printf("������ϵ��\n");
	if (g_address_book.size >= g_address_book.capacity) {
		printf("��ǰ�ռ䲻��!��������!\n");
		g_address_book.capacity += 100;
		g_address_book.persons = (PersonInfo*)realloc(g_address_book.persons,
			g_address_book.capacity * sizeof(PersonInfo));
	}
	PersonInfo* person_info = &g_address_book.persons[g_address_book.size];
	printf("��������ϵ������\n");
	//�����ȡһ��ָ��,�޸ĵ�������������Ҫ��.
	scanf("%s", person_info->name);
	printf("��������ϵ���Ա�\n");
	scanf("%s", person_info->sex);
	printf("��������ϵ������\n");
	scanf("%s", person_info->age);
	printf("��������ϵ�˵绰\n");
	scanf("%s", person_info->phone);
	printf("��������ϵ��סַ\n");
	scanf("%s", person_info->address);
	++g_address_book.size;
	printf("������ϵ�˳ɹ�\n");
}
void DelPersonInfo() {
	printf("ɾ����ϵ��\n");
	if (g_address_book.size <= 0) {
		printf("ɾ��ʧ��,ͨѶ¼Ϊ��\n");
		return;
	}
	printf("������Ҫɾ�������\n");
	int id = 0;
	scanf("%d",&id);
	if (id<0 || id>=g_address_book.size) {
		printf("ɾ��ʧ��,��������������\n");
		return;
	}
	g_address_book.persons[id] =
		g_address_book.persons[g_address_book.size - 1];
	--g_address_book.size;
	printf("ɾ����ϵ�˳ɹ�\n");
	/////////////////////////////////////////
}
void FindPersonInfo() {	
	printf("������ϵ��\n");
	if (g_address_book.size <= 0) {
		printf("����ʧ��,ͨѶ¼Ϊ��\n");
		return;
	}
	printf("��������Ҫ���ҵ���ϵ������:");
	char name[1024] = { 0 };
	scanf("%s",name);
	for (int i = 0; i < g_address_book.size; ++i) {
		PersonInfo* info = &g_address_book.persons[i];
		if (strcmp(info->name, name) == 0) {
			printf("[%d] %s\t%s\t%s\t%s\t%s\n", i,
			info->name, info->sex, info->age, info->phone, info->address);
		}
	}
	printf("������ϵ�˳ɹ�\n");
}
void UpdatPersonInfo() {
	printf("������ϵ��\n");
	if (g_address_book.size <= 0) {
		printf("�޸�ʧ��,ͨѶ¼Ϊ��\n");
		return;
	}
	printf("������Ҫ�޸ĵ����\n");
	int id = 0;
	scanf("%d", &id);
	if (id < 0 || id >= g_address_book.size) {
		printf("��������������,�޸�ʧ��\n");
		return;
	}
	PersonInfo* info = &g_address_book.persons[id];
	printf("*��ʾ��ͬ��Ϣ���޸�\n");
	printf("�������µ�����:(%s)\n",info->name);
	char name[1024] = { 0 };
	scanf("%s", name);
	if (strcmp(name, "*") != 0) {
		strcpy(info->name, name);
	}
	printf("�����µ��Ա�:(%s)\n", info->sex);
	char sex[1024] = { 0 };
	scanf("%s", sex);
	if (strcmp(sex, "*") != 0) {
		strcpy(info->sex, sex);
	}
	printf("�������µ�����:(%s)\n", info->age);
	int age[1024] = { 0 };
	scanf("%s", age);
	if (strcmp(age, "*") != 0) {
		strcpy(info->age, age);
	}
	printf("�������µĵ绰:(%s)\n", info->phone);
	char phone[1024] = { 0 };
	scanf("%s", phone);
	if (strcmp(phone, "*") != 0) {
		strcpy(info->phone,phone );
	}
	printf("�������µ�סַ:(%s)\n", info->address);
	char address[1024] = { 0 };
	scanf("%s", address);
	if (strcmp(address, "*") != 0) {
		strcpy(info->address,address );
	}
	printf("������ϵ�˳ɹ�\n");
}
void PrintAllPersonInfo() {
	printf("��ӡȫ����ϵ��\n");
	for (int i = 0; i < g_address_book.size; ++i) {
		PersonInfo* info = &g_address_book.persons[i];
		printf("[%d] %s\t%s\t%s\t%s\t%s\n",i,info->name,
			info->sex, info->age, info->phone, info->address);
	}
	printf("����ӡ�� %d ������!\n",g_address_book.size);
	printf("��ӡȫ����ϵ�˳ɹ�\n");
}
void ClearAllPersonInfo() {
	printf("�����ϵ��\n");
	printf("��ȷ��Ҫɾ��ȫ����ϵ��Y\N,����������ѡ��:\n");
	char choice[1024] = {0};
	scanf("%s",&choice);
	if (strcmp(choice, "Y") == 0) {
		g_address_book.size = 0;
		for (int i = 0; i < g_address_book.capacity; ++i) {
			g_address_book.persons[i].name[0] = ' ';
			g_address_book.persons[i].sex[0] = ' ';
			g_address_book.persons[i].age[0] = ' ';
			g_address_book.persons[i].phone[0] = ' ';
			g_address_book.persons[i].address[0] = ' ';
		}
		printf("�����ϵ�˳ɹ�\n");

	}
	else {
		printf("�������ȡ��\n");
	}
}
void SortPersonInfo() {
	printf("������ϵ��\n");
	if (g_address_book.size <= 0) {
		printf("����ʧ��,ͨѶ¼Ϊ��\n");
		return;
	}
	PersonInfo tmp;
	for (int i = 0; i < g_address_book.size; ++i) {
		for (int j = 1; j < g_address_book.size - i; ++j) {
			if (strcmp(g_address_book.persons[j - 1].name, 
				g_address_book.persons[j].name) > 0) {
				tmp = g_address_book.persons[j];
				g_address_book.persons[j] = g_address_book.persons[j-1];
				g_address_book.persons[j-1] = tmp;

			}
		}
	}
	PrintAllPersonInfo();
	printf("������ϵ�˳ɹ�\n");
}
void SavePersonInfoFile() {
	printf("������ϵ�˵��ļ�");
	int i = 0;
	int str[500][5] = { 0 };

	FILE* fp1 = fopen("./test.txt","w");
	if (fp1 == NULL) {
		//printf("%s\n", strerror(errno));
		perror("fopen");
		return 1;
	}
	for (i=0;i<g_address_book.size;++i) {
		//fwrite(&g_address_book.persons[g_address_book.size], sizeof(struct PersonInfo), 1, fp);
		str[i][0] = strlen(g_address_book.persons[i].name);
		str[i][1] = strlen(g_address_book.persons[i].age);
		str[i][2] = strlen(g_address_book.persons[i].sex);
		str[i][3] = strlen(g_address_book.persons[i].phone);
		str[i][4] = strlen(g_address_book.persons[i].address);
		fwrite(str[i],4,5,fp1);
	}
	fclose(fp1);
	FILE* fp2 = fopen("./��ϵ����Ϣ.txt", "w");
	if (fp2 == NULL) {
		perror("fopen");
		return 1;
	}
	for (i = 0; i < g_address_book.size; ++i) {
		fwrite(g_address_book.persons[i].name,
			strlen(g_address_book.persons[i].name),1,fp2);
		fprintf(fp2, "\t");
		fwrite(g_address_book.persons[i].sex,
			strlen(g_address_book.persons[i].sex), 1, fp2);
		fprintf(fp2, "\t");
		fwrite(g_address_book.persons[i].age,
			strlen(g_address_book.persons[i].age), 1, fp2);
		fprintf(fp2, "\t");
		fwrite(g_address_book.persons[i].phone,
			strlen(g_address_book.persons[i].phone), 1, fp2);
		fprintf(fp2, "\t");
		fwrite(g_address_book.persons[i].address,
			strlen(g_address_book.persons[i].address), 1, fp2);
		fprintf(fp2, "\t");
	}
	fclose(fp2);
	FILE* fp3 = fopen("./��ϵ�˸���.txt","w");
		if (fp3 == NULL) {
		perror("fopen");
		return 1;
	}
		fwrite(&g_address_book.size,4,1,fp3);
		fclose(fp3);
	printf("������ϵ�˵��ļ��ɹ�!\n");
}
void ReadPersonInfo() {
	printf("������ϵ������\n");
	int str[500][5] = { 0 };
	int size;
	size = g_address_book.size;
	FILE* fp3 = fopen("./��ϵ�˸���.txt", "r");
	if (fp3 == NULL) {
		perror("fopen");
		return 1;
	}
	fread(&g_address_book.size, 4, 1, fp3);
	fclose(fp3);
	FILE* fp1 = fopen("./test.txt","w");
	if (fp1 == NULL) {
		perror("fopen");
		return 1;
	}
	for (int i = 0;i<g_address_book.size;++i) {
		fread(str[i], 4, 5, fp1);
	}
	
	fclose(fp1); 
	FILE* fp2 = fopen("./��ϵ����Ϣ.txt", "r");
	if (fp2 == NULL) {
		perror("fopen");
		return 1;
	}
	for (int i =0;i<size;++i ) {
		fread(g_address_book.persons->name, str[i][0], 1, fp2);
		fread(g_address_book.persons->sex, str[i][1], 1, fp2);
		fread(g_address_book.persons->age, str[i][2], 1, fp2);
		fread(g_address_book.persons->phone, str[i][3], 1, fp2);
		fread(g_address_book.persons->address, str[i][4], 1, fp2);
		g_address_book.size++;
	}
	fclose(fp2);
	printf("������ϵ�˳ɹ�!\n");
}

typedef void(*Func)();
int main() {
	Func arr[] = {
		Empty,
		AddPersonInfo,
		DelPersonInfo,
		FindPersonInfo,
		UpdatPersonInfo,
		PrintAllPersonInfo,
		ClearAllPersonInfo,
		SortPersonInfo,
		SavePersonInfoFile,
		ReadPersonInfo
	};
	Init();
	while (1) {
		int choice = Menu();
		if (choice < 0 || choice >= sizeof(arr) / sizeof(arr[0])) {
			printf("������������,����������!\n");
			continue;
		}
		if (choice == 0) {
			printf("�ټ�\n");
			break;
		}
		arr[choice]();
	}
	system("pause");
	return 0;
}