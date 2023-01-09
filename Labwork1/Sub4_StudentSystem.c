#define AUTOLOAD 1 // *** 자동 로드 기능 on - 1 | off - 0 ***
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#define NAME_SIZE  20//학생 이름 들어갈 문자열 길이
#define ARR_SIZE 100//구조체배열 길이

struct student//학생정보 구조체
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

std arr[ARR_SIZE];//학생 정보가 들어갈 구조체 배열

int count = 0;//공백에 학생이 몇번인덱스까지 들어왔는지 카운트

void input(void) {
	int stopWhile = 0;
	while (1){
		while (1) {
			stopWhile = 0;
			printf("학번을 입력하세요 : ");
			if (scanf_s("%d", &arr[count].id) == 0) {
				printf("\n숫자만 입력하시오\n");
				rewind(stdin);
			}
			else { 
				if (arr[count].id < 0) {
					printf("\n0 이상의 숫자만 입력하시오\n");
				}
				else { break; }
			}
		}
		for (int i = 0; i < ARR_SIZE; i++) {
			if (i == count) {
			}
			else {
				if (arr[count].id == arr[i].id) {
					printf("%d 는 이미 존재하는 학번입니다. 새로운 ", arr[count].id);
					stopWhile = 1;
				}
			}
		}if (stopWhile == 0) { break; }
	}
	printf("이름을 입력하세요 : ");
	scanf_s("%s", &arr[count].name, NAME_SIZE);
	rewind(stdin);

	while (1) {
		printf("국어 점수를 입력하세요 : ");
		if (scanf_s("%d", &arr[count].korGrade) == 0) {
			printf("\n숫자만 입력하시오\n");
			rewind(stdin);
		}
		else {
			if (arr[count].korGrade > 100 || arr[count].korGrade < 0) {
				printf("0 ~ 100 까지의 숫자만 입력하시오\n");
			}
			else { break; }
		}
	}
	while (1) {
		printf("수학 점수를 입력하세요 : ");
		if (scanf_s("%d", &arr[count].mathGrade) == 0) {
			printf("\n숫자만 입력하시오\n");
			rewind(stdin);
		}
		else {
			if (arr[count].mathGrade > 100 || arr[count].mathGrade < 0) {
				printf("\n0 ~ 100 까지의 숫자만 입력하시오\n");
			}
			else { break; }
		}
	}
	while (1) {
		printf("영어 점수를 입력하세요 : ");
		if (scanf_s("%d", &arr[count].engGrade) == 0) {
			printf("\n숫자만 입력하시오\n");
			rewind(stdin);
		}
		else {
			if (arr[count].engGrade > 100 || arr[count].engGrade < 0) {
				printf("\n0 ~ 100 까지의 숫자만 입력하시오\n");
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
		printf("\n출력할 학생 정보가 없습니다.\n\n");
	}
	else {
		printf("\n");
		for (int i = 0; i < count; i++) {
			printf("학번 : %8d | 이름 : %s | 국어점수 : %3d | 수학점수 : %3d | 영어점수 : %3d | 종합점수 : %3d | 평균점수 : %3d\n", arr[i].id, arr[i].name, arr[i].korGrade, arr[i].mathGrade, arr[i].engGrade, arr[i].sumGrade, arr[i].average);
		}
		printf("\n");
	}
	return;
}

void search(void) {
	int searchNum = 0;
	int searchIdx = 0;
	while (1) {
		printf("\n검색할 학생의 학번을 입력하세요 : ");
		if (scanf_s("%d", &searchNum) == 0) {
			printf("\n숫자만 입력하시오\n");
			rewind(stdin);
		}
		else { break; }
	}
	for (int i = 0; i < ARR_SIZE; i++) {
		if (searchNum == arr[i].id) {
			printf("\n학번 : %8d | 이름 : %s | 국어점수 : %3d | 수학점수 : %3d | 영어점수 : %3d | 종합점수 : %3d | 평균점수 : %3d\n\n", arr[i].id, arr[i].name, arr[i].korGrade, arr[i].mathGrade, arr[i].engGrade, arr[i].sumGrade, arr[i].average);
			searchIdx = i;
			break;
		}
		else { searchIdx = ARR_SIZE + 1; }
	}
	if (searchIdx == ARR_SIZE + 1) {
		printf("\n검색한 정보를 찾을 수 없습니다.\n\n");
	}
	return;
}

void delete(void) {
	int searchNum = 0;
	int searchIdx = 0;
	int select = 0;
	while (1) {
		printf("\n삭제할 학생의 학번을 입력하세요 : ");
		if (scanf_s("%d", &searchNum) == 0) {
			printf("\n숫자만 입력하시오\n");
			rewind(stdin);
		}
		else { break; }
	}
	for (int i = 0; i < ARR_SIZE; i++) {
		if (searchNum == arr[i].id) {
			printf("\n검색된 학생은 다음 학생입니다.\n");
			printf("\n학번 : %8d | 이름 : %s | 국어점수 : %3d | 수학점수 : %3d | 영어점수 : %3d | 종합점수 : %3d | 평균점수 : %3d\n", arr[i].id, arr[i].name, arr[i].korGrade, arr[i].mathGrade, arr[i].engGrade, arr[i].sumGrade, arr[i].average);
			int stopper = 1;
			while (stopper) {
				printf("\n해당학생을 삭제하시겠습니까? 맞으면 1을 취소하려면 2를 입력하세요. : ");
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
					printf("\n숫자 1, 2 중 하나만 입력하시오\n");
					break;
				}
			}		
			break;
		}
		else { searchIdx = ARR_SIZE + 1; }
	}
	if (searchIdx == ARR_SIZE + 1) {
		printf("\n검색한 정보를 찾을 수 없습니다.\n\n");
	}
	else if (searchIdx == ARR_SIZE + 2) {
		printf("\n삭제를 취소하였습니다.\n\n");
	}
	else {
		printf("\n%d 학생의 정보를 삭제하였습니다.\n\n", arr[searchIdx].id);
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
		printf("파일이 열리지 않습니다.\n");
		exit(1);
	}
	for (int i = 0; i < count; i++) {
		fprintf(f, "%d %d %s %d %d %d %d %d\n", i+1, arr[i].id, arr[i].name, arr[i].korGrade, arr[i].mathGrade, arr[i].engGrade, arr[i].sumGrade, arr[i].average);
	}
	fclose(f);
	printf("\n\"students.txt\"파일에 학생 목록을 저장했습니다.\n\n");
	return;
}

void load(void) {
	char fname[] = "students.txt";
	FILE* f;
	if (fopen_s(&f, fname, "r") != 0) {
		printf("파일이 열리지 않습니다.\n");
		exit(1);
	}
	std loadStd;
	int scCount = 1;
	while(fscanf(f, "%d %d %s %d %d %d %d %d\n", &scCount, &loadStd.id, loadStd.name, &loadStd.korGrade, &loadStd.mathGrade, &loadStd.engGrade, &loadStd.sumGrade, &loadStd.average) !=EOF) {
		arr[scCount - 1] = loadStd;
		count = scCount;
	}
	fclose(f);
	printf("\n\"students.txt\"에서 학생 목록을 불러왔습니다.\n\n");
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
		printf("\n----------!자동 로드 기능 활성화중!----------");
		load();
	}
	int loop = 1;
	while (loop){
		range();
		printf("****************************************************\n");
		printf("* 1.입력 2.출력 3.검색 4.삭제 5.저장 6.로드 7.종료 *\n");
		printf("****************************************************\n");

		int select;
		printf("입력할 번호를 입력하세요 : ");
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
			printf("\n\n-----시스템을 종료합니다.-----\n\n");
			loop = 0;
			break;
		default:
			printf("1 ~ 7 의 숫자만 입력하시오\n");
			select = 0;
			break;
		}
		
	}
}