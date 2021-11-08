#include<iostream>
#include<string>
using namespace std;

#include "Ex3-12.h" // ��������� include ����

Date::Date(int m, int d, int y){ // ������ ����
	setMonth(m); // setMonth�Լ��� �̿��Ͽ� month ��������� �Էµ� m�� ������ �ʱ�ȭ
	setDay(d); // setDay�Լ��� �̿��Ͽ� day ��������� �Էµ� d�� ������ �ʱ�ȭ
	setYear(y); // setYear�Լ��� �̿��Ͽ� year ��������� �Էµ� y�� ������ �ʱ�ȭ
}

void Date::setMonth(int m){  // Date Ŭ������ ����Լ��� setMonth�� ����
	if (m < 1 || m > 12) // m�� 1���� �۰ų�, 12���� ũ��
	{
		month = 0; // month�� 0�� �����Ѵ�.
		return;
	}
	month = m; // if���� ������Ű�� ������, 1�� 12 ������ ���� ������ ���̹Ƿ� ���� �Էµ� ���� m�� �����Ѵ�.
}

int Date::getMonth(){ // Date Ŭ������ ����Լ��� getMonth�� ����
	return month; // getMonth�� month ��� ������ ��ȯ�ϴ� �Լ��̹Ƿ� month�� return���ش�.
}

void Date::setDay(int d){ // Date Ŭ������ ����Լ��� setDay�� ����
	day = d; // setDay�� day ���� �Է��� ������ ���Ҵ� �ϴ� �Լ��̹Ƿ� day�� d�� �����Ѵ�.
}

int Date::getDay() { // Date Ŭ������ ����Լ��� getDay�� ����
	return day; // getDay�� day ��� ������ ��ȯ�ϴ� �Լ��̹Ƿ� day�� return���ش�.
}

void Date::setYear(int y) { // Date Ŭ������ ����Լ��� setYear�� ����
	year = y; // setYear�� year ���� �Է��� ������ ���Ҵ� �ϴ� �Լ��̹Ƿ� year�� y�� �����Ѵ�.
}

int Date::getYear() { // Date Ŭ������ ����Լ��� getYear�� ����
	return year; // getYear�� year ��� ������ ��ȯ�ϴ� �Լ��̹Ƿ� year�� return���ش�.
}

void Date::displayDate() { // Date Ŭ������ ����Լ��� dispalyDate�Լ��� ����
	cout << getMonth() << "/" << getDay() << "/" << getYear() << endl;
} // dispalyDate �Լ��� month, day, year ������ /�� ������ ����ϴ� �Լ��̴�. month, day, year ������ �ٷ� �ҷ��� �� �����Ƿ� get�Լ��� �̿��� ��ȯ ���� ����Ѵ�.