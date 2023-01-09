#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node* left;
	struct node* right;
}; typedef struct node node;

node* head = NULL;

node* create(int data) {
	node* cur = (node*)malloc(sizeof(node));
	if (cur == NULL) {
		printf("��� ������ ���� �޸� �Ҵ翡 ������ �ֽ��ϴ�.\n");
		return NULL;
	}
	cur->data = data;
	cur->left = NULL;
	cur->right = NULL;
	return cur;
}

void inputNode(data) {
	node* cur = create(data);
	if (cur == NULL) {
		printf("���� �޸� �Ҵ翡 ������ �ֽ��ϴ�.\n");
		exit(1);
	}
	node* currentNode = head;
	if (head == NULL) {
		head = cur;
		return;
	}
	while (1) {
		if (currentNode->data > data) {
			if (currentNode->left == NULL) {
				currentNode->left = cur;
				return;
			}
			currentNode = currentNode->left;
		}
		else {
			if (currentNode->right == NULL) {
				currentNode->right = cur;
				return;
			}
			currentNode = currentNode->right;
		}
	}
	return;
}

void input() {
	int data;
	while (1) {
		printf("\n������ �����Ͱ��� �Է��Ͻÿ� : ");
		if (scanf_s("%d", &data) == 0) {
			printf("\n���ڸ� �Է��Ͻÿ�\n");
			rewind(stdin);
		}
		else {
			if (data < 0) {
				printf("0 �̻��� ���ڸ� �Է��Ͻÿ�");
			}
			else { break; }
		}
	}
	inputNode(data);
	printf("\n");
	return;
}

void preorder(node* currentNode) {
	if (currentNode == NULL) {
		return;
	}
	printf("%d   ", currentNode->data);
	preorder(currentNode->left);
	preorder(currentNode->right);
}

void inorder(node* currentNode) {
	if (currentNode == NULL) {
		return;
	}
	inorder(currentNode->left);
	printf("%d   ", currentNode->data);
	inorder(currentNode->right);
}

void postorder(node* currentNode) {
	if (currentNode == NULL) {
		return;
	}
	postorder(currentNode->left);
	postorder(currentNode->right);
	printf("%d   ", currentNode->data);
}

void output() {
	printf("\n");
	if (head == NULL) {
		printf("����Ž��Ʈ���� ��尡 �������� �ʽ��ϴ�.\n");
		return;
	}
	node* currentNode = head;

	printf("\n������ȸ : ");
	preorder(currentNode);
	
	printf("\n\n������ȸ : ");
	inorder(currentNode);

	printf("\n\n������ȸ : ");
	postorder(currentNode);
	printf("\n");
}

int findedChild = -1;	//������ �������� ����� ����(�ڽĳ�� ����)�� ����ϴ� ����, -1�̸� ������ �����͸� ���� ��尡 ������ �ǹ�
node* findedNode;

void findChild(node* currentNode, int num) {	//������ ���� �� ������ Ȯ���ϴ� �Լ�
	if (currentNode == NULL) {
		return;
	}
	if (currentNode->data == num) {
		findedNode = currentNode;
		if (currentNode->left == NULL && currentNode->right == NULL) {
			findedChild = 0;
		}
		else if (currentNode->left == NULL || currentNode->right == NULL) {
			findedChild = 1;
		}
		else {
			findedChild = 2;
		}
	}
	//printf("%d   ", currentNode->data);
	findChild(currentNode->left, num);
	findChild(currentNode->right, num);
	return;
}

deleteZeroDeg(node *currentNode, node *findedNode) {
	if (currentNode == NULL) {
		return;
	}
	if (currentNode->left == findedNode) {
		currentNode->left = NULL;
	}
	if (currentNode->right == findedNode) {
		currentNode->right = NULL;
	}
	//printf("%d   ", currentNode->data);
	deleteZeroDeg(currentNode->left, findedNode);
	deleteZeroDeg(currentNode->right, findedNode);
	return;
}

deleteSingleDeg(node* currentNode, node* findedNode) {
	if (currentNode == NULL) {
		return;
	}
	if (currentNode->left == findedNode) {
		if (findedNode->left == NULL) {
			currentNode->left = findedNode->right;
		}
		if (findedNode->right == NULL) {
			currentNode->left = findedNode->left;
		}
	}
	if (currentNode->right == findedNode) {
		if (findedNode->left == NULL) {
			currentNode->right = findedNode->right;
		}
		if (findedNode->right == NULL) {
			currentNode->right = findedNode->left;
		}
	}
	//printf("%d   ", currentNode->data);
	deleteSingleDeg(currentNode->left, findedNode);
	deleteSingleDeg(currentNode->right, findedNode);
	return;
}

void deleteNode(num) {
	node* currentNode = head;
	findedChild = -1;
	findChild(currentNode, num);
	if (findedChild == 0) {	//�����Ϸ��� ��尡 �ܸ� ����� ���(������ 0�� ���)
		if (findedNode == head) {
			head = NULL;
			free(findedNode);
			return;
		}
		deleteZeroDeg(currentNode, findedNode);
		free(findedNode);
	}
	else if (findedChild == 1) {	//�����Ϸ��� ��尡 �ϳ��� ����Ʈ���� ���� ���(������ 1�� ���)
		if (findedNode == head) {
			if (head->left != NULL) {
				head = head->left;
				free(findedNode);
				return;
			}
			if (head->right != NULL) {
				head = head->right;
				free(findedNode);
				return;
			}
		}
		deleteSingleDeg(currentNode, findedNode);
		free(findedNode);
	}
	else if (findedChild == 2) {	//�����Ϸ��� ��尡 �ΰ��� ����Ʈ���� ���� ���(������ 2�� ���)
		deleteDoubleDeg(currentNode, findedNode);
	}
	else {
		printf("�ش� �����͸� ���� ��带 ã�� �� �����ϴ�.\n");
	}
}

deleteDoubleDeg(node* currentNode, node* findedNode) {
	int savedData;
	currentNode = findedNode;
	currentNode = currentNode->left;
	while (currentNode->right != NULL) {
		currentNode = currentNode->right;
	}
	savedData = currentNode->data;
	deleteNode(savedData);
	findedNode->data = savedData;
}

void delete() {
	int num;
	while (1) {
		printf("\n������ �����Ͱ��� �Է��Ͻÿ� : ");
		if (scanf_s("%d", &num) == 0) {
			printf("\n���ڸ� �Է��Ͻÿ�\n");
			rewind(stdin);
		}
		else { break; }
	}
	deleteNode(num);
}

int main(void) {
	//inputNode(15);
	//inputNode(7);
	//inputNode(20);
	//inputNode(4);
	//inputNode(11);
	//inputNode(16);
	//inputNode(27);
	//inputNode(9);
	//inputNode(17);

	int loop = 1;
	while (loop) {
		printf("\n**************************************\n");
		printf("* 1.�Է� 2.��� 3.���� 4.���� *\n");
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
			delete();
			break;
		case 4:
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
