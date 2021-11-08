#include <iostream>
using namespace std;

// Ŭ������ ���� ���� ������ �����ϱ� ���� ���� ��ó���� ���
#ifndef RATIONAL_H // RATIONAL_H�� def���� �ʾ����� true�� �� #endif�� ������ �������� �ڵ带 �������Ѵ�.
#define RATIONAL_H
class Rational // Rational class ����
{
public: // ��� �Լ��� public
	Rational(int = 0, int = 1); // Rational calss�� ������ ����(�ΰ��� int�� parameter�� ����Ʈ ���ڸ� 0, 1�� ����)
	void add(Rational, Rational); // �ΰ��� Rational ��ü�� parameter�� �ϴ� �� �м��� �����ִ� �Լ� ����
	void sub(Rational, Rational); // �ΰ��� Rational ��ü�� parameter�� �ϴ� �� �м��� ���ִ� �Լ� ����
	void mul(Rational, Rational); // �ΰ��� Rational ��ü�� parameter�� �ϴ� �� �м��� �����ִ� �Լ� ����
	void div(Rational, Rational); // �ΰ��� Rational ��ü�� parameter�� �ϴ� �� �м��� �����ִ� �Լ� ����
	void print_fract(); // �м��� �м� ��� �״�� Ǯ���ϴ� �Լ� ����
	void print_float(); // �м��� �Ҽ��� ����ϴ� �Լ� ����
private: // ��� ������ private
	int numerator; // �м��� ���ڸ� ��Ÿ���� int�� ���� ����
	int denominator; // �м��� �и� ��Ÿ���� int�� ���� ����
};

#endif // #ifndef�� ���κ�