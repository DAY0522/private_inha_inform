#include<iostream>
#include<iomanip>
using namespace std;

int main_6_1()
{
	float x = 1.234567890123456789;
	double y = 1.234567890123456789;

	//printf("size of float = %d\n", sizeof(float));
	//printf("size of float = %d\n", sizeof(double));

	cout << fixed;
	cout.precision(25); // �Ҽ��� 2��° �ڸ����� ����
	cout << "x = " << setw(30) << x << endl;
	//printf("x = %30.25\n", x);

	cout << fixed;
	cout.precision(25); // �Ҽ��� 2��° �ڸ����� ����
	cout << "y = " << setw(30) << y << endl;
	//printf("y = %30.25\n", y);

	//setw�� �ڸ� ũ�� ������Ű�� ��
	//fixed, precision�� �Ҽ��� �ڸ��� �����ϴ� ��


	return 0;
}