#include<iostream>
using namespace std;

int main_B(void)
{
	int c = 0;

	switch (c)
	{
	case 'v': // ASCII �ڵ�� �о���̹Ƿ� 118�� �޾Ƶ���.
		cout << "I am in case v" << endl;
		break;
	case 3:
		cout << "I am in case 3" << endl;
		break;
	case 12:
		cout << "I am in case 12" << endl;
		break;
	default:
		cout << "I am in default" << endl;
		break;
	}

	return 0;
}