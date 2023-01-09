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
		printf("노드 생성을 위한 메모리 할당에 문제가 있습니다.\n");
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
		printf("동적 메모리 할당에 문제가 있습니다.\n");
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
		printf("\n삽입할 데이터값을 입력하시오 : ");
		if (scanf_s("%d", &data) == 0) {
			printf("\n숫자만 입력하시오\n");
			rewind(stdin);
		}
		else {
			if (data < 0) {
				printf("0 이상의 숫자만 입력하시오");
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
		printf("이진탐색트리에 노드가 존재하지 않습니다.\n");
		return;
	}
	node* currentNode = head;

	printf("\n전위순회 : ");
	preorder(currentNode);
	
	printf("\n\n중위순회 : ");
	inorder(currentNode);

	printf("\n\n후위순회 : ");
	postorder(currentNode);
	printf("\n");
}

int findedChild = -1;	//삭제할 데이터의 노드의 차수(자식노드 개수)를 기록하는 변수, -1이면 삭제할 데이터를 가진 노드가 없음을 의미
node* findedNode;

void findChild(node* currentNode, int num) {	//삭제할 노드와 그 차수를 확인하는 함수
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
	if (findedChild == 0) {	//삭제하려는 노드가 단말 노드일 경우(차수가 0인 경우)
		if (findedNode == head) {
			head = NULL;
			free(findedNode);
			return;
		}
		deleteZeroDeg(currentNode, findedNode);
		free(findedNode);
	}
	else if (findedChild == 1) {	//삭제하려는 노드가 하나의 서브트리를 가진 경우(차수가 1인 경우)
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
	else if (findedChild == 2) {	//삭제하려는 노드가 두개의 서브트리를 가진 경우(차수가 2인 경우)
		deleteDoubleDeg(currentNode, findedNode);
	}
	else {
		printf("해당 데이터를 가진 노드를 찾을 수 없습니다.\n");
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
		printf("\n삭제할 데이터값을 입력하시오 : ");
		if (scanf_s("%d", &num) == 0) {
			printf("\n숫자만 입력하시오\n");
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
		printf("* 1.입력 2.출력 3.삭제 4.종료 *\n");
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
			delete();
			break;
		case 4:
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
