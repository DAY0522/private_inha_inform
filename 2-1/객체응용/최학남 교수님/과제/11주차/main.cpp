#include<iostream>
using namespace std;

#include "Account.h"

int main()
{
	Account ac(10000); // Account class ���� ����(�����ڸ� �̿��� balance�� 10000���� �ʱ�ȭ)
	cout << "Account : " << endl;
	cout << "���� �ܰ� - ";
	ac.print();
	ac.credit(10000); // 10000���� �Ա�
	cout << "�Ա� �� - ";
	ac.print();
	ac.debit(5000); // 5000���� ���
	cout << "��� �� - ";
	ac.print();
	cout << endl;

	SavingAccount sa(ac.get(), 0.1); // SavingAccount class ���� ����(�����ڸ� �̿��� balance�� ac ������ �����ϰ� �ʱ�ȭ, �������� 0.1�� �ʱ�ȭ)
	cout << "SavingAccount : " << endl;
	cout << "���� �ܰ� - ";
	sa.print();
	cout << "interest - " << sa.CalculateInterest() << endl; // ���� �ܰ��� ���¿� ������ ���ڸ� ���
	ac.credit(int(sa.CalculateInterest())); // ���ڸ� ���� ���� �ܰ� ����
	cout << "���� �Ա� �� - ";
	sa.print();
	cout << endl;

	CheckingAccount ca(ac.get(), 1000); // CheckingAccount class ���� ����(�����ڸ� �̿��� balance�� ac ������ �����ϰ� �ʱ�ȭ, ������� 1000���� �ʱ�ȭ)
	cout << "CheckingAccount : " << endl;
	cout << "���� �ܰ� - "; 
	ca.print();
	ca.credit(10000); // 10000���� �Ա�(������ ���)
	cout << "�Ա� �� - "; 
	ca.print();
	ca.debit(5000); // 5000���� ���(������ ���)
	cout << "��� �� - "; 
	ca.print();
	cout << endl;

	return 0;
}