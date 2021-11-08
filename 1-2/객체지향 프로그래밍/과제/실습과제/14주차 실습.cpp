#include<iostream>
using namespace std;
#pragma warning(disable:4996)

//calloc�� 0���� �ʱ�ȭ ������

struct Book
{
	int number;
	char title[100]; // title�� 10�̸� error �߻�
	//why? �Է¹��� ���񺸴� �迭 ������ ����
};

int main(void)
{
	FILE* fp;
	char fname[100];
	int number, count = 0;
	char name[20];
	float score, total = 0.0;

	//���� �̸� �Է� �ޱ�
	cout << "Enter the score file name : ";
	cin >> fname;

	// ���� ����
	fopen_s(&fp, fname, "w"); // ���� ���� ������ ��

	if (fp == NULL)
	{
		fprintf(stderr, "can not open the  %s file.\n", fname); // stderr�� ������ ����
		exit(1);
	}

	// �й�, �̸�, ���� ����
	while (1)
	{
		cout << "Enter the number, name, score : ";
		cin >> number;
		if (number < 0)
		{
			break;
		}

		cin >> name >> score;
		fprintf(fp, "%d %s %f\n", number, name, score);
	}

	fclose(fp);


	//������ �б� ���� ����
	fopen_s(&fp, fname, "r");

	if (fp == NULL)
	{
		fprintf(stderr, "can not open the  %s file.\n", fname);
		cout << "Can not open the" << fname << " file" << endl;
		exit(1);
	}

	// ���� �б� + ��� ���� ���

	while (1)
	{
		fscanf(fp, "%d %s %f", &number, name, &score);
		//fscanf_s(fp, "%d %s %f", &number, name, &score);
		// name�� �迭�̿��� &�� �� ����

		if (feof(fp)!=0)
		{
			break;
		}
		cout << "number : " << number << ", name : " << name << ", score : " << score << endl;
		total += score;
		count++;
	}
	cout << "Average - " << (total / count) << endl;
	fclose(fp);

	return 0;
}

/*
//EX1
int main(void)
{
	char* pc = NULL;
	pc = (char*)malloc(sizeof(char)); // �����Ҵ�
	// char*�� ����ȯ

	if (pc == NULL) // �޸� ���� �Ҵ��� ���� �ʾ��� �� ���� �߻� ���� ���
	{
		cout << "Memory allocation Error" << endl;
		exit(1);
	}

	*pc = 'm';
	cout << "*pc : " << *pc << endl;
	free(pc); //�޸� �Ҵ� ����

	return 0;
}


//EX2
int main(void)
{
	char* pc = NULL;
	int i = 0;
	pc = (char*)malloc(100*sizeof(char));


	if (pc == NULL)
	{
		cout << "Memory allocation Error" << endl;
		exit(1);
	}

	for (i = 0; i < 26; i++)
	{
		*(pc + i) = 'a' + i;
	}
	*(pc + i) = 0;
	cout << "pc : " << pc << endl;
	free(pc);

	return 0;
}

//EX3
int main(void)
{
	int* pi;
	pi = (int*)malloc(5 * sizeof(int));
	// ĳ������ ������ ������ void*�� �Ҵ�Ǵµ�? �׷��� int* ���ִ� ��

	if (pi == NULL)
	{
		cout << "Memory allocation Error" << endl;
		exit(1);
	}

	pi[0] = 100;
	pi[1] = 200;
	pi[2] = 300;
	pi[3] = 400;
	pi[4] = 500;

	for (int i = 0; i < 5; i++)
	{
		cout << "pc[" << i << "] : " << pi[i] << endl;
	}

	return 0;
}


//EX4
struct Book
{
	int number;
	char title[100]; // title�� 10�̸� error �߻�
	//why? �Է¹��� ���񺸴� �迭 ������ ����
};

int main(void)
{
	struct Book* p;

	p = (struct Book*)malloc(2 * sizeof(struct Book));

	if (p == NULL)
	{
		cout << "Memory allocation Error" << endl;
		exit(1);
	}

	p->number = 1;
	strcpy_s(p->title, "C/C++ programming");

	(p + 1)->number = 2;
	strcpy_s((p+1)->title, "Data Structure");

	cout << "p->number : " << p->number << endl;
	cout << "p->title : " << p->title << endl;

	cout << "(p+1)->number : " << (p+1)->number << endl;
	cout << "(p+1)->title : " << (p+1)->title << endl;

	free(p);

	return 0;
}


//EX5
int main(void)
{
	FILE* fp = NULL;

	// fp = fopen("sample.txt", "w"); ������ �̰ǵ� error �߻���
	fopen_s(&fp, "sample.txt", "w");

	if (fp == NULL) // �Ҵ��� �� ������
	{
		cout << "failed" << endl;
	}
	else
	{
		cout << "success!" << endl;
	}
	fprintf(fp, "hello");

	fclose(fp);

	return 0;
}


//EX6
int main(void)
{
	FILE* fp;
	char fname[100];
	int number, count = 0;
	char name[20];
	float score, total = 0.0;

	//���� �̸� �Է� �ޱ�
	cout << "Enter the score file name : ";
	cin >> fname;

	// ���� ����
	fopen_s(&fp, fname, "w"); // ���� ���� ������ ��

	if (fp == NULL)
	{
		fprintf(stderr, "can not open the  %s file.\n", fname); // stderr�� ������ ����
		exit(1);
	}

	// �й�, �̸�, ���� ����
	while (1)
	{
		cout << "Enter the number, name, score : ";
		cin >> number;
		if (number < 0)
		{
			break;
		}

		cin >> name >> score;
		fprintf(fp, "%d %s %f\n", number, name, score);
	}

	fclose(fp);


	//������ �б� ���� ����
	fopen_s(&fp, fname, "r");

	if (fp == NULL)
	{
		fprintf(stderr, "can not open the  %s file.\n", fname);
		cout << "Can not open the" << fname << " file" << endl;
		exit(1);
	}

	// ���� �б� + ��� ���� ���

	while (1)
	{
		fscanf(fp, "%d %s %f", &number, name, &score);
		//fscanf_s(fp, "%d %s %f", &number, name, &score);
		// name�� �迭�̿��� &�� �� ����

		if (feof(fp)!=0)
		{
			break;
		}
		cout << "number : " << number << ", name : " << name << ", score : " << score << endl;
		total += score;
		count++;
	}
	cout << "Average - " << (total / count) << endl;
	fclose(fp);

	return 0;
}
*/