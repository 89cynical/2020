#include "main.h"

int main() {
	int stick = 64, x, num = 0;
	do{
		scanf_s("%d", &x);
		if (x > 64) {
			printf("64 ������ �ڿ����� �Է����ֽʽÿ�.\n");
		}
	} while (x > 64);
	while (x) {
		while (stick > x) {
			stick /= 2;
		}
		x = x - stick;
		num++;
	}
	printf("%d\n", num);
	return 0;
}