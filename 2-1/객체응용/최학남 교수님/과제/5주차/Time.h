#include<iostream>

#ifndef TIME_H // #ifndef-#endif�� ���� Time class�� ���� ���Ǹ� ����
#define TIME_H

class Time {  // Time class ����
public: // ��� �Լ��� public���� ����
	Time(int = 0, int = 0, int = 0); // ������ ������Ÿ�� ����, ����Ʈ ���ڸ� �̿��� �ƹ��� ���� �Էµ��� �ʾ��� �� 0���� �ʱ�ȭ
	void setTime(int, int, int); // hour, minute, second�� ���� ���Ҵ��ϴ� setTime �Լ� ������Ÿ�� ����
	void setHour(int); // hour�� ���� ���Ҵ��ϴ� setHour �Լ� ������Ÿ�� ����
	void setMinute(int); // minute�� ���� ���Ҵ��ϴ� setMinute �Լ� ������Ÿ�� ����
	void setSecond(int); // second�� ���� ���Ҵ��ϴ� setSecond �Լ� ������Ÿ�� ����
	int getHour() const; // hour�� ���� ��ȯ�ϴ� getHour �Լ� ������Ÿ�� ����
	int getMinute() const; // minute�� ���� ��ȯ�ϴ� getMinute �Լ� ������Ÿ�� ����
	int getSecond() const; // secpnd�� ���� ��ȯ�ϴ� getSecond �Լ� ������Ÿ�� ����
	void printUniversal(); // Universal�� �ð��� print�ϴ� printUniversal �Լ� ����
	void printStandard(); // Standard�� �ð��� print�ϴ� printStandard �Լ� ����
	int tick(); // �Լ� ȣ�� �� �ʸ� 1�ʾ� �ø��� tick �Լ� ������Ÿ�� ����

private: // ��� ������ private���� ����
	int hour; // '��'�� ��Ÿ���� int�� ���� hour ����
	int minute; // '��'�� ��Ÿ���� int�� ���� minute ����
	int second; // '��'�� ��Ÿ���� int�� ���� second ����
};

#endif