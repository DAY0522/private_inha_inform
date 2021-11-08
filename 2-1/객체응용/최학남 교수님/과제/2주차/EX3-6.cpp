#include<iostream>
#include<string>
using namespace std;

class Invoice // Invoice class�� �����Ѵ�.
{
public:
	Invoice(string Number, string Description, int Quantity, int Price) // Number, Description, Quantity, Price�� �ʱ�ȭ ���ֱ� ���� �����ڸ� �����Ѵ�.
	{
		number = Number; // �������� �μ��� �Էµ� Number�� class ��� �������� number�� �Է��Ѵ�.
		description = Description; // �������� �μ��� �Էµ� Description�� class ��� �������� description�� �Է��Ѵ�.
		if (Quantity < 0) // �������� �μ��� �Էµ� Quantity�� 0���� ������ ��ȿ���� ���� ���̹Ƿ�
		{
			cout << "quantity cannot be negative. quantity set to 0." << endl; // �Էµ� Quantity�� ������ ������ �ִٴ� ������ ������ص�
			quantity = 0; // 0���� �ʱ�ȭ�� ��Ų��.
		}
		else
		{
			quantity = Quantity; // ���࿡ Quantity�� 0 �̻��̸� ��ȿ�� ���̹Ƿ� �Էµ� �μ��� quantity�� �Է��Ѵ�.
		}
		if (Price < 0) // �������� �μ��� �Էµ� Price�� 0���� ������ ��ȿ���� ���� ���̹Ƿ�
		{
			cout << "price cannot be negative. price set to 0." << endl; // �Էµ� Price�� ������ ������ �ִٴ� ������ ������ص�
			price = 0; // 0���� �ʱ�ȭ�� ��Ų��.
		}
		else 
		{
			price = Price; // ���࿡ Price�� 0 �̻��̸� ��ȿ�� ���̹Ƿ� �Էµ� �μ��� price�� �Է��Ѵ�.
		}
		cout << "Invoice data members modified." << endl; // �� ������ ������ ��� ��� ������ �����Ǿ��ٴ� ������ ����Ѵ�.
		cout << endl;
	}
	// main �Լ������� ��� ������ ���� �ҷ��� �� �����Ƿ� ��� ���� ���� �̿��ϱ� ���� get�Լ��� �̿��Ѵ�.
	string get_N()  // string���� number�� ��ȯ���ִ� �Լ��� �����ϱ� ���� get_N�Լ��� �����Ѵ�.
	{
		return number; // number�� return �Ѵ�.
	}
	string get_D() // string���� description�� ��ȯ���ִ� �Լ��� �����ϱ� ���� get_D�Լ��� �����Ѵ�.
	{
		return description; // description�� return �Ѵ�.
	}
	int get_Q() // int���� quantity�� ��ȯ���ִ� �Լ��� �����ϱ� ���� get_Q�Լ��� �����Ѵ�.
	{
		return quantity; // quantity�� return �Ѵ�.
	}
	int  get_P() // int���� price�� ��ȯ���ִ� �Լ��� �����ϱ� ���� get_P�Լ��� �����Ѵ�.
	{
		return price; // price�� return �Ѵ�.
	}
	int getInvoiceAmount() // �� ��ǰ�� �ݾ��� ��ȯ�ϴ� �Լ��� getInvoiceAmount �Լ��� �����Ѵ�.
	{
		return quantity * price; // �� ��ǰ�� �ݾ��� ��ǰ�� ������ quantity�� ���� price�� ���� ���̹Ƿ� return ���ش�.
	}
private:
	string number; // ��ǰ�� ��ȣ�� number ��� ������ string ������ �����Ѵ�.
	string description; // ��ǰ�� ������ description ��� ������ string ������ �����Ѵ�.
	int quantity; // ��ǰ�� ������ quantity ��� ������ int������ �����Ѵ�.
	int price; // ��ǰ�� ������ price�� int������ �����Ѵ�.
};

int main()
{
	Invoice item1("12345", "Hammer", 100, 5); // Invoice�� ������ item1�� �����ϰ�, �����ڸ� �̿��Ͽ� ��ǰ�� �� �׸��� �ʱ�ȭ �Ѵ�.
	Invoice item2("123456", "Saw", -10, 10); // Invoice�� ������ item2�� �����ϰ�, �����ڸ� �̿��Ͽ� ��ǰ�� �� �׸��� �ʱ�ȭ �Ѵ�.

	cout << "Part number : " << item1.get_N() << endl; // item1�� number�� get_N �Լ��� return ���� �̿��� ����Ѵ�.
	cout << "Part description : " << item1.get_D() << endl; // item1�� description�� get_D �Լ��� return ���� �̿��� ����Ѵ�.
	cout << "Quantity : " << item1.get_Q() << endl; // item1�� quantity�� get_Q �Լ��� return ���� �̿��� ����Ѵ�.
	cout << "Price per item : $" << item1.get_P() << endl; // item1�� item �� price�� get_P �Լ��� return ���� �̿��� ����Ѵ�.
	cout << "Invoice amount : $" << item1.getInvoiceAmount() << endl; // item1�� �� ��ǰ �ݾ��� getInvoiceAmount �Լ��� �̿��� ����Ѵ�.
	cout << endl;

	cout << "Part number : " << item2.get_N() << endl; // item2�� number�� get_N �Լ��� return ���� �̿��� ����Ѵ�.
	cout << "Part description : " << item2.get_D() << endl; // item2�� description�� get_D �Լ��� return ���� �̿��� ����Ѵ�.
	cout << "Quantity : " << item2.get_Q() << endl; // item2�� quantity�� get_Q �Լ��� return ���� �̿��� ����Ѵ�.
	cout << "Price per item : $" << item2.get_P() << endl; // item2�� item �� price�� get_P �Լ��� return ���� �̿��� ����Ѵ�.
	cout << "Invoice amount : $" << item2.getInvoiceAmount() << endl; // item2�� �� ��ǰ �ݾ��� getInvoiceAmount �Լ��� �̿��� ����Ѵ�.
	cout << endl;
}