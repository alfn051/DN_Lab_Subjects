	#include <stdio.h>
void main(void) {
	
	int num;
	printf("���ڸ� �Է��Ͻÿ� : ");
	scanf_s("%d", &num);

	if (num % 2 == 0) {
		for (int i = 0; i < num-1; i++) {
			if (i * 2 <= num-2) {
				for (int j = 0; j < num/2-1-i; j++) { printf(" "); }
				for (int j = 0; j <(i+1)*2; j++) { printf("*"); }
			}
			else {
				for (int j = 0; j < i - (num - 1) / 2; j++) { printf(" "); }
				for (int j = 0; j < (num-i-1)*2; j++) { printf("*"); }
			}
			printf("\n");
		}
	}
	else {
		for (int i = 0; i < num; i++) {
			if (i * 2 <= num) {
				for (int j = 0; j < (num/2-i); j++) {printf(" ");}
				for (int j = 0; j < i * 2 + 1; j++) {printf("*");}
			}
			else {
				for (int j = 0; j < i-(num-1)/2; j++) { printf(" ");}
				for (int j = 0; j < (num - i) * 2 -1; j++) {printf("*");}
			}
			printf("\n");
		}
	}

}