#include<iostream>
using namespace std;

#include "SavingAccount.h" // ��������� include

int main()
{
	SavingAccount::modifyInterestRate(0.03); // �� ���ڸ� 3%�� �Ҵ�

	SavingAccount* ptrServer1 = new SavingAccount(2000.00); // new�� �̿��� ptrSever1 ��ü�� ���� �޸� �Ҵ�, ��ü�� �ܰ� $2000�� �ʱ�ȭ
	SavingAccount* ptrServer2 = new SavingAccount(3000.00); // new�� �̿��� ptrSever2 ��ü�� ���� �޸� �Ҵ�, ��ü�� �ܰ� $3000�� �ʱ�ȭ

	cout << "server1 balance : ";
	ptrServer1->printBalance(); // ptrServer1�� �ܰ� ���
	cout << "server2 balance : ";
	ptrServer2->printBalance(); // ptrServer2�� �ܰ� ���
	cout << endl;

	cout << "server1 interest : ";
	ptrServer1->calculateMonthlyInterest(); // ptrServer1�� �� ���� ���
	cout << "server2 interest : ";
	ptrServer2->calculateMonthlyInterest(); // ptrServer2�� �� ���� ���
	cout << endl;

	cout << "server1 balance : ";
	ptrServer1->printBalance(); // ptrServer1�� �ܰ�(������ 0.03%�� ����� ��) ���
	cout << "server2 balance : ";
	ptrServer2->printBalance(); // ptrServer2�� �ܰ�(������ 0.03%�� ����� ��) ���
	cout << endl;

	SavingAccount::modifyInterestRate(0.04); // �� ���ڸ� 4%�� �Ҵ�

	cout << "server1 interest : ";
	ptrServer1->calculateMonthlyInterest(); // ptrServer1�� �� ���� ���
	cout << "server2 interest : ";
	ptrServer2->calculateMonthlyInterest(); // ptrServer2�� �� ���� ���
	cout << endl;

	cout << "server1 balance : ";
	ptrServer1->printBalance(); // ptrServer1�� �ܰ�(������ 0.04%�� ����� ��) ���
	cout << "server2 balance : ";
	ptrServer2->printBalance(); // ptrServer2�� �ܰ�(������ 0.04%�� ����� ��) ���

	delete ptrServer1; // ptrServer1�� �޸� ���� ����
	delete ptrServer2; // ptrServer2�� �޸� ���� ����
	return 0;
}