#include<iostream>
using namespace std;

/*
int main(void) // Ex. 
{
	return 0;
}


int main(void) // Ex. a
{
	int j;
	while (j <= 10)
	{
		cout << j << endl; // endl : endline
		j += 1; // j=j+1
	}
	return 0;
}


int main(void) // Ex. b
{
	int i = 1;
	while (i <= 10); // ;�� ������ �� �ȴ�. ������ ���ѷ��� �߻�. ��, while���� �������� ����(while�� �������� �Ѿ�� ���ϰ� ��)
	{
		cout << i << endl; // endl : endline
		i ++; // i=i+1
	}
	return 0;
}


int main(void) // Ex. c
{
	int j = 0;
	while (j <= 10)
	{
		cout << j << endl;
		j = j + 1;
	}
	return 0;
}


int main(void) // Ex. d
{
	int x = 1;
	while (x==1) // ==�� ���ٴ� ������
	{
		x = x - 1;
		cout << x << endl;
	}
	return 0;
}


int main(void) // Ex. e
{
	int x = 1;
	while (x==1) // ��ȣ�� ������ while�� �Ʒ� �ڵ� �ϳ��� loop������ ���� �� ����
		x = x - 1;
	cout << x << endl;
	return 0;
}


int main(void) // Ex. f ( while���� for���� ����)
{
	char x; // char : -128 ~ 127
	while (x = 0; x <= 255; x++)
	{
		cout << "Ascii value" << int(x) << "Character" << x << endl;
	} // char �ڷ����� decimal�� ����ϰ� ���� ���� int(����)�� �Է����ָ� �ȴ�.
	return 0;
}


int main(void) // Ex. f - 1 ( while���� for���� ����)
{
	char x; // char : -128 ~ 127
	for (x = 0; x <= 255; x++) // char�� 128�� �Ǹ� -128�� �ǹǷ� ���ѷ����� �߻��ϰ� �ȴ�.
	{
		cout << "Ascii value" << int(x) << "Character" << x << endl;
	} // char �ڷ����� decimal�� ����ϰ� ���� ���� int(����)�� �Է����ָ� �ȴ�.
	return 0;
}


int main(void) // Ex. f - 2
{
	unsigned char x; // unsigned char : 0 ~ 255
	for (x = 0; x < 255; x++)  // unsigned�� ���� overflow �߻� x
	{
		cout << "Ascii value : " << int(x) << ", Character : " << x << endl;
	}
	return 0;
}


int main(void) // Ex. g
{
	int x = 4, y, z;
	y = --x; // ���� x = x - 1 ��
	z = x--; // ���� �ٿ��� x = x - 1�� ��
	cout << x << ' ' << y << ' ' << z;
	return 0;
}


int main(void) // Ex. h 
{
	int x = 4, y = 3, z;
	z = x-- - y;
	cout << x << ' ' << y << ' ' << z;
	return 0;
}


int main(void) // Ex. h -1
{
	int x = 4, y = 3, z;
	z = --x - y;
	cout << x << ' ' << y << ' ' << z;
	return 0;
}


int main(void) // Ex. i
{
	while ('a'<'b') // a�� b�� �ƽ�Ű�ڵ�� �ν� �ž� 97<98�̹Ƿ� ���ѷ��� �߻�
	{ // ���ǹ��� ���ڰ� �� ���� �ִ�!
		cout << "malyalam is a palindrome" << endl;
	}
	return 0;
}


int main(void) // Ex. j
{
	int i = 10;
	while (i = 20) // =�� �ϳ� �־ ���ѷ����� �߻��ϰ� �ȴ�.
				   // i = 20�� ������ �޾Ƶ���.
	{
		cout << "A computer buff!" << endl;
	}
	return 0;
}


int main(void) // Ex. j -1
{
	int i = 10;
	while (0) // 0�� false�� �ǴܵǹǷ� while���� ������� �ʴ´�.
	{
		cout << "A computer buff!" << endl;
	}
	cout << "end" << endl;
	return 0;
}


int main(void) // Ex. k
{
	int i;
	while (i = 10) // i++; �� �ϴ��� �ٽ� i�� 10���� �ʱ�ȭ �ǹǷ� ��� 10�� ����ϰ� ��
	{
		cout << i << endl;
		i = i + 1; // i++; �� ����
		//cout << i << endl; // �ϸ� 11�� ��µ�
	}
	return 0;
}


int main(void) // Ex. ��
{
	float x = 1.1;
	while (x == 1.1) // float ���� ��� �ٻ�ġ�� ������ �־ ��Ȯ�� 1.1�� ���� �ʴ´�.
					 // ���� x == 1.1�� false�� �ǹǷ� �ݺ����� ������� �ʴ´�.
					 // ���ǹ����� float, double�� ���� �ʴ� ���� ����.
	{
		cout << x << endl;
		x = x - 0.1;
	}
	return 0;
}


int main(void) // Ex. m
{
	printf("%d %d", '1', '2');

	while ('1' < '2') // ���ǹ� : 49 < 50
	{
		cout << "while loop" << endl;
	}
	return 0;
}


int main(void) // Ex. n
{
	char x;
	for (x = 0; x <= 255; x++)
	{
		cout << "Ascii value" << int(x) << "Character" << x << endl;
	}
	return 0;
}


int main(void) // Ex. o
{
	int x = 4, y = 0, z;
	while (x >= 0)
	{
		x--;
		y++;

		if (x == y)
			continue; // x�� 2, y�� 2�� �Ǹ� continue�� ����� ���� �ݺ������� �Ѿ�� ��
		else
			cout << x << ' ' << y << endl;
	}
	return 0;
}


int main(void) // Ex. p
{
	int x = 4, y = 0, z;
	while (x >= 0)
	{
		if (x == y)
			break; // x�� 2, y�� 2�� �Ǹ� break�� ����� �ݺ����� �����
		else
			cout << x << ' ' << y << endl;

		x--;
		y++;
	}
	return 0;
}
*/