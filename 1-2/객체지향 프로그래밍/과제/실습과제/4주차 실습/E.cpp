#include<iostream>
using namespace std;

int main_E(void)
{
	int k;
	float j = 2.0; // 2.9���� k = j + 1�� 3�� �ȴ�. int�� �Ǳ� ���� �Ҽ����� �׳� ����

	switch (k=j+1) // j�� float�̾ k�� int�̹Ƿ� 
	{
	case 3:
		cout << "Trapped" << endl;
		break;
	default:
		cout << "Caught!" << endl;
	}

	return 0;
}