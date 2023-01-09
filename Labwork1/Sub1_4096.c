#include <stdio.h>

void main(void)
{
	
	for (int num1 = 0; num1 < 8; num1++) {
		for (int num2 = 0; num2 < 8; num2++) {
			for (int num3 = 0; num3 < 8; num3++) {
				for (int num4 = 1; num4 <= 8; num4++) {
					printf("%4d ", num4 + (num3 * 64) + (num2 * 8) + (num1 * 512));
				}
				printf(" ");
			}
			printf("\n");
		}
		printf("\n");
	}

	return;
}