#include<iostream>
using namespace std;

void sub(int* p);
void addmult(int a, int b, int* sum, int* mult);

struct student
{
	int number;
	char name[20];
	double height;
	struct student* next;
};

struct date
{
	int month;
	int day;
	int year;
};

struct point
{
	int x;
	int y;
};

int get_line_parameter(struct point p1, struct point p2, float* slope, float* yintercept);

int main()
{
	struct point pt1 = { 3,3 }, pt2 = { 6,6 };
	float s, y;

	if (get_line_parameter(pt1, pt2, &s, &y) == -1)
		cout << "error" << endl;
	else
		cout << "Gradient is " << s << " intercept is " << y;

	return 0;
}

void sub(int* p)
{
	*p = 200;
}

void addmult(int a, int b, int* sum, int* mult)
{
	*sum = a + b;
	*mult = a * b;
}

int get_line_parameter(struct point p1, struct point p2, float* slope, float* yintercept)
{
	if (p1.x == p2.x)
		return (-1);
	else
	{
		// slope�� ���⸦ �ǹ�
		//uintercept�� �׻� 0�� ���´�. why? y�� - ����*x���� �׻� 0�̹Ƿ�!
		*slope = (float)(p2.y - p1.y) / (float)(p2.x - p1.x);
		*yintercept = p1.y - (*slope) * p1.x;
		return 0;
	}
}

/*
EX 1
int main()
{
	int n = 10;
	int* m;
	m = &n;
	cout << "Address : " << m << " Value : " << *m << endl;

	n = 100; // n�� 100���� �ٲ����μ� m�� �ּ��� ���� ���� 100���� �ٲ�, ������ �ּҰ��� �״�δ�.
	cout << "Address : " << m << " Value : " << *m << endl;

	return 0;
}


EX 2
int main()
{
	char c = 'A';
	int i = 10000;
	double d = 6.78;

	char* pc = &c;
	int* pi = &i;
	double* pd = &d;

	(*pc)++;
	*pi = *pi + 1;
	*pd += 1;

	cout << "c = " << c << endl;
	cout << "i = " << i << endl;
	cout << "d = " << d << endl;
	//�Ʒ� �ڵ嵵 ������ �ڵ�!
	//cout << "c = " << *pc << endl;
	//cout << "i = " << *pi << endl;
	//cout << "d = " << *pd << endl;

return 0;
}


EX 3
int main()
{
	int i = 10000;
	int* p, * q;

	p = &i;
	q = &i;

	*p = *p + 1;
	*q = *q + 1;

	cout << "i = " << i << endl;

	return 0;
}


EX 4
//�����Ͷ� �̿��� ������ ������ Ÿ���� �����ؾ� �Ѵ�.
int main()
{
	int i;
	double* pd;

	pd = &i;
	*pd = 36.4;

	return 0;
}


EX 5
int main()
{
	int a[] = { 10,20,30,40,50 };

	cout << &a[0] << endl;
	cout << &a[1] << endl;
	cout << &a[2] << endl;

	cout << a << endl; // a���� a[0]�� �ּҰ��� �����ϴ�.
	cout << *a << endl; // a[0]�� ���� �ҷ��´�.

	return 0;
}


EX 6
int main()
{
	int a[] = { 10,20,30,40,50 };

	cout << "a = " << a << endl;
	cout << "a + 1 = " << a + 1 << endl;
	// a+1�� ����ϸ� �迭 a�� ù �ּ� a[0]���� 1�� �������� �� �ƴ϶� a[1]�� �ּҰ� ��µǰ� �ȴ�.

	cout << "a = " << *a << endl;
	cout << "a + 1 = " << *(a + 1) << endl;
	// ���� *(a+1)�� ���� a[1]�� ���� ��µȴ�. a[0]�� ���� 1�� �������� �� �ƴϴ�.

	return 0;
}


EX 7
int main()
{
	int a[] = { 10,20,30,40,50 };
	int* p;

	p = a; // p�� a�� ����
	cout << "1 = " << a[0] << " 2 = " << a[1] << " 3 = " << a[2] << endl;
	cout << "1 = " << p[0] << " 2 = " << p[1] << " 3 = " << p[2] << endl;
	// �迭�� call by reference�̹Ƿ� *�� �� ���δ�.

	p[0] = 60;
	p[1] = 70;
	p[2] = 80;

	cout << "1 = " << a[0] << " 2 = " << a[1] << " 3 = " << a[2] << endl;
	cout << "1 = " << p[0] << " 2 = " << p[1] << " 3 = " << p[2] << endl;

	return 0;
}


EX 8
int main()
{
	int i = 100;

	sub(&i);

	cout << i << endl;

	return 0;
}


EX 11
int main()
{
	int x = 10;
	int y = 20;
	int s;
	int m;

	addmult(x, y, &s, &m);
	cout << s << ' ' << m << endl;

	return 0;
}


EX 12
int main()
{
	struct student s = { 12201856,"Kim",170 };
	struct student* p;

	p = &s;

	cout << "Student id is : " << s.number << endl;
	cout << "Student id is : " << (*p).number << endl;
	cout << "Student id is : " << p->number << endl;
	// �� �ڵ�� ��� �����ϴ�.

	return 0;
}



EX 13
int main()
{
	struct date d = { 3,20,1980 };
	struct student  s = { 12201856,"Kim",170 };

	s.dob = &d;

	cout << "SID : " << s.number << endl;

	cout << "Year : " << (*s.dob).year << endl;
	cout << "Year : " << s.dob->year << endl;
	// ������ �ڵ��̴�.

	return 0;
}


EX 14
int main()
{
	struct student s1 = { 30,"Kim",167.2 };
	struct student s2 = { 31,"Park",179.1, NULL};
	struct student* first;
	struct student* current = NULL;

	first = &s1;
	s1.next = &s2;
	s2.next = NULL;
	// ������ �ڵ��̴�.

	current = first; // current, first ��� �ּҰ�
	while (current != NULL)
	{
		cout << current->number << endl;
		current = current->next;
	}
	return 0;
}


EX 16
int main()
{
	struct point pt1 = { 3,3 }, pt2 = { 6,6 };
	float s, y;

	if (get_line_parameter(pt1, pt2, &s, &y) == -1)
		cout << "error" << endl;
	else
		cout << "Gradient is " << s << " intercept is " << y;

	return 0;
}
*/