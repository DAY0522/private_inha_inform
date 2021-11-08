#pragma once // �������� ������ ����

#ifndef SAVINGACCUNT_H
#define SAVINGACCUNT_H

class SavingAccount // SavingAccount Ŭ���� ����
{
public:
	SavingAccount(double); // double ���� �ϳ��� parameter�� �޴� ������ ����
	void calculateMonthlyInterest(); // �����ڸ� ������ִ� �Լ� ����
	static void modifyInterestRate(double); // annualInterestRate ���� �����ϴ� �Լ� ����
	void printBalance() const; // �ܰ� ������ִ� �Լ� ����
private:
	double savingsBalance; // �ܰ� �ݾ�
	static double annualInterestRate; // ������
};

#endif