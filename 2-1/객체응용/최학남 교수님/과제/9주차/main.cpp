#include <iostream>
using namespace std;
#include "Rational Number.h"

int main()
{
	RationalNumber rn(1, 3); // Rational class�� rn�� ����
	RationalNumber rn2(3, 4); // Rational class�� rn�� ����
	RationalNumber rn3; // Rational class�� rn�� ����

	rn3 = rn + rn2; // + ������ �����ε��� �̿��� RationalNumber class(rn, rn2)�� ���� ����
	rn3.printRational();

	rn3 = rn - rn2; // - ������ �����ε��� �̿��� RationalNumber class(rn, rn2)�� ���� ��
	rn3.printRational();

	rn3 = rn * rn2; // * ������ �����ε��� �̿��� RationalNumber class(rn, rn2)�� ���� ����
	rn3.printRational();

	rn3 = rn / rn2; // / ������ �����ε��� �̿��� RationalNumber class(rn, rn2)�� ���� ����
	rn3.printRational();

	cout << "rn > rn2 ? ";
	if (rn > rn2) cout << "true" << endl; // > ������ �����ε��� �̿��� RationalNumber class(rn, rn2)�� ���� ��(rn>rn2�ΰ�?)
	else cout << "false" << endl;

	cout << "rn < rn2 ? ";
	if (rn < rn2) cout << "true" << endl; // < ������ �����ε��� �̿��� RationalNumber class(rn, rn2)�� ���� ��(rn<rn2�ΰ�?)
	else cout << "false" << endl;

	cout << "rn >= rn2 ? ";
	if (rn >= rn2) cout << "true" << endl; // >= ������ �����ε��� �̿��� RationalNumber class(rn, rn2)�� ���� ��(rn>=rn2�ΰ�?)
	else cout << "false" << endl;

	cout << "rn <= rn2 ? ";
	if (rn <= rn2) cout << "true" << endl; // <= ������ �����ε��� �̿��� RationalNumber class(rn, rn2)�� ���� ��(rn<=rn2�ΰ�?)
	else cout << "false" << endl;

	cout << "rn == rn2 ? ";
	if (rn == rn2) cout << "true" << endl; // == ������ �����ε��� �̿��� RationalNumber class(rn, rn2)�� ���� ��(rn==rn2�ΰ�?)
	else cout << "false" << endl;

	cout << "rn != rn2 ? ";
	if (rn != rn2) cout << "true" << endl; // != ������ �����ε��� �̿��� RationalNumber class(rn, rn2)�� ���� ��(rn!=rn2�ΰ�?)
	else cout << "false" << endl;

	return 0;
}