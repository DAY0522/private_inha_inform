#include<iostream>
using namespace std;
#define PI 3.141592

int main_2(void)
{
	float radius, area, circumference; // ������, ����, �ѷ�

	cout << "insert the radius : ";
	//printf("insert the radius : ");
	cin >> radius;
	//scanf_s("%f", &radius);

	area = PI * radius * radius;
	circumference = 2.0 * PI * radius;

	cout << "radius = " << radius << endl;
	cout << fixed;
	cout.precision(2); // �Ҽ��� 2��° �ڸ����� ����
	cout << "radius = " << radius << endl;

	//printf("radius = %f\n", radius);
	cout << "circle area = " << area << endl << "circumference = " << circumference << radius << endl;
	//printf("circle area = %f, circumference = %f\n", area, circumference);

	return 0;
}