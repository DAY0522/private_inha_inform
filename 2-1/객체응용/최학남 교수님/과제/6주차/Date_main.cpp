#include <iostream>
#include "Date.h"

using namespace std;

int main()
{
	Date d1; // d1�� �⺻ �����ڷ� ����
	Date d2(142, 2021); // d2�� ������ �� ddd, yyyy���·� �����ڸ� ���� �ʱ�ȭ
	Date d3(22, 5, 2021); // d3�� ������ �� dd, m, yyyy���·� �����ڸ� ���� �ʱ�ȭ
	Date d4("May", 22, 2021); // d4�� ������ �� month(string), dd, yyyy���·� �����ڸ� ���� �ʱ�ȭ

	d1.print(); // d1�� mm/dd/yyyy���·� ���
	cout << endl; 

	d2.printDDDYYYY(); // d2�� ddd/yyyy���·� ���
	cout << endl; 

	d3.printMMDDYY(); // d3�� mm/dd/yy���·� ���
	cout << endl; 

	d4.printMonthDDYYYY(); // d4�� month(string), dd, yyyy���·� ��� 
	cout << endl;


	return 0;
}