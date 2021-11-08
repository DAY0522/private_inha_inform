#include <iostream>

using namespace std;

// Ŭ������ ���� ���� ������ �����ϱ� ���� ���� ��ó���� ���
#ifndef COMPLEX_H // COMPLEX_H�� def���� �ʾ����� true�� �� #endif�� ������ �������� �ڵ带 �������Ѵ�.
#define COMPLEX_H
class Complex { // Complex class ����
public: // ��� �Լ��� public
	Complex(double = 0.0, double = 0.0); // Complex class�� ������ ����, �� ���� double�� parameter�� �⺻ ���ڷ� �ʱ�ȭ
	void add(Complex com); // �� ���� ���Ҽ��� ���ϴ� �Լ� ����
	void sub(Complex com); // �� ���� ���Ҽ��� ���� ���Ҽ� ����
	void print(); // ���Ҽ��� (�Ǽ���, �����)�� ���·� ����ϴ� �Լ� ����
private: // ��� ������ private
	double real; // ���Ҽ��� �Ǽ��θ� ��Ÿ���� double�� ���� ����
	double imag; // ���Ҽ��� ����θ� ��Ÿ���� double�� ���� ����
};

#endif // #ifndef�� ���κ�