#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
//通讯录可以用来存储1000个人的信息，每个人的信息包括：
//姓名、性别、年龄、电话、住址
//1.	添加联系人信息
//2.	删除指定联系人信息
//3.	查找指定联系人信息
//4.	修改指定联系人信息
//5.	显示所有联系人信息
//6.	清空所有联系人
//7.	以名字排序所有联系人
//8. 保存联系人到文件
//9. 加载联系人

typedef struct PersonInfo {
	char name[1024];
	char sex[1024];
	int age[1024];
	char phone[1024];
	char address[1024];
}PersonInfo;

typedef struct AddressBook {
	PersonInfo* persons;
	int size;//表示有效元素
	int capacity;
}AddressBook,*Pc;
AddressBook g_address_book;
int Menu() {
	printf("*************************\n");
	printf("*****1.新增联系人********\n");
	printf("*****2.删除指定联系人****\n");
	printf("*****3.查找指定联系人****\n");
	printf("*****4.修改指定联系人****\n");
	printf("*****5.显示所有联系人****\n");
	printf("*****6.清空所有联系人****\n");
	printf("*****7.以名字排序联系人**\n");
	printf("*****8.保存联系人到文件**\n");
	printf("*****9.加载联系人********\n");
	printf("*************************\n");
	int choice = 0;
	printf("请输入您的选择:");
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
	printf("新增联系人\n");
	if (g_address_book.size >= g_address_book.capacity) {
		printf("当前空间不足!进行扩容!\n");
		g_address_book.capacity += 100;
		g_address_book.persons = (PersonInfo*)realloc(g_address_book.persons,
			g_address_book.capacity * sizeof(PersonInfo));
	}
	PersonInfo* person_info = &g_address_book.persons[g_address_book.size];
	printf("请输入联系人姓名\n");
	//必须获取一个指针,修改的内容是与其想要的.
	scanf("%s", person_info->name);
	printf("请输入联系人性别\n");
	scanf("%s", person_info->sex);
	printf("请输入联系人年龄\n");
	scanf("%s", person_info->age);
	printf("请输入联系人电话\n");
	scanf("%s", person_info->phone);
	printf("请输入联系人住址\n");
	scanf("%s", person_info->address);
	++g_address_book.size;
	printf("新增联系人成功\n");
}
void DelPersonInfo() {
	printf("删除联系人\n");
	if (g_address_book.size <= 0) {
		printf("删除失败,通讯录为空\n");
		return;
	}
	printf("请输入要删除的序号\n");
	int id = 0;
	scanf("%d",&id);
	if (id<0 || id>=g_address_book.size) {
		printf("删除失败,您输入的序号有误\n");
		return;
	}
	g_address_book.persons[id] =
		g_address_book.persons[g_address_book.size - 1];
	--g_address_book.size;
	printf("删除联系人成功\n");
	/////////////////////////////////////////
}
void FindPersonInfo() {	
	printf("查找联系人\n");
	if (g_address_book.size <= 0) {
		printf("查找失败,通讯录为空\n");
		return;
	}
	printf("请输入你要查找的联系人姓名:");
	char name[1024] = { 0 };
	scanf("%s",name);
	for (int i = 0; i < g_address_book.size; ++i) {
		PersonInfo* info = &g_address_book.persons[i];
		if (strcmp(info->name, name) == 0) {
			printf("[%d] %s\t%s\t%s\t%s\t%s\n", i,
			info->name, info->sex, info->age, info->phone, info->address);
		}
	}
	printf("查找联系人成功\n");
}
void UpdatPersonInfo() {
	printf("更新联系人\n");
	if (g_address_book.size <= 0) {
		printf("修改失败,通讯录为空\n");
		return;
	}
	printf("请输入要修改的序号\n");
	int id = 0;
	scanf("%d", &id);
	if (id < 0 || id >= g_address_book.size) {
		printf("您输入的序号有误,修改失败\n");
		return;
	}
	PersonInfo* info = &g_address_book.persons[id];
	printf("*表示相同信息不修改\n");
	printf("请输入新的姓名:(%s)\n",info->name);
	char name[1024] = { 0 };
	scanf("%s", name);
	if (strcmp(name, "*") != 0) {
		strcpy(info->name, name);
	}
	printf("请输新的性别:(%s)\n", info->sex);
	char sex[1024] = { 0 };
	scanf("%s", sex);
	if (strcmp(sex, "*") != 0) {
		strcpy(info->sex, sex);
	}
	printf("请输入新的年龄:(%s)\n", info->age);
	int age[1024] = { 0 };
	scanf("%s", age);
	if (strcmp(age, "*") != 0) {
		strcpy(info->age, age);
	}
	printf("请输入新的电话:(%s)\n", info->phone);
	char phone[1024] = { 0 };
	scanf("%s", phone);
	if (strcmp(phone, "*") != 0) {
		strcpy(info->phone,phone );
	}
	printf("请输入新的住址:(%s)\n", info->address);
	char address[1024] = { 0 };
	scanf("%s", address);
	if (strcmp(address, "*") != 0) {
		strcpy(info->address,address );
	}
	printf("更新联系人成功\n");
}
void PrintAllPersonInfo() {
	printf("打印全部联系人\n");
	for (int i = 0; i < g_address_book.size; ++i) {
		PersonInfo* info = &g_address_book.persons[i];
		printf("[%d] %s\t%s\t%s\t%s\t%s\n",i,info->name,
			info->sex, info->age, info->phone, info->address);
	}
	printf("共打印了 %d 条数据!\n",g_address_book.size);
	printf("打印全部联系人成功\n");
}
void ClearAllPersonInfo() {
	printf("清除联系人\n");
	printf("您确定要删除全部联系人Y\N,请输入您的选择:\n");
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
		printf("清除联系人成功\n");

	}
	else {
		printf("清除操作取消\n");
	}
}
void SortPersonInfo() {
	printf("排序联系人\n");
	if (g_address_book.size <= 0) {
		printf("排序失败,通讯录为空\n");
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
	printf("排序联系人成功\n");
}
void SavePersonInfoFile() {
	printf("保存联系人到文件");
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
	FILE* fp2 = fopen("./联系人信息.txt", "w");
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
	FILE* fp3 = fopen("./联系人个数.txt","w");
		if (fp3 == NULL) {
		perror("fopen");
		return 1;
	}
		fwrite(&g_address_book.size,4,1,fp3);
		fclose(fp3);
	printf("保存联系人到文件成功!\n");
}
void ReadPersonInfo() {
	printf("加载联系人数据\n");
	int str[500][5] = { 0 };
	int size;
	size = g_address_book.size;
	FILE* fp3 = fopen("./联系人个数.txt", "r");
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
	FILE* fp2 = fopen("./联系人信息.txt", "r");
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
	printf("加载联系人成功!\n");
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
			printf("您的输入有误,请重新输入!\n");
			continue;
		}
		if (choice == 0) {
			printf("再见\n");
			break;
		}
		arr[choice]();
	}
	system("pause");
	return 0;
}