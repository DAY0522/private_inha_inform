#include<iostream> // iostream ��������� include
using namespace std; // ǥ�� �������̽��� ���
int N = 1000; // int�� ���� N�� ���������� ���� �� 1000���� �ʱ�ȭ
int cal_sum(); // 0~N���� ���� ��ȯ�ϴ� �Լ� ������Ÿ�� ����

int main(void) { // �����Լ� ����
	int sum; //int�� ���� sum�� ���������� ����
	sum = cal_sum(); // sum�� cal_sum�� ��ȯ���� ����
	{ // ��ȣ ����
		int k; //int�� ���� k�� ���������� ����
		k = 9; // k�� 9�� �ʱ�ȭ
		cout << "k = " << k << endl; // k�� ��� �� ��ٲ�
	} //��ȣ �ݱ�
	cout << "sum of first " << N << " naural numbers is " << sum << endl; // N�� sum�� ����� �� �ٹٲ�
	return 0; // 0�� ��ȯ
} // ��ȣ �ݱ�

int cal_sum() { // int��(��ȯo) �Լ� cal_sum ����
	int i, s = 0; // int�� ���� i, s�� ���������� ���� �� s�� =���� �ʱ�ȭ
	for (i = 0; i <= N; i++) //i�� 0���� N���� �۰ų� ���� ������ i++�� �ϸ鼭 for�� �ۼ�
	{ // ��ȣ ����
		s = s + i; // s�� i�� ���� ���� s�� ����
	} // ��ȣ �ݱ�
	return s; // for���� ���� �������� s�� ���
} // ��ȣ �ݱ�