#include <stdio.h>
#define SIZE 159

int arr[SIZE] = { 0 };

int factorial(int num) {
	if (num == 0) {
		return 1;
	}
	else {
		for (int i = 0; i < SIZE; i++) {
			arr[i] = arr[i] * num;
		}
		for (int i = 0; i < SIZE; i++) {
			if (i + 1 < SIZE) {
				arr[i + 1] += arr[i] / 10;
				arr[i] = arr[i] % 10;
			}
		}
		return factorial(num - 1);
	}
}
void main(void) {
	int num;
	printf("숫자를 입력하시오 : ");
	scanf_s("%d", &num);
	arr[0] = 1;
	factorial(num);
	int startNum=0;
	for (int i = 0; i < SIZE; i++) {
		if (arr[SIZE - i - 1] != 0) { 
			startNum = i;
			break;
		}
	}
	for (int i = startNum; i < SIZE; i++) {
		printf("%d", arr[SIZE - i - 1]);
	}
	return;
}