#include<iostream>
#include<string>
using namespace std;
#include "Ex3-11.h" // ��������� include ����

Employee::Employee(string f, string l, int s) // ������ ����
{
	setFirstName(f); // setFirstName �Լ��� �̿��Ͽ� firstname ��� ������ �Էµ� f�� ������ �ʱ�ȭ
	setLastName(l); // setLastName �Լ��� �̿��Ͽ� lastrname ��� ������ �Էµ� l�� ������ �ʱ�ȭ
	setMonthlySalary(s); // setMonthlySalary �Լ��� �̿��Ͽ� monthlySalary ��� ������ �Էµ� s�� ������ �ʱ�ȭ
}
void Employee::setFirstName(string f) { // Employee Ŭ������ ����Լ��� setFirstName�� ����
	firstName = f; // setFirstName�� firstName ���� �Է��� f ������ ���Ҵ� �ϴ� �Լ��̹Ƿ� firstName�� f�� �����Ѵ�.
}
string Employee::getFirstName() { // Employee Ŭ������ ����Լ��� getFisrtName�� ����
	return firstName; // getFirstName�� firstName�� ��ȯ�ϴ� �Լ��̹Ƿ� firstName�� return ���ش�
}
void Employee::setLastName(string l) {  // Employee Ŭ������ ����Լ��� setLastName�� ����
	lastName = l; // setLastName�� lastName ���� �Է��� l ������ ���Ҵ� �ϴ� �Լ��̹Ƿ� lastName�� l�� �����Ѵ�.
}
string Employee::getLastName() {   // Employee Ŭ������ ����Լ��� getLastName�� ����
	return lastName; // getLastName�� lastName�� ��ȯ�ϴ� �Լ��̹Ƿ� lastName�� return ���ش�
}
void Employee::setMonthlySalary(int s) {  // Employee Ŭ������ ����Լ��� setMonthlySalary�� ����
	if (s<0) // ������ ������ �ԷµǸ� 0���� �ʱ�ȭ�� ���Ѿ� �ϹǷ� if�� �̿�
	{
		monthlySalary = 0; // s<0�� true�̸� ������ �Էµ� ���̹Ƿ� monthlySalary�� 0 ����
		return; // return�� ���� �Լ� ����
	}
	monthlySalary = s; // if���� �������� ������ ���(0����)�� �ùٸ��� �Էµ� ���̹Ƿ� monthlySalary�� �Էµ� s�� ����
}
int Employee::getMonthlySalary()  // Employee Ŭ������ ����Լ��� getMonthlySalary�� ����
{
	return monthlySalary; // getMonthlySalary�� monthlySalary�� ��ȯ�ϴ� �Լ��̹Ƿ� monthlySalary�� return ���ش�
}