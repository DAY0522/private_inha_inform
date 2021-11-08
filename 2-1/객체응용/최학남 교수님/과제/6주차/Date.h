#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

#ifndef DATE_H
#define DATE_H

class Date
{
public:
	Date(); // Date�� default constructor ����
	Date(int, int); // �� ���� int�� ������ parameter�� �޴� constructor ����
	Date(int, int, int); // �� ���� int�� ������ parameter�� �޴� constructor ����
	Date(string, int, int); // �ϳ��� string�� ������ �� ���� int�� ������ parameter�� �޴� constructor ����
	void setDay(int); // day�� ���� �Ҵ����ִ� setDay �Լ� ����
	void setMonth(int); // month�� ���� �Ҵ����ִ� setDay �Լ� ����
	void setYear(int); // year�� ���� �Ҵ����ִ� setDay �Լ� ����
	void print() const; // print data in month/day/year format
	void printDDDYYYY() const; // print data in ddd yyyy format  
	void printMMDDYY() const; // print data  in mm/dd/yy format
	void printMonthDDYYYY() const; // print data in Month dd, yyyy format
private:
	int year; // '�⵵'�� ��Ÿ���� year ����
	int month; // '��'�� ��Ÿ���� month ����
	int day; // '��'�� ��Ÿ���� day ����

	int checkDay(int) const; // day�� ������ ������ Ȯ�����ִ� �Լ�
	int checkMonth(int) const;  // month�� ������ ������ Ȯ�����ִ� �Լ�
	int checkYear(int) const;  // year�� ������ ������ Ȯ�����ִ� �Լ�
	int daysInMonth(int) const; // parameter�� �Էµ� '��'�� ������ '��'�� ��ȯ�ϴ� �Լ�
	bool isLeapYear() const; // �������� Ȯ�����ִ� �Լ�
	int convertDDToDDD() const; // MM. DD���¸� DDD���·� �ٲ��ִ� �Լ�
	void setMMDDFromDDD(int); // DDD���¸� MM, DD�� ��ȯ���ִ� �Լ�
	string convertMMToMonth(int) const; // MM���� ǥ���� '��'�� string���� �ٲ��ִ� �Լ�
	void setMMFromMonth(string); // string���� ǥ���� month�� int������ �ٲ��ִ� �Լ�
	int convertYYYYToYY() const; // YYYY���·� ǥ���� year�� YY���·� �ٲ��ִ� �Լ�
	void setYYYYFromYY(int); // YY ���·� ǥ���� year�� YYYY���·� �ٲ��ִ� �Լ�
};

#endif