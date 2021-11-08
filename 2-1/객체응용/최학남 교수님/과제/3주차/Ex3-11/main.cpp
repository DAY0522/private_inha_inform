#include<iostream>
using namespace std;
#include "Ex3-11.h" // ��������� include

int main()
{
	Employee lisa("Lisa", "Roberts", 4500); // Employee Ŭ������ ��ü�� lisa�� �����ϰ� �����ڸ� ���� �� ��������� �ʱ�ȭ
	Employee mark("Mark", "Stein", 4000); // Employee Ŭ������ ��ü�� mark�� �����ϰ� �����ڸ� ���� �� ��������� �ʱ�ȭ

	cout << "Employees' yearly salaries : " << endl // cout�� �̿��� �������� ������ ������ ���
		<< lisa.getFirstName() << " " << lisa.getLastName() // lisa ��ü�� ��� ������ �����Ͽ� ���� ����� �� �����Ƿ� ������ get�Լ��� �̿��� firstname�� lastname, monthlysalary�� ���� ��ȯ�޾� ���
		<< " : $" << (lisa.getMonthlySalary()*12) << endl // ��ü�� ������ �ִ� monthlysalary ������ �����̹Ƿ� ������ ����ϱ� ���� 12�� ���Ѵ�.
		<< mark.getFirstName() << " " << mark.getLastName() // mark ��ü�� ��� ������ �����Ͽ� ���� ����� �� �����Ƿ� ������ get�Լ��� �̿��� firstname�� lastname, monthlysalary�� ���� ��ȯ�޾� ���
		<< " : $" << (mark.getMonthlySalary()*12) << endl;

	// ���� ��ü�� ������ 10% �λ��ϱ� ���� get�Լ��� ���� monthlysalary ���� �ҷ��� 1.1�� �����ְ� set�Լ��� �̿��� monthlysalary�� ���� �ٽ� �Ҵ��Ѵ�.
	lisa.setMonthlySalary(lisa.getMonthlySalary() * 1.1);
	mark.setMonthlySalary(mark.getMonthlySalary() * 1.1);

	// �տ����� ������ ������� ��ü�� ��������� ������ش�.
	cout << endl << "Employees' yearly salaries after 10% raise : " << endl
		<< lisa.getFirstName() << " " << lisa.getLastName()
		<< " : $" << (lisa.getMonthlySalary()*12) << endl
		<< mark.getFirstName() << " " << mark.getLastName()
		<< " : $" << (mark.getMonthlySalary()*12) << endl;

	return 0;
}