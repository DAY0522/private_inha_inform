#include "Rational.h" // Rational Ŭ������ �̿��ϱ� ���� ������� include
#include<iostream>
using namespace std;

void reduced_form(int *n, int *d) 
// �Էµ� Rational�� ��������� ���м��� �ƴ� �� ���м��� ������ֱ� ���� reduced_form �Լ� ����
// Rational �Լ��� ������� ���� reduced_form �Լ� ������ ���� �ٲ�� �ϹǷ� call by reference�� �̿�
{
    if (*n >= *d) // ����(*n)�� �и�(*d)���� ũ�ų� ������
    {
        int max = *d; // max�� �и��� �Ҵ�
        for (int i = max; i > 1; i--) { // index�� max���� �����ؼ� 1���� Ŭ������
            if (*n % i == 0 && *d % i == 0) 
            // ���ڰ� i�� ������ ��������, d�� i�� ������ ������ ��
            // �̸� ó������ �����ϴ� i�� ���ڿ� �и��� �ִ������̹Ƿ�
            {
                *n /= i; // ���ڸ� �ִ� ������� �����ش�.
                *d /= i; // �и� �ִ� ������� �����ش�.
                return; // �ִ������� �����ָ� �ش� �м��� ���м� �����̹Ƿ� �� �̻� for���� �̿����� �ʾƵ� �ȴ�.
            }
            //(numerator % i == 0) ? (denominator % i) ? numerator /= i, denominator /= i : 0 : 0;
        }
    }
    else // ����(*n)�� �и�(*d)���� ������
    {
        int max = *n; // max ���� ���� �Ҵ�
        for (int i = max; i > 1; i--) {
            // �������ǹ�, �Ѵ� ������ ������ ����
            if (*n % i == 0 && *d % i == 0)
           // ���ڰ� i�� ������ ��������, d�� i�� ������ ������ ��
           // �̸� ó������ �����ϴ� i�� ���ڿ� �и��� �ִ������̹Ƿ�
            {
                *n /= i; // ���ڸ� �ִ� ������� �����ش�.
                *d /= i; // �и� �ִ� ������� �����ش�.
                return; // �ִ������� �����ָ� �ش� �м��� ���м� �����̹Ƿ� �� �̻� for���� �̿����� �ʾƵ� �ȴ�.
            }
            //(numerator % i == 0) ? (denominator % i) ? numerator /= i, denominator /= i : 0 : 0;
        }
    }
}

Rational::Rational(int n, int d) :numerator(n), denominator(d) // Rational class�� ������ ����
// ����̴ϼȶ�����(:)�� �̿��� ���ڿ� �и� ����ڰ� �Է��� n�� d�� �ʱ�ȭ
{
    if (denominator == 0)
    {
        cout << "�и� 0�� �� �� �����Ƿ� �и� 1�� ��ü�մϴ�." << endl;
        denominator = 1;
    }
    reduced_form(&numerator, &denominator); // �Էµ� �м��� ���м��� ������ֱ� ���� reduced_form �Լ��� ��������� ��������
}

void Rational::add(Rational R1, Rational R2) // Rational class�� add ����Լ� ����
{
    numerator = R1.numerator * R2.denominator + R1.denominator * R2.numerator; // �м��� �����̹Ƿ� ���ڴ� (R1�� ����*R2�� �и�)+(R2�� ����*R1�� �и�)�� �� ��
    denominator = R1.denominator * R2.denominator; // �м��� �����̹Ƿ� �и�� (R1�� �и�*R2�� �и�)
    reduced_form(&numerator, &denominator); // ������ �Ϸ��� �� ���м� ���·� ����
}

void Rational::sub(Rational R1, Rational R2) // Rational class�� sub ����Լ� ����
{
    numerator = R1.numerator * R2.denominator - R1.denominator * R2.numerator; // �м��� �����̹Ƿ� ���ڴ� (R1�� ����*R2�� �и�)-(R2�� ����*R1�� �и�)�� �� ��
    denominator = R1.denominator * R2.denominator; // �м��� �����̹Ƿ� �и�� (R1�� �и�*R2�� �и�)
    reduced_form(&numerator, &denominator); // ������ �Ϸ��� �� ���м� ���·� ����
}

void Rational::mul(Rational R1, Rational R2) // Rational class�� mul ����Լ� ����
{
    numerator = R1.numerator * R2.numerator; // �м��� �����̹Ƿ� ���ڴ� (R1�� ����*R2�� ����)
    denominator = R1.denominator * R2.denominator; // �м��� �����̹Ƿ� �и�� (R1�� �и�*R2�� �и�)
    reduced_form(&numerator, &denominator); // ������ �Ϸ��� �� ���м� ���·� ����
}

void Rational::div(Rational R1, Rational R2) // Rational class�� div ����Լ� ����
{
    numerator = R1.numerator * R2.denominator; // �м��� �������̹Ƿ� ���ڴ� (R1�� ����*R2�� �и�)
    denominator = R1.denominator * R2.numerator; // �м��� �������̹Ƿ� ���ڴ� (R1�� �и�*R2�� ����)
    reduced_form(&numerator, &denominator); // �������� �Ϸ��� �� ���м� ���·� ����
}

void Rational::print_fract() // Rational class�� print_fract ����Լ� ����
{
    if (numerator == 0) // ���࿡ ���ڰ� 0�̸� �ش� �м��� 0�� ���̹Ƿ� 0�� ����ϰ� �Ѵ�.
    {
        cout << numerator; // 0�� ���
        return;
    }
    else if (numerator == denominator) // ���࿡ ���ڿ� �и� �����ϸ� 1�� ���̹Ƿ�
    {
        cout << numerator / denominator; // 1�� ����Ѵ�.
        return;
    }
    else if (denominator == 1)
    {
        cout << numerator;
        return;
    }
    cout << numerator << "/" << denominator; // ���࿡ ���ڰ� 0�� �ƴϰ� ���ڿ� �и� ������ �͵� �ƴϸ� ���� / �и� ����Ѵ�.
}

void Rational::print_float() // Rational class�� print_float ����Լ� ����
{
    cout << (double)numerator / (double)denominator; // ���ڸ� �и�� ���� ���� ����Ѵ�
}