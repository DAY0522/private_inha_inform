#pragma once

class Account // Account class ����
{
public:
	Account(int); // Account class�� ������ ����(int�� ���� �ϳ��� ���ڷ� ����)
	void credit(int); // ���¿� �Էµ� ���ڸ�ŭ ���� �Ա��ϴ� credit �Լ� ����
	void debit(int); // ���¿� �Էµ� ���ڸ�ŭ ���� ����ϴ� debit �Լ� ����
	int get() const; // balance�� return�ϴ� get�Լ� ����
	void set(int&); // balance�� �Էµ� ���ڷ� �ʱ�ȭ�ϴ� set�Լ� ����
	void print(); // ���� �ܰ� ����ϴ� print �Լ� ����

private:
	int balance; // ���� �ܰ� �ش��ϴ� int�� ���� balance
};

class SavingAccount // SavingAccount class ����
	: public Account // �⺻Ŭ������ Account�� ���(���������� : public)
{
public:
	SavingAccount(int, double);  // Account class�� ������ ����(int�� ���� �ϳ�, double�� ���� �ϳ��� ���ڷ� ����)
	double CalculateInterest();
private:
	double interestrate; // ���ڿ� �ش��ϴ� double�� ���� interestrate
};

class CheckingAccount // CheckingAccount class ����
	: public Account // �⺻Ŭ������ Account�� ���(���������� : public)
{
public:
	CheckingAccount(int, int);  // Account class�� ������ ����(int�� ���� �� ���� ���ڷ� ����)
	void credit(int); // ���¿� �Էµ� ���ڸ�ŭ ���� �Ա��ϴ� credit �Լ� ����(������ ���)
	void debit(int); // ���¿� �Էµ� ���ڸ�ŭ ���� ����ϴ� debit �Լ� ����(������ ���)

private:
	int TransactionFee; // �����ῡ �ش��ϴ� int�� ���� TransactionFee
};