#include<iostream>
#include<string>
using namespace std;

const string operator+(const string& left, const string& right) // string class�� ������ �����ε�, string&�� �� ���� parameter�� �Է¹���
{
	return left + ' ' + right; // ���� parameter�� �Էµ� str��ü�� ������ parameter�� �Էµ� str��ü�� �����Ͽ� ��ȯ 
}

int main()
{
	string str1 = "happy"; // str1 ��ü ���� �� �ʱ�ȭ
	string str2 = "birth day"; // str2 ��ü ���� �� �ʱ�ȭ
	string str3 = str1 + str2; // str3 ��ü ���� �� �ʱ�ȭ, ������ ������ ������ �����ε� �Լ��� �̿��� ������ str ��ü�� +�� �����ų �� ����

	cout << "str1 : " << str1 << endl
		<< "str2 : " << str2 << endl
		<< "str3 : " << str3 << endl << endl;

	string str4("happy"); // str4 ��ü ���� �� �ʱ�ȭ
	string str5("birth day"); // str5 ��ü ���� �� �ʱ�ȭ
	string str6("to you"); // str6 ��ü ���� �� �ʱ�ȭ
	string str7 = str4 + str5 + str6; // ������ ������ ������ �����ε� �Լ��� �̿��� ���� ���� ���� �̿� ������


	cout << "str4 : " << str4 << endl
		<< "str5 : " << str5 << endl
		<< "str6 : " << str6 << endl
		<< "str7 : " << str7 << endl;

	return 0;
}