#include<iostream>
using namespace std;

int main_A(void) {
	char suite = 3;

	// ��� switch���� if������ ǥ�� ����
	// ������ ��� if���� switch������ ǥ���ϴ� ���� �Ұ���
	switch (suite) // () ���� �ݵ�� ������ ���� �Ѵ�.
				   // char, short, int, long, long long, ...
	{
	case 1:
		cout << "Diamond" << endl;
		break;
	case 2:
		cout << "Spade" << endl;
		break;
	default: // ����ó��
		cout << "Heart" << endl;
		break;
	}
	cout << "I thought one wears a suite" << endl;

	return 0;
}