#include <iostream>
using namespace std;
#include "Rational Number.h"

RationalNumber::RationalNumber(int n, int d)
{
	numerator = n; // ����
	denominator = d; // �и�
	reduction(); 
}

RationalNumber RationalNumber::operator+(const RationalNumber& R) // + ������ �����ε� ����
{
	RationalNumber RN;
	RN.numerator = numerator * R.denominator + denominator * R.numerator; // �м��� �����̹Ƿ� ���ڴ� (��ü �ڽ��� ����*R�� �и�)+(R�� ����*��ü �ڽ��� �и�)�� �� ��
	RN.denominator = denominator * R.denominator; // �м��� �����̹Ƿ� �и�� (��ü �ڽ��� �и�*R�� �и�)
	RN.reduction();
	return RN;
}

RationalNumber RationalNumber::operator-(const RationalNumber& R) // - ������ �����ε� ����
{
	RationalNumber RN(numerator * R.denominator - denominator * R.numerator, denominator * R.denominator); 
	// �м��� �����̹Ƿ� ���ڴ� (��ü �ڽ��� ����*R�� �и�)-(R�� ����*��ü �ڽ��� �и�)�� �� ��
	// �м��� �����̹Ƿ� �и�� (��ü �ڽ��� �и�*R�� �и�)
	RN.reduction();
	return RN;
}

RationalNumber RationalNumber::operator*(const RationalNumber& R) // * ������ �����ε� ����
{
	RationalNumber RN;
	RN.numerator = numerator * R.numerator; // �м��� �����̹Ƿ� ���ڴ� (��ü �ڽ��� ����*R�� ����)
	RN.denominator = denominator * R.denominator; // �м��� �����̹Ƿ� �и�� (��ü �ڽ��� �и�*R�� �и�)
	RN.reduction();
	return RN;
}

RationalNumber RationalNumber::operator/(RationalNumber& R) // / ������ �����ε� ����
{
	RationalNumber RN;
	RN.numerator = numerator * R.denominator; // �м��� �������̹Ƿ� ���ڴ� (��ü �ڽ��� ����*R�� �и�)
	RN.denominator = denominator * R.numerator; // �м��� �������̹Ƿ� ���ڴ� (��ü �ڽ��� �и�*R�� ����)
	if (RN.denominator < 0 && RN.numerator < 0)
	{
		RN.denominator = -RN.denominator;
		RN.numerator = -RN.numerator;
	}
	RN.reduction(); 
	return RN;
}

bool RationalNumber::operator>(const RationalNumber& R) const // > ������ �����ε� ����
{
	return (double)numerator / (double)denominator > (double)R.numerator / (double)R.denominator ? 1 : 0;
}


bool RationalNumber::operator<(const RationalNumber& R) const // < ������ �����ε� ����
{
	return (double)numerator / (double)denominator < (double)R.numerator / (double)R.denominator ? 1 : 0;
}

bool RationalNumber::operator>=(const RationalNumber& R) const // >= ������ �����ε� ����
{
	return (double)numerator / (double)denominator >= (double)R.numerator / (double)R.denominator ? 1 : 0;
}

bool RationalNumber::operator<=(const RationalNumber& R) const // <= ������ �����ε� ����
{
	return (double)numerator / (double)denominator <= (double)R.numerator / (double)R.denominator ? 1 : 0;
}

bool RationalNumber::operator==(const RationalNumber& R) const // == ������ �����ε� ����
{
	return (double)numerator / (double)denominator == (double)R.numerator / (double)R.denominator ? 1 : 0;
}

bool RationalNumber::operator!=(const RationalNumber& R) const // != ������ �����ε� ����
{
	return (double)numerator / (double)denominator != (double)R.numerator / (double)R.denominator ? 1 : 0;
}

void RationalNumber::reduction() // ���м��� ����� �Լ� ����
{
	if (denominator == 0 || denominator < 0) // �и� �����̰ų� 0�̸� ���� �߻� ���� ��� �� exit��
	{
		cout << "�и� �����̰ų� 0�� �� �� �����ϴ�." << endl;
		exit(1);
	}

	if (numerator < 0)
	{
		numerator = -numerator;
		if (numerator >= denominator)
		{
			int max = denominator;
			for (int i = max; i > 1; i--) {
				if (numerator % i == 0 && denominator % i == 0)
				{
					numerator /= i;
					denominator /= i;
				}
			}
		}
		else
		{
			int max = numerator;
			for (int i = max; i > 1; i--) {
				if (numerator % i == 0 && denominator % i == 0)
				{
					numerator /= i;
					denominator /= i;
				}
			}
		}
		numerator = -numerator;
	}
	else
	{
		if (numerator >= denominator)
		{
			int max = denominator;
			for (int i = max; i > 1; i--) {
				if (numerator % i == 0 && denominator % i == 0)
				{
					numerator /= i;
					denominator /= i;
					return;
				}
			}
		}
		else
		{
			int max = numerator;
			for (int i = max; i > 1; i--) {
				if (numerator % i == 0 && denominator % i == 0)
				{
					numerator /= i;
					denominator /= i;
					return;
				}
			}
		}
	}
}

void RationalNumber::printRational() const
{
	if (numerator == 0) // ���࿡ ���ڰ� 0�̸� �ش� �м��� 0�� ���̹Ƿ� 0�� ����ϰ� �Ѵ�.
	{
		cout << numerator << endl; // 0�� ���
		return;
	}
	else if (numerator == denominator) // ���࿡ ���ڿ� �и� �����ϸ� 1�� ���̹Ƿ�
	{
		cout << numerator / denominator << endl; // 1�� ����Ѵ�.
		return;
	}
	else if (denominator == 1) // �и� 1�̸� ���ڸ� ����Ѵ�
	{
		cout << numerator << endl; // ���ڸ� ���
		return;
	}
	cout << numerator << "/" << denominator << endl; // ���࿡ ���ڰ� 0�� �ƴϰ� ���ڿ� �и� ������ �͵� �ƴϸ� ���� / �и� ����Ѵ�.
}