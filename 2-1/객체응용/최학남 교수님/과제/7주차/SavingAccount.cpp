#include<iostream>
using namespace std;

#include "SavingAccount.h" // ��������� include

double SavingAccount::annualInterestRate = 0.03; // annualInterestRate�� �ʱ�ȭ(��ü�� �������� �ʾƵ� ���� �����ڸ� �̿��� ���� ����)

SavingAccount::SavingAccount(double b)  // double ���� �ϳ��� parameter�� �޴� ������ ����
{
	savingsBalance = b >= 0 ? b : 0; // ��ȿ�� �˻縦 ���� 0���� ũ�ų� ���� ���� �ԷµǸ� �Է��� �� �״��, ���� ���� �ԷµǸ� 0���� �ʱ�ȭ
}

void SavingAccount::calculateMonthlyInterest() // �����ڸ� ������ִ� �Լ� ����
{
	cout << "$" << (savingsBalance * annualInterestRate) / 12 << endl; // ������((savingsBalance * annualInterestRate) / 12 )�� ���
	savingsBalance *= 1 + annualInterestRate / 12; // ���ڸ� ���('1 + annualInterestRate / 12'�� ���� �ݾ׿� ����)�Ͽ� ������ �ܰ� ���
}

void SavingAccount::modifyInterestRate(double i)  // annualInterestRate ���� �����ϴ� �Լ� ����
{
	annualInterestRate = i > 0 ? i : 0.03; // ��ȿ�� �˻縦 ���� 0���� ũ�ų� ���� ���� �ԷµǸ� �Է��� �� �״��, ���� ���� �ԷµǸ� 0.03���� �ʱ�ȭ
}

void SavingAccount::printBalance() const // �ܰ� ������ִ� �Լ� ����
{
	cout << "$" << savingsBalance << endl; // ���� �ܰ�(savingsBalance)�� ���
}