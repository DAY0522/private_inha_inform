#include <iostream>
using namespace std;

#include "Time.h" // Time Ŭ������ �̿��ϱ� ���� ������� include

int main()
{
	Time t(23, 58, 40); // Time class ��ü t ����, �� : 23, �� : 58, �� : 40���� �ʱ�ȭ
	int day = 1; // hour�� 0�� ���� �� ��¥�� �ٲ��� �����ֱ� ���� int�� ���� day ���� �� 1�� �ʱ�ȭ

	for (int i = 0; i < 180; i++) // loop�� ���� tick �Լ��� �� �۵��Ǵ��� Ȯ��
	{
		if (t.tick() == 1) // if�� ������ t.tick()�� ����Ǹ鼭 for loop �� �� �� ������ 1�ʾ� ����
		// t.tick()�� ��ȯ���� 1�̸� day�� 1 ���������
		{
			day++; // ��ȯ���� 1�̸� hour�� 0�� �ƴٴ� ���̹Ƿ� day�� 1�� ������
		}
		cout << "Day-" << day << " : "; // day�� ���
		t.printStandard(); // Standard �ð����� ��ü t�� ��:��:��(AM/PM)�� ���
	}

	return 0;
}