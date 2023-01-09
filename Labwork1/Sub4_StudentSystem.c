#define AUTOLOAD 1 // *** �ڵ� �ε� ��� on - 1 | off - 0 ***
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#define NAME_SIZE  20//�л� �̸� �� ���ڿ� ����
#define ARR_SIZE 100//����ü�迭 ����

struct student//�л����� ����ü
{
	int id;
	char name[NAME_SIZE];
	int korGrade;
	int mathGrade;
	int engGrade;
	int sumGrade;
	int average;
};
typedef struct student std;

std arr[ARR_SIZE];//�л� ������ �� ����ü �迭

int count = 0;//���鿡 �л��� ����ε������� ���Դ��� ī��Ʈ

void input(void) {
	int stopWhile = 0;
	while (1){
		while (1) {
			stopWhile = 0;
			printf("�й��� �Է��ϼ��� : ");
			if (scanf_s("%d", &arr[count].id) == 0) {
				printf("\n���ڸ� �Է��Ͻÿ�\n");
				rewind(stdin);
			}
			else { 
				if (arr[count].id < 0) {
					printf("\n0 �̻��� ���ڸ� �Է��Ͻÿ�\n");
				}
				else { break; }
			}
		}
		for (int i = 0; i < ARR_SIZE; i++) {
			if (i == count) {
			}
			else {
				if (arr[count].id == arr[i].id) {
					printf("%d �� �̹� �����ϴ� �й��Դϴ�. ���ο� ", arr[count].id);
					stopWhile = 1;
				}
			}
		}if (stopWhile == 0) { break; }
	}
	printf("�̸��� �Է��ϼ��� : ");
	scanf_s("%s", &arr[count].name, NAME_SIZE);
	rewind(stdin);

	while (1) {
		printf("���� ������ �Է��ϼ��� : ");
		if (scanf_s("%d", &arr[count].korGrade) == 0) {
			printf("\n���ڸ� �Է��Ͻÿ�\n");
			rewind(stdin);
		}
		else {
			if (arr[count].korGrade > 100 || arr[count].korGrade < 0) {
				printf("0 ~ 100 ������ ���ڸ� �Է��Ͻÿ�\n");
			}
			else { break; }
		}
	}
	while (1) {
		printf("���� ������ �Է��ϼ��� : ");
		if (scanf_s("%d", &arr[count].mathGrade) == 0) {
			printf("\n���ڸ� �Է��Ͻÿ�\n");
			rewind(stdin);
		}
		else {
			if (arr[count].mathGrade > 100 || arr[count].mathGrade < 0) {
				printf("\n0 ~ 100 ������ ���ڸ� �Է��Ͻÿ�\n");
			}
			else { break; }
		}
	}
	while (1) {
		printf("���� ������ �Է��ϼ��� : ");
		if (scanf_s("%d", &arr[count].engGrade) == 0) {
			printf("\n���ڸ� �Է��Ͻÿ�\n");
			rewind(stdin);
		}
		else {
			if (arr[count].engGrade > 100 || arr[count].engGrade < 0) {
				printf("\n0 ~ 100 ������ ���ڸ� �Է��Ͻÿ�\n");
			}
			else { break; }
		}
	}
	arr[count].sumGrade = arr[count].korGrade + arr[count].mathGrade + arr[count].engGrade;
	arr[count].average = arr[count].sumGrade / 3;
	count++;
	return;
}

void output(void) {
	if (count == 0) {
		printf("\n����� �л� ������ �����ϴ�.\n\n");
	}
	else {
		printf("\n");
		for (int i = 0; i < count; i++) {
			printf("�й� : %8d | �̸� : %s | �������� : %3d | �������� : %3d | �������� : %3d | �������� : %3d | ������� : %3d\n", arr[i].id, arr[i].name, arr[i].korGrade, arr[i].mathGrade, arr[i].engGrade, arr[i].sumGrade, arr[i].average);
		}
		printf("\n");
	}
	return;
}

void search(void) {
	int searchNum = 0;
	int searchIdx = 0;
	while (1) {
		printf("\n�˻��� �л��� �й��� �Է��ϼ��� : ");
		if (scanf_s("%d", &searchNum) == 0) {
			printf("\n���ڸ� �Է��Ͻÿ�\n");
			rewind(stdin);
		}
		else { break; }
	}
	for (int i = 0; i < ARR_SIZE; i++) {
		if (searchNum == arr[i].id) {
			printf("\n�й� : %8d | �̸� : %s | �������� : %3d | �������� : %3d | �������� : %3d | �������� : %3d | ������� : %3d\n\n", arr[i].id, arr[i].name, arr[i].korGrade, arr[i].mathGrade, arr[i].engGrade, arr[i].sumGrade, arr[i].average);
			searchIdx = i;
			break;
		}
		else { searchIdx = ARR_SIZE + 1; }
	}
	if (searchIdx == ARR_SIZE + 1) {
		printf("\n�˻��� ������ ã�� �� �����ϴ�.\n\n");
	}
	return;
}

void delete(void) {
	int searchNum = 0;
	int searchIdx = 0;
	int select = 0;
	while (1) {
		printf("\n������ �л��� �й��� �Է��ϼ��� : ");
		if (scanf_s("%d", &searchNum) == 0) {
			printf("\n���ڸ� �Է��Ͻÿ�\n");
			rewind(stdin);
		}
		else { break; }
	}
	for (int i = 0; i < ARR_SIZE; i++) {
		if (searchNum == arr[i].id) {
			printf("\n�˻��� �л��� ���� �л��Դϴ�.\n");
			printf("\n�й� : %8d | �̸� : %s | �������� : %3d | �������� : %3d | �������� : %3d | �������� : %3d | ������� : %3d\n", arr[i].id, arr[i].name, arr[i].korGrade, arr[i].mathGrade, arr[i].engGrade, arr[i].sumGrade, arr[i].average);
			int stopper = 1;
			while (stopper) {
				printf("\n�ش��л��� �����Ͻðڽ��ϱ�? ������ 1�� ����Ϸ��� 2�� �Է��ϼ���. : ");
				if (scanf_s("%d", &select) == 0) {
					rewind(stdin);
					select = 0;
				}
				switch (select)
				{
				case 1:
					searchIdx = i;
					stopper = 0;
					break;
				case 2:
					searchIdx = ARR_SIZE + 2;
					stopper = 0;
					break;
				default:
					printf("\n���� 1, 2 �� �ϳ��� �Է��Ͻÿ�\n");
					break;
				}
			}		
			break;
		}
		else { searchIdx = ARR_SIZE + 1; }
	}
	if (searchIdx == ARR_SIZE + 1) {
		printf("\n�˻��� ������ ã�� �� �����ϴ�.\n\n");
	}
	else if (searchIdx == ARR_SIZE + 2) {
		printf("\n������ ����Ͽ����ϴ�.\n\n");
	}
	else {
		printf("\n%d �л��� ������ �����Ͽ����ϴ�.\n\n", arr[searchIdx].id);
		for (int i = searchIdx; i < ARR_SIZE-1; i++) {
			arr[i] = arr[i + 1];
		}
		std nostd = { 0 };
		arr[ARR_SIZE-1] = nostd;
		count -= 1;
	}
	return;
}

void save(void) {
	char fname[] = "students.txt";
	FILE* f;
	if (fopen_s(&f, fname, "w") != 0) {
		printf("������ ������ �ʽ��ϴ�.\n");
		exit(1);
	}
	for (int i = 0; i < count; i++) {
		fprintf(f, "%d %d %s %d %d %d %d %d\n", i+1, arr[i].id, arr[i].name, arr[i].korGrade, arr[i].mathGrade, arr[i].engGrade, arr[i].sumGrade, arr[i].average);
	}
	fclose(f);
	printf("\n\"students.txt\"���Ͽ� �л� ����� �����߽��ϴ�.\n\n");
	return;
}

void load(void) {
	char fname[] = "students.txt";
	FILE* f;
	if (fopen_s(&f, fname, "r") != 0) {
		printf("������ ������ �ʽ��ϴ�.\n");
		exit(1);
	}
	std loadStd;
	int scCount = 1;
	while(fscanf(f, "%d %d %s %d %d %d %d %d\n", &scCount, &loadStd.id, loadStd.name, &loadStd.korGrade, &loadStd.mathGrade, &loadStd.engGrade, &loadStd.sumGrade, &loadStd.average) !=EOF) {
		arr[scCount - 1] = loadStd;
		count = scCount;
	}
	fclose(f);
	printf("\n\"students.txt\"���� �л� ����� �ҷ��Խ��ϴ�.\n\n");
	return;
}

void range() {
	std temp;
	for (int i = 0; i < ARR_SIZE; i++) {
		for (int j = i + 1; j < ARR_SIZE; j++) {
			if (arr[i].sumGrade < arr[j].sumGrade) {
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}return;
}

void main(void) {
	if (AUTOLOAD == 1) {
		printf("\n----------!�ڵ� �ε� ��� Ȱ��ȭ��!----------");
		load();
	}
	int loop = 1;
	while (loop){
		range();
		printf("****************************************************\n");
		printf("* 1.�Է� 2.��� 3.�˻� 4.���� 5.���� 6.�ε� 7.���� *\n");
		printf("****************************************************\n");

		int select;
		printf("�Է��� ��ȣ�� �Է��ϼ��� : ");
		if (scanf_s("%d", &select) == 0) {
			rewind(stdin);
			select = 0;
		}
		switch (select) {
		case 1:
			input();
			break;
		case 2:
			output();
			break;
		case 3:
			search();
			break;
		case 4:
			delete();
			break;
		case 5:
			save();
			break;
		case 6:
			load();
			break;
		case 7:
			printf("\n\n-----�ý����� �����մϴ�.-----\n\n");
			loop = 0;
			break;
		default:
			printf("1 ~ 7 �� ���ڸ� �Է��Ͻÿ�\n");
			select = 0;
			break;
		}
		
	}
}