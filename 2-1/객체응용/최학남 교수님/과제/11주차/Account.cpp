#include<iostream>
using namespace std;

#include"Account.h"

Account::Account(int b)
{
	// ���� �ܰ��� ��ȿ�� �˻�
	if (b >= 0) // ���� �ܰ� 0���� ũ�ų� ������ ��ȿ�� ��
	{
		balance = b; // �Էµ� ���� balance�� �Ҵ�
	}
	else  // ���� �ܰ� 0���� ������ ��ȿ���� ���� ��
	{
		balance = 0; // ��ȿ���� ���� ���̹Ƿ� �ܰ� 0���� �ʱ�ȭ
		cout << "�Էµ� ���� ��ȿ���� ���� ���̹Ƿ� 0���� �ʱ�ȭ �մϴ�." << endl;
	}
}

void Account::credit(int m)
{
	balance += m; // �Էµ� ���ڸ�ŭ ���� �ܰ� ����
}

void Account::debit(int m)
{
	// ���� �ܰ��� ��ȿ�� �˻�
	if (balance >= m) // ����Ϸ��� ���� ���� �ܰ��� ũ�� ��ȿ�� ��
	{
		balance -= m; // �Էµ� ���ڸ�ŭ ���� �ܰ��� ��
	}
	else // ����Ϸ��� ���� ���� �ܰ��� ������ ��ȿ�� ��
	{
		cout << "�ܰ� �����մϴ�." << endl;  // ���� �޽��� ���
	}
}

int Account::get(void) const 
{
	return balance; // ���� �ܰ� ��ȯ
}

void Account::set(int& b)
{
	balance = b; // �Էµ� ���ڸ� balance�� �Ҵ�
}

void Account::print()
{
	cout << balance << endl; // ���� �ܰ� ���
}


SavingAccount::SavingAccount(int b, double i)
	: Account(b)
{
	// ������ ��ȿ�� �˻�
	if (i >= 0) // ���ڰ� 0���� ũ�ų� ������ ��ȿ�� ��
	{
		interestrate = i; // �Էµ� i�� interestrate�� �Ҵ�
	}
	else // ���ڰ� 0���� ������ ��ȿ���� ���� ����
	{
		interestrate = 0; 
		cout << "�Էµ� ���� ��ȿ���� ���� ���̹Ƿ� 0���� �ʱ�ȭ �մϴ�." << endl;
	}
}

double SavingAccount::CalculateInterest()
{
	return interestrate * double(get()); // ���ڸ� ����� ���� �ܰ�
}

CheckingAccount::CheckingAccount(int b, int t)
	: Account(b)
{
	// �������� ��ȿ�� �˻�
	if (t >= 0) // �����ᰡ 0���� ũ�ų� ������ ��ȿ�� ��
	{
		TransactionFee = t; // t�� TransactionFee�� �Ҵ�
	}
	else // �����ᰡ 0���� ������ ��ȿ���� ���� ��
	{
		TransactionFee = 0;
		cout << "�Էµ� ���� ��ȿ���� ���� ���̹Ƿ� 0���� �ʱ�ȭ �մϴ�." << endl;
	}
}

void CheckingAccount::credit(int m)
{
	int b = get() + m - TransactionFee; // �Ա� �� ���� �ܰ�� (���� ���� �ܰ� + �Ա��� �ݾ� - ������)
	// �Ա� �� �ݾ��� ��ȿ�� �˻�
	if (b >= 0) // �Ա� �� �ݾ��� 0���� ũ�ų� ������ ��ȿ�� ��
	{
		set(b); // �Ա� �� �ݾ��� set�Լ��� �̿��� balance�� �Ҵ�
	}
	else // �Ա� �� �ݾ��� 0���� ������ ��ȿ���� ���� ��
	{
		cout << "�Ա� �ܾ��� �����մϴ�." << endl;
	}
}

void CheckingAccount::debit(int m)
{
	int b = get() - m - TransactionFee; // ��� �� ���� �ܰ�� (���� ���� �ܰ� - ����� �ݾ� - ������)
	// ��� �� �ݾ��� ��ȿ�� �˻�
	if (b >= 0) // ��� �� �ݾ��� 0���� ũ�ų� ������ ��ȿ�� ��
	{
		set(b);  // ��� �� �ݾ��� set�Լ��� �̿��� balance�� �Ҵ�
	}
	else // ��� �� �ݾ��� 0���� ������ ��ȿ���� ���� ��
	{
		cout << "��� �ܾ��� �����մϴ�." << endl;
	}
}