#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node* link;
}; typedef struct node node;

node* head = NULL;

node* create(int data) {
	node* cur = (node*)malloc(sizeof(node));
	if (cur == NULL) {
		printf("노드 생성을 위한 메모리 할당에 문제가 있습니다.\n");
		return NULL;
	}
	cur->data = data;
	cur->link = NULL;
	return cur;
}

void input() {
	int data;
	while (1) {
		printf("\n삽입할 데이터값을 입력하시오 : ");
		if (scanf_s("%d", &data) == 0) {
			printf("\n숫자만 입력하시오\n");
			rewind(stdin);
		}
		else { break; }
	}
	node* cur = create(data);
	if (cur == NULL) {
		printf("동적 메모리 할당에 문제가 있습니다.");
		exit(1);
	}
	printf("\n");
	node* currentNode = head;
	if (head == NULL) {
		head = cur;
		cur->link = head;
		return;
	}
	while (currentNode->link != head) {
		currentNode = currentNode->link;
	}
	currentNode->link = cur;
	cur->link = head;
	return;
}

void output() {
	printf("\n");
	if (head == NULL) {
		printf("연결리스트에 노드가 존재하지 않습니다.\n");
		return;
	}
	node* currentNode = head;
	do {
		printf("%d   ", currentNode->data);
		currentNode = currentNode->link;
	} while (currentNode != head);
	printf("\n");
}

void searchNode(int num) {
	int count = 1;
	int finded = 0;
	node* currentNode = head;
	printf("데이터 (%d) 는 ", num);
	do {
		if (currentNode->data == num) {
			printf("(%d번째 노드) ", count);
			finded = 1;
		}
		currentNode = currentNode->link;
		count++;
	} while (currentNode != head);
	if (finded == 1) {
		printf("에서 검색되었습니다.\n");
	}
	else {
		printf(" 검색되지 않았습니다.\n");
	}
	return;
}

void search() {
	int num;
	while (1) {
		printf("\n검색할 데이터값을 입력하시오 : ");
		if (scanf_s("%d", &num) == 0) {
			printf("\n숫자만 입력하시오\n");
			rewind(stdin);
		}
		else { break; }
	}
	searchNode(num);
	return;
}

void deleteNode(int num) {
	node* currentNode = head;
	node* temp;
	node* lastNode = head;
	while (lastNode->link != head) {	//lastNode를 연결리스트의 마지막 노드로 이동
		lastNode = lastNode->link;
	}
	if (head->data == num) {	//데이터가 첫번째 노드에 있을때
		head = head->link;
		lastNode->link = head;
		free(currentNode);
		printf("데이터 (%d) 를 삭제하였습니다.\n", num);
		return;
	}
	do {
		if (currentNode->link->data == num) {	//데이터가 잇는 바로 전 노드를 찾음
			temp = currentNode->link;	//삭제할 노드를 temp가 가리킴
			currentNode->link = temp->link;
			free(temp);
			printf("데이터 (%d) 를 삭제하였습니다.\n", num);
			return;
		}
		else {
			currentNode = currentNode->link;
		}
	}while (currentNode != head);
}

void deleteSelect(int num) {	//삭제할 데이터가 여러개 있을 때 원하는 노드만 선택해서 지우는 함수
	node* currentNode = head;
	node* temp;
	node* lastNode = head;
	int nodeNum;
	int count = 2;
	int finded = 0;
	searchNode(num);	//삭제할 노드가 어느노드에 위치한지 알려주기 위함
	while (1) {
		printf("\n몇번째 노드에 있는 데이터 (%d) 를 삭제하시겠습니까? : ", num);
		if (scanf_s("%d", &nodeNum) == 0) {
			printf("\n숫자만 입력하시오\n");
			rewind(stdin);
		}
		else { break; }
	}
	while (lastNode->link != head) {	//lastNode를 연결리스트의 마지막 노드로 이동
		lastNode = lastNode->link;
	}
	if (nodeNum == 1) {	//데이터가 첫번째 노드에 있을때
		if (head->data == num) {
			head = head->link;
			lastNode->link = head;
			free(currentNode);
			printf("(1) 번째 노드에 있는 데이터 (%d) 를 삭제하였습니다.\n", num);
			return;
		}
		else {
			printf("선택하신 노드에는 해당 데이터가 존재하지 않습니다.\n");
			return;
		}
	}
	do {
		if (count == nodeNum) {	//데이터가 잇는 바로 전 노드를 찾음
			if (currentNode->link->data == num) {
				temp = currentNode->link;	//삭제할 노드를 temp가 가리킴
				currentNode->link = temp->link;
				free(temp);
				printf("(%d) 번째 노드에 있는 데이터 (%d) 를 삭제하였습니다.\n", nodeNum, num);
				return;
			}
		}
		currentNode = currentNode->link;
		count++;
	} while (currentNode != head);
	printf("선택하신 노드에는 해당 데이터가 존재하지 않습니다.\n");
	return;
}

void delete() {
	int num;
	int count = 0;
	while (1) {
		printf("\n삭제할 데이터값을 입력하시오 : ");
		if (scanf_s("%d", &num) == 0) {
			printf("\n숫자만 입력하시오\n");
			rewind(stdin);
		}
		else { break; }
	}
	node* currentNode = head;
	do {	//데이터가 몇개 있는지 검사
		if (currentNode->data == num) {
			count++;
		}
		currentNode = currentNode->link;
	}while (currentNode != head);
	if (count == 0) {
		printf("데이터 (%d) 는 발견되지 않았습니다.", num);
		return;
	}
	if (count == 1) {
		deleteNode(num);
		return;
	}
	if (count > 1) {
		deleteSelect(num);
		return;
	}
}

int main(void) {
	int loop = 1;
	while (loop) {
		printf("\n**************************************\n");
		printf("* 1.입력 2.출력 3.검색 4.삭제 5.종료 *\n");
		printf("**************************************\n");

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