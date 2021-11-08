#include "Complex.h" // Complex Ŭ������ �̿��ϱ� ���� ������� include
#include<iostream>
using namespace std;

Complex::Complex(double r, double i) // Complex class�� ������ ����
	: real(r), imag(i) {} // ��� �̴ϼȶ�����(:)�� �̿��� real�� imag ������ ����ڰ� �Է��� r�� i�� �ʱ�ȭ

void Complex::add(Complex com) // Complex class�� add �Լ� ����
{
	real += com.real; // ���� ��ü�� real ������ ����ڰ� �Է��� �߰� ��ü com�� real ������ ����
	imag += com.imag; // ���� ��ü�� imag ������ ����ڰ� �Է��� �߰� ��ü com�� imag ������ ����
}

void Complex::sub(Complex com) // Complex class�� sub �Լ� ����
{
	real -= com.real; // ���� ��ü�� real ������ ����ڰ� �Է��� �߰� ��ü com�� real ������ ��
	imag -= com.imag; // ���� ��ü�� imag ������ ����ڰ� �Է��� �߰� ��ü com�� imag ������ ��
}

void Complex::print() // Complex class�� print �Լ� ����
{
	cout << "(" << real << ", " << imag << ")"; // cout�� �̿��� ���Ҽ��� (�Ǽ���, �����) ���·� ���
}