#include<stdio.h>

int main(void)
{
	char x, x1, x2, x3; // char�� ���� -128~127
	unsigned char y; // unsigned char�� ���� 0~256
	x = -128;
	x1 = x - 1;
	x2 = x - 2;
	x3 = x - 3;
	printf("%d\n", x1);
	printf("%d\n", x - 1); // �̰� overflow �߻����� ����. �׳� a-1�� ���� 4byte�� ����ϴ� ����.
	printf("%d\n", x2);
	printf("%d\n", x3);

	y = 256;
	printf("%u\n", y);
	printf("%u\n", y + 1);
	printf("%u\n", y + 2);

	return 0;
}