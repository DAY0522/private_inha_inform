#include<iostream>
using namespace std;

#include "Ex3-12.h"

int main()
{
	Date date(5, 6, 1981); // �����ڸ� �̿��� DateŬ������ ��ü date�� �ʱ�ȭ

	cout << "Month : " << date.getMonth() << endl 
		<< "Day : " << date.getDay() << endl
		<< "Year : " << date.getYear() << endl;
	// date ��ü�� ����Լ��� getMonth, getDay, getYear�� �̿��� month, day, year���� ���
	
	cout << "\nOriginal date : " << endl;
	date.displayDate(); // date��ü�� ����Լ��� displayDate�� �̿��� ��,��,�⵵�� ��� 

	date.setMonth(1); // setMonth �Լ��� �̿��� date�� month ��� ������ 1�� �ʱ�ȭ
	date.setDay(1); // setDay �Լ��� �̿��� date�� day ��� ������ 1�� �ʱ�ȭ
	date.setYear(2005); // setYear �Լ��� �̿��� date�� year ��� ������ 2005�� �ʱ�ȭ
	
	cout << "\nNew date : " << endl;
	date.displayDate(); // date��ü�� ����Լ��� displayDate�� �̿��� ���Ӱ� �Ҵ�� ��,��,�⵵�� ��� 

	return 0;
}