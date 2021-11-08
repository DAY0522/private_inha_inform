#include "Rational.h" // Complex Ŭ������ �̿��ϱ� ���� ������� include
#include <iostream>

using namespace std;

int main()
{
	Rational R1(2, 6); // Rational class�� ��ü�� R1�� �����ϰ� ��� ������ 2, 6���� �ʱ�ȭ
	Rational R2(21, 24); // Rational class�� ��ü�� R2�� �����ϰ� ��� ������ 21, 24���� �ʱ�ȭ
	Rational R3; // Rational class�� ��ü�� R3�� ����, �ʱ�ȭ ���� �Է������� �ʾ����Ƿ� ����Ʈ ���ڿ� ���� ���ڴ� 0, �и�� 1�� ��

	R1.print_fract(); // R1�� �м� ���·� ���
	cout << " + ";
	R2.print_fract(); // R2�� �м� ���·� ���
	cout << " = ";
	R3.add(R1,R2); // R1�� R2�� ���� ���� R3�� ����
	R3.print_fract(); // R3�� �м� ���·� ���
	cout << endl;
	R3.print_fract(); // R3�� �м� ���·� ���
	cout << " = ";
	R3.print_float(); // R3�� �Ҽ� ���·� ���

	cout << endl << endl;


	R1.print_fract(); // R1�� �м� ���·� ���
	cout << " - ";
	R2.print_fract(); // R2�� �м� ���·� ���
	cout << " = ";
	R3.sub(R1,R2); // R1���� R2�� �� ���� R3�� ����
	R3.print_fract(); // R3�� �м� ���·� ���
	cout << endl;
	R3.print_fract(); // R3�� �м� ���·� ���
	cout << " = ";
	R3.print_float(); // R3�� �Ҽ� ���·� ���

	cout << endl << endl;


	R1.print_fract(); // R1�� �м� ���·� ���
	cout << " x ";
	R2.print_fract(); // R2�� �м� ���·� ���
	cout << " = ";
	R3.mul(R1,R2); // R1�� R2�� ���� ���� R3�� ����
	R3.print_fract(); // R3�� �м� ���·� ���
	cout << endl;
	R3.print_fract(); // R3�� �м� ���·� ���
	cout << " = ";
	R3.print_float(); // R3�� �Ҽ� ���·� ���

	cout << endl << endl;


	R1.print_fract(); // R1�� �м� ���·� ���
	cout << " / ";
	R2.print_fract(); // R2�� �м� ���·� ���
	cout << " = ";
	R3.div(R1,R2); // R1���� R2�� ���� ���� R3�� ����
	R3.print_fract(); // R3�� �м� ���·� ���
	cout << endl;
	R3.print_fract(); // R3�� �м� ���·� ���
	cout << " = ";
	R3.print_float(); // R3�� �Ҽ� ���·� ���

	cout << endl << endl;

	return 0;
}