#include<iostream>
using namespace std;
int main(void)
{
	char num;
	cin >> num;
	while (num < 65 || (num > 90 && num < 97) || num>122) {
		cout << "�߸� �Է��ϼ̽��ϴ�. ���ĺ��� �ٽ� �Է��ϼ���" << endl;
		cin >> num;
	}
	switch (num/92)
	{
	case 0:
		cout << char(num + 32);
		break;
	case 1:
		cout << num;
		break;
	default:
		break;
	}
	return 0;
}