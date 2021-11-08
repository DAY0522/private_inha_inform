#include<iostream>
#include<string>
using namespace std;

class Employee { // Employee Ŭ������ ����
public: // �� ��� �Լ��� public���� ����
	Employee(string f, string l, int s); // �Էµ� f, l, s�� ������ �ʱ�ȭ �ϴ� ������ �������̽� ����
	void setFirstName(string f); //firstName ������ ���� �Ҵ��ϱ� ���� setFirstName�Լ� �������̽� ����
	string getFirstName(); // firstName������ ���� �ҷ����� ���� getFirstName�Լ� �������̽� ����
	void setLastName(string l); //lastName ������ ���� �Ҵ��ϱ� ���� setLastName�Լ� �������̽� ����
	string getLastName(); // lastName������ ���� �ҷ����� ���� getLastName�Լ� �������̽� ����
	void setMonthlySalary(int s); //monthlySalary ������ ���� �Ҵ��ϱ� ���� setMonthlySalary�Լ� �������̽� ����
	int getMonthlySalary(); // monthlySalary������ ���� �ҷ����� ���� getMonthlySalary�Լ� �������̽� ����
private: // �� ��� ������ private�� ����
	string firstName; // string���� fistName ���� ����
	string lastName; // string���� lastName ���� ����
	int monthlySalary; // int���� monthlySalary ���� ����
};