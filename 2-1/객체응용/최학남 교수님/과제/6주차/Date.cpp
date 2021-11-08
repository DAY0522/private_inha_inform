#define _CRT_SECURE_NO_WARNINGS
#include "Date.h" // Date header���� include
#include<iostream>
#include<ctime> // time, time_t, tm ���� �̿��� ���� ��¥�� �ҷ����� ���� ctime ���̺귯�� �̿�
#include<iomanip> // setfill, setw�� �̿��ϱ� ���� iomanip ���̺귯�� �̿�
using namespace std;

const string strmonth[13] = { "\n0","January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };
// '�⵵'�� string���� �����ϰ� �ִ� strmonth �迭 ����
const int daysPerMonth[13] = { 0,31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
// '��'�� ������ ��¥�� �����ϰ� �ִ� daysPerMonth �迭 ����

Date::Date() // default ������ ����
{
	time_t currentDay= time(0); // time()�Լ��� ���� ���� �ð��� ��ȯ�ް� time_t�� currentDay������ �Ҵ�
	tm* localDay = localtime(&currentDay); // localtime �Լ��� ���� currentDay�� ��, ��, �� ���� ���ؿ� ���� ��ȯ
	setYear(localDay->tm_year + 1900); // localDay�� tm_year�� ������ ���� '�⵵'�� �θ�. �ش� �⵵�� 1900����� �����ϹǷ� 1900�� ������ ���� year ������ �Ҵ�
	setMonth(localDay->tm_mon + 1); // localDay�� tm_mon�� ������ ���� '��'�� �ҷ��´�. �ش� ���� 1��=0, 12��=11�̹Ƿ� 1�� ������ ���� month ������ �Ҵ�
	setDay(localDay->tm_mday); // localDay�� tm_mday�� ������ ���� '��'�� �ҷ��� day������ �Ҵ� 
}

Date::Date(int ddd, int yyyy) // using ddd yyyy format
{
	setYear(yyyy); // setYear�Լ��� ���� year�� yyyy�� �Ҵ�
	setMMDDFromDDD(ddd); 
}

Date::Date(int dd, int mm, int yyyy) // using dd/mm/yyyy format
{
	setYear(yyyy); // setYear�Լ��� ���� year�� yyyy�� �Ҵ�
	setMonth(mm); // setMonth�Լ��� ���� month�� mm�� �Ҵ�
	setDay(dd); // setDay�Լ��� ���� day�� dd�� �Ҵ�
}

Date::Date(string month, int dd, int yyyy) // using Month dd, yyyy format
{
	setYear(yyyy); // setYear�Լ��� ���� year�� yyyy�� �Ҵ�
	setMMFromMonth(month); // 
	setDay(dd); // setDay�Լ��� ���� day�� dd�� �Ҵ�
}

void Date::setDay(int d)
{
	day = checkDay(d); // �Էµ� d�� ���� ��ȿ�� �˻� ����
}

void Date::setMonth(int m)
{
	month = checkMonth(m); // �Էµ� m�� ���� ��ȿ�� �˻� ����
}

void Date::setYear(int y)
{
	year = checkYear(y); // �Էµ� y�� ���� ��ȿ�� �˻� ����
}

void Date::print() const 
{
	cout << setfill('0') << setw(2) << this->month << '/' << setfill('0') << setw(2) << this->day << '/' << this->year;
	// setw�� ���� 2�ڸ��� Ȯ���� �� month, day�� 2�ڸ��� �ƴ� ���� �ش� �ڸ��� setfill�� �̿��� 0�� ����, year�� �״�� ���
}

void Date::printDDDYYYY() const // �Էµ� year, month, day�� ���� 
{
	cout << convertDDToDDD() << " " << year; // month�� day�� ddd���·� ��ȯ���ִ� convertDDToDDD�Լ��� ��ȯ���� year�� ���
}

void Date::printMMDDYY() const // �Էµ� year, month, day�� ���� ��, ��, �⵵(�ڿ� 2�ڸ�)�� ������ִ� �Լ�
{
	cout << setfill('0')<<setw(2)<< month << "/" << // setw�� ���� 2�ڸ��� Ȯ���� �� month, day�� 2�ڸ��� �ƴ� ���� �ش� �ڸ��� setfill�� �̿��� 0�� ����
		setfill('0') << setw(2) << day << "/" << convertYYYYToYY(); // month�� day�� �״�� ����ϰ�, year�� yyyy���·� ǥ���� �����Ƿ� convertYYYYToYY�Լ��� �̿��� yy���·� ��ȯ
}

void Date::printMonthDDYYYY() const // �Էµ� year, month, day�� ���� ��(string), ��, �⵵�� ������ִ� �Լ�
{
	cout << convertMMToMonth(month) << ", " << day << ", " << year; // month�� convertMMToMonth�Լ��� �̿��� string���� ��ȯ���� ���� ���, day, year�� �״�� ����Ѵ�
}

int Date::checkDay(int d) const // d�� ��ȿ�� �˻�
{
	if (d > 0 && d <= daysInMonth(month)) // d�� 0���� ũ�ų� �ش� ���� ������ ��¥���� �۰ų� ������ ��ȿ�� ���̹Ƿ�
		return d; // d�� �״�� ��ȯ
	else // �̸� �����ϸ� ��ȿ���� ���� ���̹Ƿ�
		cout << "Invalid day (" << d << ") set to 1.\n"; // �����޽��� ���
	return 1; // 1�� ��ȯ
}

int Date::checkMonth(int m) const // m�� ��ȿ�� �˻�
{
	if (m > 0 && m <= 12) // m�� 1~12 ������ ���� �ƴϸ�
		return m; // m�� ��ȯ
	else // 1~12 ������ ���� �ƴϸ� �߸��� ���̹Ƿ�
		cout << "Invalid month (" << m << ") set to 1.\n"; // �߸��ƴٴ� ������ ���
	return 1; // 1��ȯ
}

int Date::checkYear(int y) const // y�� ��ȿ�� �˻�
{
	if (y >= 0) // y�� 0���� ũ�ų� ������ ��ȿ�� ���̹Ƿ� 
		return y; // y�� ��ȯ
	else // y�� 0���� ������ ��ȿ�� ���� �ƴϹǷ�
		cout << "Invalid year (" << y << ") set to 1900.\n"; // �߸��� ���̶�� �޽����� ���
	return 1900; // 1900�� ��ȯ
}

int Date::daysInMonth(int mm) const // mm���� ������ ��¥�� ��ȯ�ϴ� �Լ�
{
	if (mm <= 0 || mm > 12) // mm�� 1�� 12 ���� ���� �ƴϸ� �߸��� ���̹Ƿ�
	{
		return -1; // -1 ��ȯ
	}
	if (mm == 2) // mm�� 2�̸� �������� Ȯ���� �������
	{
		if (isLeapYear()) // isLeapYear�� 1�̸� ������ ���̹Ƿ�
		{
			return 29; // 29�� ��ȯ
		}
		return 28; // ������ �ƴϸ� 28�� ��ȯ
	}
	return daysPerMonth[mm]; // 1~12������ ���ε� 2�� �ƴϸ� daysPerMonth�� �Էµ� mm��° ���� ��ȯ
}

bool Date::isLeapYear() const // �����ΰ�?
{
	return (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
	// �ش� �⵵�� 400���� ������ �������ų�, 4�� ������ �������� 100���� ������ �������� ������ �����̹Ƿ� 1�� ��ȯ, �ƴϸ� 0�� ��ȯ�ϰ� ��
}

int Date::convertDDToDDD() const // mm, dd�� ǥ���� '��', '��'�� ddd�� �������ִ� �Լ�
{
	int ddd = 0; // ddd�� ���������� �����ϰ� 0���� �ʱ�ȭ
	for (int i = 1; i < month; i++) // i�� 1���� month-1���� for loop�� ����
	{
		ddd += daysInMonth(i); // i���� ������ ���� ddd�� �����ش�
	}
	ddd += day; // �׸��� ddd�� day�� �����ش�.
	return ddd; // ddd�� return
}

void Date::setMMDDFromDDD(int ddd) // ddd�� ǥ���� '��'��, '��'�� '��'�� �ٲ� ǥ�����ִ� �Լ�
{
	int m = 1; // �������� m�� ������ �� 1�� �ʱ�ȭ
	while (ddd > daysInMonth(m)) // ddd�� m�� ������ �Ϻ��� ũ�� ���� ���� �� �� �ִ� ���̹Ƿ�(�� �Ǹ� ���� ���� �� �� �����Ƿ� while���� ����)
	{
		ddd -= daysInMonth(m); // ddd�� m�� ������ �Ϸ� ���ְ�
		m++; // m�� 1 ����
	}
	month = m; // month�� m�� �Ҵ�
	day = ddd; // day�� ddd�� �Ҵ�
}

string Date::convertMMToMonth(int m) const // ���ڷ� �Էµ� '��'�� ���ڿ��� �ٲ��ִ� �Լ�
{
	return strmonth[m]; // m�� ���ڿ��� ǥ���� strmonth[m]�� ��ȯ
}

void Date::setMMFromMonth(string m) // string���� ǥ���� '��'�� ���ڷ� �ٲٴ� �Լ�
{
	for (int i = 1; i <= 12; i++) // for���� ���� ������ ������ strmonth�� �Էµ� string���� ǥ���� ���ڿ��� ���� �� ��ġ�ϸ� strmonth�� index ��ȯ
	{
		if (m == strmonth[i]) // string���� �Է��� ��(m)�� strmonth�� ���� �� ��ġ�ϸ�
		{
			month = i; // index �� ��ȯ(i�� m�� ���ڷ� ǥ���� ���� ��)
		}
	}
}

int Date::convertYYYYToYY() const // yyyy�� ǥ���� �⵵�� yy�� �ٲٴ� �Լ�
{
	return year % 100; // ���� �ڸ�, ���� �ڸ��� �ҷ����� �ǹǷ� 100���� ���� �������� �ҷ��´�.
}

void Date::setYYYYFromYY(int yy) // yy���¸� yyyy���·� �ٲ��ִ� �Լ�
{
	if (yy >= 0 || yy < 100) // 1951~2050������� ���� ��ȯ�Ѵٰ� ��������.
		year = (yy > 50 ? 1900 : 2000) + yy; // yy���� 0~50�̸� 2000�� ���� 2000~2050����, 51~99�̸� 1900�� ���� 1951~1999�� year�� �Ҵ�
	else {
		cout << "Invalid year (" << yy << ") sets to 1900." << std::endl; // 0~99������ ���� �ƴ϶�� ����� ���̶�� ������ ����ϰ� 1900������ �������ش�.
		year = 1900;
	}
}
