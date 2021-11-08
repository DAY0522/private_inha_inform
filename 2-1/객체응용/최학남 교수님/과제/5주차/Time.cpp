#include <iostream>
#include<iomanip>
using namespace std;

#include "Time.h" // Time Ŭ������ �̿��ϱ� ���� ������� include

Time::Time(int h, int m, int s)
	:hour(h), minute(m), second(s){} // ��� �̴ϼȶ�����(:)�� �̿��� ��� ���� �ʱ�ȭ

void Time::setTime(int h, int m, int s) // setTime �Լ� ����
{
	setHour(h); // setHour �Լ��� �̿��� hour�� h ���� �Ҵ�
	setMinute(m); // setMinute �Լ��� �̿��� minute�� m ���� �Ҵ�
	setSecond(s); // setSecond �Լ��� �̿��� second�� s ���� �Ҵ�
}

void Time::setHour(int h) // setHour �Լ� ����
{
	hour = (h >= 0 && h < 24) ? h : 0; // ��ȿ�� �˻� ����
	// '��'�� 0��~23�ñ��� �����ϹǷ� �ش��ϴ� ���� �ƴϸ� 0���� ���� �Ҵ�
}

void Time::setMinute(int m) // setMinute �Լ� ����
{
	minute = (m >= 0 && m < 60) ? m : 0; // ��ȿ�� �˻� ����
	// '��'�� 0��~59�б��� �����ϹǷ� �ش��ϴ� ���� �ƴϸ� 0���� ���� �Ҵ�
}

void Time::setSecond(int s) // setSecond �Լ� ����
{
	second = (s >= 0 && s < 60) ? s : 0; // ��ȿ�� �˻� ����
	// '��'�� 0��~59�ʱ��� �����ϹǷ� �����ϹǷ� �ش��ϴ� ���� �ƴϸ� 0���� ���� �Ҵ�
}

int Time::getHour() const // getHour �Լ� ����
{
	return hour; // ������� hour�� ��ȯ
}

int Time::getMinute() const // getMinute �Լ� ����
{
	return minute; // ������� minute�� ��ȯ
}

int Time::getSecond() const // getSecond �Լ� ����
{
	return second; // ������� second�� ��ȯ
}

void Time::printUniversal() // printUniversal �Լ� ����
{

	cout << setfill('0') << setw(2) << hour << ":"
		<< setw(2) << minute << ":" << setw(2) << second << endl;
	// setfill�� �̿��Ͽ� setw�� ���� �Ҵ�� ��� ĭ ����ŭ ����� �� ���� �� 0���� �� ĭ�� ä��
	// universal �ð��̹Ƿ� 00:00:00~23:59:59 ���·� �ð��� ���
}

void Time::printStandard() // printStandard �Լ� ����
{
	cout << ((hour == 0 || hour == 12) ? 12 : hour % 12) << ":"
		// Standard �ð��� 0��~11�ñ��� ǥ�õǹǷ� 0���̰ų� 12���̸� 0�÷�, �ƴϸ� 12�� ���� 1���� 11������ �ð��� ��ȯ�ؾ��Ѵ�.
		<< setfill('0') << setw(2) << minute << ":" << setw(2)
		<< second << (hour < 12 ? " AM" : " PM") << endl; // hour�� 12���� ������ AM��, ũ�� PM�� ���
	// setfill�� �̿��Ͽ� setw�� ���� �Ҵ�� ��� ĭ ����ŭ ����� �� ���� �� 0���� �� ĭ�� ä��
	// Standard �ð��̹Ƿ� 0:00:00~11:59:59(AM/PM) ���·� �ð��� ���
}

int Time::tick() // tick �Լ� ����
{
	setSecond(second+1); // tick �Լ��� �ʸ� 1�� �ø��� �Լ��̹Ƿ� ���� second ���� 1�� ���� ���� second�� �� ���Ҵ�
	if (second == 0) // ���࿡ second�� 0�� �Ǹ� (59��->0��)�� �ǰ� ���� 1��ŭ �þ�� ��
	{
		setMinute(minute+1); // ���� second�� 0�� ���� �� minute�� 1�� ���� ���� minute�� �ٽ� ���Ҵ�
		if (minute == 0) // ���� minute�� 0�� �Ǹ� (59��->0��)�� �ǰ� �ð��� 1��ŭ �þ�� ��
		{
			setHour(hour+1); // ���� minute�� 0�� ���� �� hour�� 1�� ���� ���� hour�� �ٽ� ���Ҵ�
			if (hour == 0) // hour�� 1 ���� ���� 0�̶�� (23��->0��)�� �Ǵ� ���̹Ƿ� ��¥(day)�� �Ϸ� �þ�� ��
			{
				return 1; // main �Լ����� hour�� 0�� ���� �� day�� 1 �÷��ֱ� ���� 1�� return ����
				// return ���� 1�̸� day�� 1 �÷��ְ�, 0�̸� �״�� ���θ� ��
			}
		}
	}
	return 0; // return ���� 0�̸� day�� �ø��� �ʾƵ� ��
}