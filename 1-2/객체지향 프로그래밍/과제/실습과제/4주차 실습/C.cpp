#include<iostream>
using namespace std;

int main_C(void)
{
	int k, j = 2;

	switch (k=j+1)
	// switch�� if������ ������. (���ǽİ� ���Խ��� ����?)
	// if�����ٴ� �������� ����.
	// ������ ���� if���� ����ϴ� ���� �� ����.
	{
	case 0: // if(k==0)
		cout << "Tailor" << endl;
	case 1:
		cout << "Tutor" << endl;
	case 2:
		cout << "Tramp" << endl;
	default:
		cout << "Pure Simple Egghead!" << endl;
	}
	return 0;
}