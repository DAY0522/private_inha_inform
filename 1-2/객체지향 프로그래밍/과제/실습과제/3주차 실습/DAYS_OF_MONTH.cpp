#include<iostream>
#include<iomanip>
using namespace std;

#define START_DAY 5
#define DAYS_OF_MONTH 31

int main(void)
{
	int day, date;
	cout << "=========================================" << endl;
	cout << "Sun.  Mon.  Tue.  Wed.  Thu.  Fri.  Sat. " << endl;
	cout << "=========================================" << endl;

	for (day = 0; day < START_DAY; day++)
	{
		cout << "      "; // ���⼱ 5���� �ڿ� ù���� ���۵ǹǷ� ������ 5�� ����Ѵ�.
	}

	for (date = 1; date <= DAYS_OF_MONTH; date++)
	{
		if (day == 7)
		{
			day = 0;
			cout << endl;
		}
		day++;
		//printf("%4d", date);
		cout << setw(4) << date << "  ";
		

		// �� �̷��� �ۼ��ϸ� �� �ǳ�?
		/*cout.precision(4);
		cout << date;*/
	}

	cout << "\n=========================================\n";
	return 0;
}