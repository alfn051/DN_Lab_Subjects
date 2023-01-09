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
		printf("��� ������ ���� �޸� �Ҵ翡 ������ �ֽ��ϴ�.\n");
		return NULL;
	}
	cur->data = data;
	cur->link = NULL;
	return cur;
}

void input() {
	int data;
	while (1) {
		printf("\n������ �����Ͱ��� �Է��Ͻÿ� : ");
		if (scanf_s("%d", &data) == 0) {
			printf("\n���ڸ� �Է��Ͻÿ�\n");
			rewind(stdin);
		}
		else { break; }
	}
	node* cur = create(data);
	if (cur == NULL) {
		printf("���� �޸� �Ҵ翡 ������ �ֽ��ϴ�.");
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
		printf("���Ḯ��Ʈ�� ��尡 �������� �ʽ��ϴ�.\n");
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
	printf("������ (%d) �� ", num);
	do {
		if (currentNode->data == num) {
			printf("(%d��° ���) ", count);
			finded = 1;
		}
		currentNode = currentNode->link;
		count++;
	} while (currentNode != head);
	if (finded == 1) {
		printf("���� �˻��Ǿ����ϴ�.\n");
	}
	else {
		printf(" �˻����� �ʾҽ��ϴ�.\n");
	}
	return;
}

void search() {
	int num;
	while (1) {
		printf("\n�˻��� �����Ͱ��� �Է��Ͻÿ� : ");
		if (scanf_s("%d", &num) == 0) {
			printf("\n���ڸ� �Է��Ͻÿ�\n");
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
	while (lastNode->link != head) {	//lastNode�� ���Ḯ��Ʈ�� ������ ���� �̵�
		lastNode = lastNode->link;
	}
	if (head->data == num) {	//�����Ͱ� ù��° ��忡 ������
		head = head->link;
		lastNode->link = head;
		free(currentNode);
		printf("������ (%d) �� �����Ͽ����ϴ�.\n", num);
		return;
	}
	do {
		if (currentNode->link->data == num) {	//�����Ͱ� �մ� �ٷ� �� ��带 ã��
			temp = currentNode->link;	//������ ��带 temp�� ����Ŵ
			currentNode->link = temp->link;
			free(temp);
			printf("������ (%d) �� �����Ͽ����ϴ�.\n", num);
			return;
		}
		else {
			currentNode = currentNode->link;
		}
	}while (currentNode != head);
}

void deleteSelect(int num) {	//������ �����Ͱ� ������ ���� �� ���ϴ� ��常 �����ؼ� ����� �Լ�
	node* currentNode = head;
	node* temp;
	node* lastNode = head;
	int nodeNum;
	int count = 2;
	int finded = 0;
	searchNode(num);	//������ ��尡 �����忡 ��ġ���� �˷��ֱ� ����
	while (1) {
		printf("\n���° ��忡 �ִ� ������ (%d) �� �����Ͻðڽ��ϱ�? : ", num);
		if (scanf_s("%d", &nodeNum) == 0) {
			printf("\n���ڸ� �Է��Ͻÿ�\n");
			rewind(stdin);
		}
		else { break; }
	}
	while (lastNode->link != head) {	//lastNode�� ���Ḯ��Ʈ�� ������ ���� �̵�
		lastNode = lastNode->link;
	}
	if (nodeNum == 1) {	//�����Ͱ� ù��° ��忡 ������
		if (head->data == num) {
			head = head->link;
			lastNode->link = head;
			free(currentNode);
			printf("(1) ��° ��忡 �ִ� ������ (%d) �� �����Ͽ����ϴ�.\n", num);
			return;
		}
		else {
			printf("�����Ͻ� ��忡�� �ش� �����Ͱ� �������� �ʽ��ϴ�.\n");
			return;
		}
	}
	do {
		if (count == nodeNum) {	//�����Ͱ� �մ� �ٷ� �� ��带 ã��
			if (currentNode->link->data == num) {
				temp = currentNode->link;	//������ ��带 temp�� ����Ŵ
				currentNode->link = temp->link;
				free(temp);
				printf("(%d) ��° ��忡 �ִ� ������ (%d) �� �����Ͽ����ϴ�.\n", nodeNum, num);
				return;
			}
		}
		currentNode = currentNode->link;
		count++;
	} while (currentNode != head);
	printf("�����Ͻ� ��忡�� �ش� �����Ͱ� �������� �ʽ��ϴ�.\n");
	return;
}

void delete() {
	int num;
	int count = 0;
	while (1) {
		printf("\n������ �����Ͱ��� �Է��Ͻÿ� : ");
		if (scanf_s("%d", &num) == 0) {
			printf("\n���ڸ� �Է��Ͻÿ�\n");
			rewind(stdin);
		}
		else { break; }
	}
	node* currentNode = head;
	do {	//�����Ͱ� � �ִ��� �˻�
		if (currentNode->data == num) {
			count++;
		}
		currentNode = currentNode->link;
	}while (currentNode != head);
	if (count == 0) {
		printf("������ (%d) �� �߰ߵ��� �ʾҽ��ϴ�.", num);
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
		printf("* 1.�Է� 2.��� 3.�˻� 4.���� 5.���� *\n");
		printf("**************************************\n");

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