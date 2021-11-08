#include<iostream>
#include<string>
using namespace std;

class Date // Date Ŭ������ ����
{
public: // �� ��� �Լ��� public���� ����
	Date(int m, int d, int y); // �Էµ� m, d, y�� ���� ��� ������ �ʱ�ȭ �ϴ� ������ �������̽� ����
	void setMonth(int m); // month ������ ���� �Ҵ��ϱ� ���� set�Լ� �������̽� ����
	int getMonth(); // month������ ���� �ҷ����� ���� get�Լ� �������̽� ����
	void setDay(int d); // day ������ ���� �Ҵ��ϱ� ���� set�Լ� �������̽� ����
	int getDay(); // day������ ���� �ҷ����� ���� get�Լ� �������̽� ����
	void setYear(int y); // year ������ ���� �Ҵ��ϱ� ���� set�Լ� �������̽� ����
	int getYear(); // year������ ���� �ҷ����� ���� get�Լ� �������̽� ����
	void displayDate(); // month/day/year�� ����ϴ� �Լ� �������̽� ����
private: // �� ��� ������ private�� ����
	int month; // month ������ int������ ����
	int day; // day ������ int������ ����
	int year; // year ������ int������ ����
};