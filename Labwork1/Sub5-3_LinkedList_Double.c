#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node* lLink;
	struct node* rLink;
}; typedef struct node node;

node* head = NULL;

node* create(int data) {
	node* cur = (node*)malloc(sizeof(node));
	if (cur == NULL) {
		printf("��� ������ ���� �޸� �Ҵ翡 ������ �ֽ��ϴ�.\n");
		return NULL;
	}
	cur->data = data;
	cur->lLink = NULL;
	cur->rLink = NULL;
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
		return;
	}
	while (currentNode->lLink != NULL) {
		currentNode = currentNode->lLink;
	}
	currentNode->lLink = cur;
	cur->rLink = currentNode;
	return;
}

void output() {
	int reverse = 1;
	while (1) {
		printf("\n���������� ����Ϸ��� 1 �� ���������� ����Ϸ��� 2�� �Է��Ͻÿ� 1 / 2 : ");
		if (scanf_s("%d", &reverse) == 0) {
			printf("\n���ڸ� �Է��Ͻÿ�\n");
			rewind(stdin);
		}
		else {
			if (reverse != 1 && reverse != 2) {
				printf("\n1 �̳� 2 �� �Է��Ͻÿ�\n");
			}
			else { break; }
		}
	}
	printf("\n");
	if (reverse == 1) {
		if (head == NULL) {
			printf("���Ḯ��Ʈ�� ��尡 �������� �ʽ��ϴ�.\n");
			return;
		}
		node* currentNode = head;
		while (currentNode != NULL) {
			printf("%d   ", currentNode->data);
			currentNode = currentNode->lLink;
		}
	}if (reverse == 2) {
		if (head == NULL) {
			printf("���Ḯ��Ʈ�� ��尡 �������� �ʽ��ϴ�.\n");
			return;
		}
		node* currentNode = head;
		while (currentNode->lLink != NULL) {
			currentNode = currentNode->lLink;
		}
		while (currentNode != NULL) {
			printf("%d   ", currentNode->data);
			currentNode = currentNode->rLink;
		}
	}
	
	printf("\n");
}

void searchNode(int num) {
	int count = 1;
	int finded = 0;
	node* currentNode = head;
	printf("������ (%d) �� ", num);
	while (currentNode != NULL) {
		if (currentNode->data == num) {
			printf("(%d��° ���) ", count);
			finded = 1;
		}
		currentNode = currentNode->lLink;
		count++;
	}
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
	if (head->data == num) {	//�����Ͱ� ù��° ��忡 ������
		head = head->lLink;
		head->rLink = NULL;
		free(currentNode);
		printf("������ (%d) �� �����Ͽ����ϴ�.\n", num);
		return;
	}
	while (currentNode != NULL) {
		if (currentNode->lLink->data == num) {	//�����Ͱ� �մ� �ٷ� �� ��带 ã��
			temp = currentNode->lLink;	//������ ��带 temp�� ����Ŵ
			currentNode->lLink = temp->lLink;
			if (currentNode->lLink != NULL) {
				currentNode->lLink->rLink = currentNode;
			}
			free(temp);
			printf("������ (%d) �� �����Ͽ����ϴ�.\n", num);
			return;
		}
		else {
			currentNode = currentNode->lLink;
		}
	}
}

void deleteSelect(int num) {	//������ �����Ͱ� ������ ���� �� ���ϴ� ��常 �����ؼ� ����� �Լ�
	node* currentNode = head;
	node* temp;
	int nodeNum;
	int count = 2;
	int finded = 0;
	searchNode(num);
	while (1) {
		printf("\n���° ��忡 �ִ� ������ (%d) �� �����Ͻðڽ��ϱ�? : ", num);
		if (scanf_s("%d", &nodeNum) == 0) {
			printf("\n���ڸ� �Է��Ͻÿ�\n");
			rewind(stdin);
		}
		else { break; }
	}
	if (nodeNum == 1) {	//�����Ͱ� ù��° ��忡 ������
		if (head->data == num) {
			head = head->lLink;
			head->rLink = NULL;
			free(currentNode);
			printf("(1) ��° ��忡 �ִ� ������ (%d) �� �����Ͽ����ϴ�.\n", num);
			return;
		}
		else {
			printf("�����Ͻ� ��忡�� �ش� �����Ͱ� �������� �ʽ��ϴ�.\n");
			return;
		}
	}
	while (currentNode != NULL) {
		if (count == nodeNum) {	//�����Ͱ� �մ� �ٷ� �� ��带 ã��
			if (currentNode->lLink->data == num) {
				temp = currentNode->lLink;	//������ ��带 temp�� ����Ŵ
				currentNode->lLink = temp->lLink;
				if (currentNode->lLink != NULL) {
					currentNode->lLink->rLink = currentNode;
				}
				free(temp);
				printf("(%d) ��° ��忡 �ִ� ������ (%d) �� �����Ͽ����ϴ�.\n", nodeNum, num);
				return;
			}
		}
		currentNode = currentNode->lLink;
		count++;
	}
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
	while (currentNode != NULL) {	//�����Ͱ� � �ִ��� �˻�
		if (currentNode->data == num) {
			count++;
		}
		currentNode = currentNode->lLink;
	}
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