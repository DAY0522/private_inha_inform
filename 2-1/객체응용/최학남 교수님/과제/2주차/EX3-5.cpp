#include<iostream>
#include<string>
using namespace std;

class Account // Account class�� �����Ѵ�.
{
public:
	Account(int Balance, string Name) // ������ �ʱ� �ݾװ� ���¸��� �ʱ�ȭ ���ֱ� ���� �����ڸ� �����Ѵ�.
	{
		balance = Balance; // �������� �μ��� �Էµ� Balance�� class ��� �������� balance�� �Է��Ѵ�.
		name = Name; // �������� �μ��� �Էµ� Name�� class ��� �������� name�� �Է��Ѵ�.
	}
	void credit() // �Ա��� ���� ��� �Լ��� �����Ѵ�.
	{
		int M; // �Ա��� �ݾ��� ��Ÿ���� ���� M�� int������ �����Ѵ�.
		cout << "Enter deposit amount for " << name << " : "; // �Ա��� �ݾ��� �Է��϶�� ������ ����Ѵ�.
		cin >> M; // �Ա��� �ݾ��� ����ڿ��� �Է¹޴´�.
		cout << "attempting to deposit " << M << " from " << name << " balance" << endl; // ����ڰ� �Է��� �ݾ� ��ŭ �Ա� �õ� ���̶�� ������ ����Ѵ�.
		balance += M; // ����ڰ� $M�� �Ա������Ƿ� ������ �ݾ��� balance�� M�� �����ش�.
	}
	void debit() // ����� ���� ��� �Լ��� �����Ѵ�.
	{
		int M; // ����� �ݾ��� ��Ÿ���� ���� M�� int������ �����Ѵ�.
		cout << "Enter withdrawal amount for " << name << " : "; // ����� �ݾ��� �Է��϶�� ������ ����Ѵ�.
		cin >> M; // ����� �ݾ��� ����ڿ��� �Է¹޴´�.
		cout << "attempting to subtract " << M << " from " << name << " balance" << endl; // ����ڰ� �Է��� �ݾ� ��ŭ ��� �õ� ���̶�� ������ ����Ѵ�.
		if (balance < M) // ���� ����ڰ� �Է��� ��� �ݾ׺��� ���� �ܰ� �� ������ if���� true�� ��
		{
			cout << "Debit amount exceeded account balance." << endl; // ��� �ݾ��� ���� �ܰ� �ʰ��ߴٴ� ������ ����Ѵ�.
			return; // �ش� �Լ��� �����Ű�� ���� return �Ѵ�.
		}
		balance -= M; // ����ڰ� $M�� ��������Ƿ� ������ �ݾ��� balance�� M�� ���ش�.
	}
	int getBalance() // ���� ���� �ܰ� ��ȯ���ִ� GetBalance �Լ��� �����Ѵ�.
	{
		return balance; // ���� ���� �ܰ� ��Ÿ���� ��� ���� balance�� return �Ѵ�.
	}

private:
	int balance; // Account class ��� �Լ��� ���� �ܰ� ��Ÿ���� balance�� int������ �����Ѵ�.
	string name; // Account calss ��� �Լ��� ���� �̸��� ��Ÿ���� name�� string������ �����Ѵ�.
};

int main()
{
	Account account1(50, "account1"); // Account���� account1 ������ �����ϰ�, �����ڸ� �̿��� �ʱ� �ܰ� $50, ���¸��� account1�� �� ��� ������ �ʱ�ȭ �Ѵ�.
	Account account2(25, "account2"); // Account���� account2 ������ �����ϰ�, �����ڸ� �̿��� �ʱ� �ܰ� $25, ���¸��� account2�� �� ��� ������ �ʱ�ȭ �Ѵ�.

	cout << "account1 balance : $" << account1.getBalance() << endl; // getBalance �Լ��� return ���� ����� account1�� �ʱ� �ܰ� Ȯ���Ѵ�.
	cout << "account2 balance : $" << account2.getBalance() << endl; // getBalance �Լ��� return ���� ����� account2�� �ʱ� �ܰ� Ȯ���Ѵ�.

	account1.debit(); // debit �Լ��� �̿��� acccount1 ���¿� ����� �Ѵ�.

	cout << "account1 balance : $" << account1.getBalance() << endl; // ����� �� �ƴ��� Ȯ���ϱ� ���� getBalance �Լ��� return ���� �ٽ� ����� �Ա� ���� account1�� �ܰ� Ȯ���Ѵ�.
	cout << "account2 balance : $" << account2.getBalance() << endl; // ����� �� �ƴ��� Ȯ���ϱ� ���� getBalance �Լ��� return ���� �ٽ� ����� �Ա� ���� account2�� �ܰ� Ȯ���Ѵ�.

	account2.debit(); // debit �Լ��� �̿��� acccount2 ���¿� ����� �Ѵ�.

	cout << "account1 balance : $" << account1.getBalance() << endl; // ����� �� �ƴ��� Ȯ���ϱ� ���� getBalance �Լ��� return ���� �ٽ� ����� �Ա� ���� account1�� �ܰ� Ȯ���Ѵ�.
	cout << "account2 balance : $" << account2.getBalance() << endl; // ����� �� �ƴ��� Ȯ���ϱ� ���� getBalance �Լ��� return ���� �ٽ� ����� �Ա� ���� account1�� �ܰ� Ȯ���Ѵ�.

	return 0;
}
