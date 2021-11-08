#include "Complex.h" // Complex Ŭ������ �̿��ϱ� ���� ������� include
#include <iostream>

using namespace std;

int main()
{
	Complex c1(1, 7); // Complex ��ü c1�� �����ϴ� ���ÿ� �����ڸ� �̿��� �Ǽ��θ� 1, ����θ� 7�� �ʱ�ȭ
	Complex c2(9, 2); // Complex ��ü c2�� �����ϴ� ���ÿ� �����ڸ� �̿��� �Ǽ��θ� 9, ����θ� 2�� �ʱ�ȭ
	Complex c3(10, 1); // Complex ��ü c3�� �����ϴ� ���ÿ� �����ڸ� �̿��� �Ǽ��θ� 10, ����θ� 1�� �ʱ�ȭ
	Complex c4(11, 5); // Complex ��ü c4�� �����ϴ� ���ÿ� �����ڸ� �̿��� �Ǽ��θ� 11, ����θ� 5�� �ʱ�ȭ

	c1.print(); // print ��� �Լ��� �̿��� c1�� ��� 
	cout << " + ";
	c2.print(); // print ��� �Լ��� �̿��� c2�� ��� 
	cout << " = ";
	c1.add(c2); // add ��� �Լ��� �̿��� c1���� c2�� ����
	c1.print(); // add �Լ��� ����� ���� ���� c1�� �ٽ� print�Լ��� �̿��� ���

	cout << endl;

	c3.print(); // print ��� �Լ��� �̿��� c3�� ��� 
	cout << " - ";
	c4.print(); // print ��� �Լ��� �̿��� c4�� ��� 
	cout << " = ";
	c3.sub(c4); // sub ��� �Լ��� �̿��� c3���� c4�� ��
	c3.print(); // add �Լ��� ����� ���� ���� c3�� �ٽ� print�Լ��� �̿��� ���

	return 0;
}