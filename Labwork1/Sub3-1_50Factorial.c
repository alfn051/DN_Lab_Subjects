#include <stdio.h>

void main(void) {
	int num;
	printf("숫자를 입력하시오 : ");
	scanf_s("%d", &num);
	
	int arr[159] = {0};
	arr[0] = 1;
	int size = sizeof(arr) / sizeof(arr[0]);

	for (int i = 0; i < num; i++) {
		for (int j = 0; j < size; j++) {
			arr[j] = arr[j] * (i+1);
		}
		for (int j = 0; j < size; j++) {
			if (j + 1 < size) {
				arr[j + 1] += arr[j] / 10;
				arr[j] = arr[j] % 10;
			}
		}
	}
	int startNum=0;
	for (int i = 0; i < size; i++) {
		if (arr[size-i-1] != 0) {
			startNum = i;
			break;
		}
	}

	for (int i = startNum; i < size; i++) {
		printf("%d", arr[size-i-1]);
	}
	return;
}