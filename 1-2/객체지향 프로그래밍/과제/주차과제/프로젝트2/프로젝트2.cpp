#include<iostream>
#include<stdlib.h>
#include<string>
#pragma warning(disable:4996)

using namespace std;

#define BOOK 10 // BOOK ����� 10���� ����
#define MEMBER 5 // MEMBER ����� 5���� ����
#define MAX 500 // �迭�� ũ�⸦ �÷��� MAX ����� 500���� ����

struct book { // ����ü book ����
	int id;
	char name[30];
};
book books[BOOK] = {0}; //book �ڷ��� �迭 ����

struct member { // ����ü member ����
	int id;
	char name[30];
};
member members[MEMBER] = { 0 }; //member �ڷ��� �迭 ����

struct borrow { // ����ü borrow ����
	int mid;
	char mname[30];
	int bid;
	char bname[30];
};
borrow borrows[MEMBER] = { 0 }; //borrows �ڷ��� �迭 ����

book books_f[BOOK + MAX] = { 0 }; //book �ڷ��� �迭 ����
member members_f[MEMBER + MAX] = { 0 }; //member �ڷ��� �迭 ����
borrow borrows_f[MEMBER + MAX] = { 0 }; //borrows �ڷ��� �迭 ����

int main()
{
	FILE* fbook = NULL; // å id�� �̸��� ������ fbook ���� ����
	int b_id, m_id; // case������ å id�� ȸ�� id�� �Է¹��� �� �̿��� ���� ����
	int now_b = BOOK, now_m = MEMBER; // ���� ��ϵ� å, ȸ�� ���� ���� ��, ��� BOOK�� MEMBER�� ����
	int index_b, index_m; // ����, �ݳ� �� å�� ȸ���� �ε����� �̿��� ���� ����

	// book.txt�� ���� �Է�
	fopen_s(&fbook, "book.txt", "w"); // book.txt ������ �б� ���� ��
	if (fbook == NULL) // fbook�� NULL�̸� ������ ����� ������ ���� ���̹Ƿ� error �޽��� �߻�
	{
		fprintf(stderr, "can not open the %s file.\n", "book.txt");
		exit(1);
	}
	for (int i = 0; i < BOOK; i++) // ó���� �Է¹��� å�� ������ 10���̹Ƿ� for���� ������ i=0���� BOOK���� ���� �������� ����
	{
		int num = 0; // å id�� �Է¹��� num�� ����
		while (num <= 0)
		{
			cout << "å ��ȣ�� �Է��ϼ���" << endl;
			cin >> num; // å ��ȣ num�� �Է� ����
			if (num <= 0) // num�� 0 ������ ���� ������ error�޽��� �߻� �� �ٽ� �Է� �޵��� ��.
			{
				cout << "�߸��� ��ȣ�� �Է��߽��ϴ�. �ٽ� �Է����ּ���" << endl;
			}
			for (int j = 0; j < BOOK; j++)
			{
				if (((books_f + j)->id) == num) // books �� index ���� num�� �������� Ȯ���ϴ� �ڵ� �����ϴٸ� ��ø id�� �߻��ϴ� ���̹Ƿ� error �޽��� �߻� �� �ٽ� �Է� �޵��� ��.
				{
					cout << "�̹� �����ϴ� å ��ȣ�Դϴ�. �ٽ� �Է����ּ���." << endl;
					num = 0;
					break;
				}
			}
		}
		(books_f + i)->id = num; // while���� ���������� �� å�� id�� ������ ���� ���̹Ƿ� �� �迭�� �ε��� ���� id ����Լ��� ������ num�� ����
		cout << "å �̸��� �Է��ϼ���" << endl;
		cin >> (books_f + i)->name; // ���� å �̸��� �Է� �޾� �� �迭�� �ε��� ���� name ����Լ��� ������ name�� �Է¹���
		fprintf(fbook, "%d %s\n", (books_f + i)->id, (books_f + i)->name); // ���� book.txt ���Ͽ� å�� ��ȣ �� �̸��� ����
	}
	fclose(fbook); // fbook ���� close


	FILE* fmem = NULL;

	fopen_s(&fmem, "member.txt", "w"); // member.txt ������ �б� ���� ��
	if (fmem == NULL) // fmem�� NULL�̸� ������ ����� ������ ���� ���̹Ƿ� error �޽��� �߻�
	{
		fprintf(stderr, "can not open the %s file.\n", "member.txt");
		exit(1);
	}
	for (int i = 0; i < MEMBER; i++) // ó���� �Է¹��� ȸ���� ���� 5���̹Ƿ� for���� ������ i=0���� MEMBER���� ���� �������� ����
	{
		int num = 0; // å id�� �Է¹��� num�� ����
		while (num <= 0) // num�� 0 ������ ���� ������ error�޽��� �߻� �� �ٽ� �Է� �޵��� ��.
		{
			cout << "ȸ�� ��ȣ�� �Է��ϼ���" << endl;
			cin >> num; // ȸ�� ��ȣ num�� �Է� ����
			if (num <= 0) // num�� 0 ������ ���� ������ error�޽��� �߻� �� �ٽ� �Է� �޵��� ��.
			{
				cout << "�߸��� ��ȣ�� �Է��߽��ϴ�. �ٽ� �Է����ּ���" << endl;
			}
			for (int j = 0; j < MEMBER; j++)
			{
				if (((members_f + j)->id) == num) // members�� �� index ���� num�� �������� Ȯ���ϴ� �ڵ� �����ϴٸ� ��ø id�� �߻��ϴ� ���̹Ƿ� error �޽��� �߻� �� �ٽ� �Է� �޵��� ��.
				{
					cout << "�̹� �����ϴ� ȸ�� ��ȣ�Դϴ�. �ٽ� �Է����ּ���." << endl;
					num = 0;
					break;
				}
			}
		}
		(members_f + i)->id = num; // while���� ���������� �� ȸ���� id�� ������ ���� ���̹Ƿ� �� �迭�� �ε��� ���� id ����Լ��� ������ num�� ����
		cout << "ȸ�� �̸��� �Է��ϼ���" << endl;
		cin >> (members_f + i)->name; // ���� ȸ�� �̸��� �Է� �޾� �� �迭�� �ε��� ���� name ����Լ��� ������ name�� �Է¹���
		fprintf(fmem, "%d %s\n", (members_f + i)->id, (members_f + i)->name); // ���� member.txt ���Ͽ� å�� ��ȣ �� �̸��� ����
	}
	fclose(fmem); // fmem ���� close

	FILE* fman = NULL; // manage.txt ������ �ּҸ� �ҷ��� FILE*�� ���� fman ����

	while (1)
	{
		int menu; // �� �޴��� �з��ϱ� ���� �̿��� menu ���� ����
		int c = 0; // �� case������ ���� �߻� ��Ȳ�� �������� �̿��ϴ� ���� c ���� �� 0���� �ʱ�ȭ
		cout << "�޴��� �Է��ϼ���" << endl;
		cout << "1.quit\n2.book show\n3.book modify\n4.book remove\n5.add a book\n6.member show\n7.member modify\n8.member remove\n9.add a member\n10.borrow\n11.return\n";
		cin >> menu; // ���� ���� �ý����� �� �޴��� ���� ���� menu �Է�
		switch (menu) // ���� ���� �ý����� �з����� switch�� �Է�
		{
		// quit
		case 1:
			fopen_s(&fbook, "book.txt", "w"); // book �ؽ�Ʈ ������ ������� �ҷ�����
			if (fbook == NULL) // fbbok�� NULL�̸� ������ ����� �ҷ������� ���� ���̹Ƿ� error �޽��� �߻�
			{
				fprintf(stderr, "can not open the %s file.\n", "book.txt");
				exit(1);
			}

			fopen_s(&fmem, "member.txt", "w"); // member �ؽ�Ʈ ������ ������� �ҷ�����
			if (fmem == NULL) // fmem�� NULL�̸� ������ ����� �ҷ������� ���� ���̹Ƿ� error �޽��� �߻�
			{
				fprintf(stderr, "can not open the %s file.\n", "book.txt");
				exit(1);
			}

			for (int i = 0; i < now_b; i++) // for���� ������ i�� 0�� ������ ���� å�� ������ now_b���� ����
			{
				if (((books_f + i)->id) == 0) // ���࿡ books �迭�� �� �ε����� id ��������� 0���� �� ������ ������ å�̹Ƿ� ���Ͽ� �Է����� ���ƾ��ϹǷ� continue.
				{
					continue;
				}
				fprintf(fbook, "%d %s\n", (books_f + i)->id, (books_f + i)->name); // if���� �������� ���� id ������, �� NULL���� �ƴ� �����鿡 ���ؼ��� id�� name�� ���Ͽ� �Է�
			}

			for (int i = 0; i < now_m; i++) // for���� ������ i�� 0�� ������ ���� ȸ���� ���� now_m���� ����
			{
				if (((members_f + i)->id) == 0) // ���࿡ members �迭�� �� �ε����� id ��������� 0���� �� ������ ������ ȸ���̹Ƿ� ���Ͽ� �Է����� ���ƾ��ϹǷ� continue.
				{
					continue;
				}
				fprintf(fmem, "%d %s\n", (members_f + i)->id, (members_f + i)->name); // if���� �������� ���� id ������, �� NULL���� �ƴ� �����鿡 ���ؼ��� id�� name�� ���Ͽ� �Է�
			}

			fclose(fbook); // book.txt������ ��� �̿������Ƿ� close
			fclose(fmem); // book.txt������ ��� �̿������Ƿ� close
			cout << "���α׷��� �����մϴ�. �̿����ּż� �����մϴ�." << endl;

			exit(1); // quit�ý����̹Ƿ� ���α׷��� ����
			break;


		// book show
		case 2:
			cout << "å ����� ����մϴ�" << endl;
			for (int i = 0; i < now_b; i++) // 
			{
				if (((books_f + i)->id) == 0) // id�� 0 �̸� ������ å�̹Ƿ� continue�� �̿��� ����� ����
				{
					continue;
				}
				cout << (books_f + i)->id << "-" << (books_f + i)->name << endl; // å�� ��ȣ�� �̸� ���
			}
			break;


		// book modify
		case 3:
			fopen_s(&fbook, "book.txt", "w+");// book.txt������ ������� �ҷ���
			if (fbook == NULL)
			{
				fprintf(stderr, "can not open the %s file.\n", "book.txt");
				exit(1);
			}

			while (c<=0) // c�� 0���� ������ å�� ��ȣ�� ����� �Է��� �� �� ���̹Ƿ� ��ȣ�� �ٽ� �Է¹޵��� ��
			{
				cout << "������ å�� ��ȣ�� �Է��ϼ���" << endl;
				cin >> b_id; // ������ å��ȣ �Է�
				for (int i = 0; i < now_b; i++) // for���� ���� b_id�� ������ å ��ȣ�� �ִ��� Ȯ��
				{
					if (((books_f + i)->id) == b_id) // ������ å��ȣ�� ������ å ��ȣ�� �Է¹ް� while���� ���������� ���� c++�� ����
					{
						cout << "������ å �̸��� �Է��ϼ���" << endl;
						cin >> (books_f + i)->name;
						c++;
						break;
					}
				}
				if (c<=0) // c�� 0���� ������ ������ å ��ȣ�� ���� ���̹Ƿ� å ��ȣ�� �ٽ� �Է� ����
				{
					cout << "�߸��� å ��ȣ�� �Է��ϼ̽��ϴ�. �ٽ� �Է����ּ���." << endl;
				}
			}
			for (int i = 0; i < now_b; i++) 
			{
				fprintf(fbook, "%d %s\n", (books_f + i)->id, (books_f + i)->name); // ���Ͽ� ������ å ��ȣ��, ������ å �̸��� ����
			}
			fclose(fbook);
			break;


		// book remove
		case 4:
			fopen_s(&fbook, "book.txt", "w+"); // book.txt ������ �б� �� ���� ������� �ҷ���
			if (fbook == NULL)
			{
				fprintf(stderr, "can not open the %s file.\n", "book.txt");
				exit(1);
			}

			while (c <= 0) // c�� 0���� ������ å�� ��ȣ�� ����� �Է��� �� �� ���̹Ƿ� ��ȣ�� �ٽ� �Է¹޵��� ��
			{
				cout << "������ å�� ��ȣ�� �Է��ϼ���" << endl;
				cin >> b_id;
				for (int i = 0; i < now_b; i++)
				{
					if (((books_f + i)->id) == b_id) // �Է��� ������ ��ȣ��, ������ �����ϴ� å�� id�� ��ġ�ϸ�
					{
						c++; // while���� ���� ������ ���� c++�� ����
						(books_f + i)->id = 0; // ������ ���� ���̹Ƿ� id�� 0�� �Է�
						strcpy((books_f + i)->name, " "); // �������� ���̹Ƿ� name�� ���� �Է�
						break;
					}
				}
				if (c <= 0) // ���� c�� 0���� �۰ų� ������ å ��ȣ�� ����� �Է��� ���� ���� ���̹Ƿ� 
				{
					cout << "�߸��� å ��ȣ�� �Է��ϼ̽��ϴ�. �ٽ� �Է����ּ���." << endl;
				}
			}

			for (int i = 0; i < now_b; i++) 
			{
				if (((books_f + i)->id) == 0) // ���� id���� 0�̸� ������ id�̹Ƿ� continue
				{
					continue;
				}
				fprintf(fbook, "%d %s\n", (books_f + i)->id, (books_f + i)->name); // continue�� ���� ���� id�� ���ؼ��� ��ȣ�� å �̸��� ���Ͽ� ����
			}
			cout << "���� �Ϸ� �ƽ��ϴ�." << endl; // ���� �Ϸ� ���� ���

			fclose(fbook);
			break;


		// add a book
		case 5:
			fopen_s(&fbook, "book.txt", "w+"); // txt������ �б�/���� ���� ��
			if (fbook == NULL)
			{
				fprintf(stderr, "can not open the %s file.\n", "book.txt"); 
				exit(1);
			}

			while (1)
			{
				cout << "�߰��� å�� ��ȣ�� �Է��ϼ���" << endl;
				cin >> b_id; // �߰��� å ��ȣ�� �Է�
				for (int i = 0; i < now_b; i++)
				{
					if (b_id <= 0 || ((books_f + i)->id) == b_id) // ���� �߰��� å id�� �����ų�, �̹� �����ϸ� �ٽ� �Է� ����
					{
						cout << "�߸��ưų� �̹� �����ϴ� å ��ȣ�Դϴ�. �ٽ� �Է����ּ���." << endl;
						break;
					}
					c++; // if���� ������� ������ �ƹ��� ������ ���� å id�̹Ƿ� c�� ������Ŵ
				}

				if (c==now_b) // c�� ���� å�� ���� �����ϸ�, �Է¹��� b_id�� ���� ������ ���� ���̹Ƿ� while���� break ���� ��������
				{
					break;
				}
			}

			now_b++; // add�� �����Ƿ� å�� �� �� �߰���, �׷��Ƿ� now_b�� 1 ������Ŵ
			cout << "�߰��� å �̸��� �Է��ϼ���" << endl;
			(books_f + (now_b-1))->id = b_id; // ���� now_b-1 �ε����� id�� ������ �Է¹��� �߰��� id�� ���� �Է�����.
			cin >> (books_f + (now_b - 1))->name; // ���� �߰��� å �̸��� �Է¹���
			for (int i = 0; i < now_b; i++)
			{
				fprintf(fbook, "%d %s\n", (books_f + i)->id, (books_f + i)->name); // for���� �̿��� �迭�� �Էµ� id�� name�� ���Ͽ� �Է���
			}
			cout << "�߰� �Ϸ� �ƽ��ϴ�." << endl; // �߰� �Ϸ� ���� ���

			fclose(fbook);
			break;


		// member show
		case 6: // case 2�� ���� ����
			cout << "ȸ�� ����� ����մϴ�" << endl;
			for (int i = 0; i < now_m; i++)
			{
				if (((members_f + i)->id) == 0)
				{
					continue;
				}
				cout << (members_f + i)->id << "-" << (members_f + i)->name << endl;
			}
			break;


		// member modify
		case 7: // case 3�� ���� ����
			fopen_s(&fmem, "member.txt", "w+");
			if (fmem == NULL)
			{
				fprintf(stderr, "can not open the %s file.\n", "member.txt");
				exit(1);
			}

			while (c <= 0)
			{
				cout << "������ ȸ���� ��ȣ�� �Է��ϼ���" << endl;
				cin >> m_id;
				for (int i = 0; i < now_m; i++)
				{
					if (((members_f + i)->id) == m_id)
					{
						c++;
						break;
					}
				}
				if (c <= 0)
				{
					cout << "�߸��� ȸ�� ��ȣ�� �Է��ϼ̽��ϴ�. �ٽ� �Է����ּ���." << endl;
				}
			}
			for (int i = 0; i < now_m; i++)
			{
				if (((members_f + i)->id) == m_id)
				{
					cout << "������ ȸ�� �̸��� �Է��ϼ���" << endl;
					cin >> (members_f + i)->name;
				}
			}
			for (int i = 0; i < now_m; i++)
			{
				fprintf(fmem, "%d %s\n", (members_f + i)->id, (members_f + i)->name);
			}

			fclose(fmem);
			break;


		// member remove
		case 8: // case 4�� ���� ����
			fopen_s(&fmem, "member.txt", "w+");
			if (fmem == NULL)
			{
				fprintf(stderr, "can not open the %s file.\n", "member.txt");
				exit(1);
			}

			while (c <= 0)
			{
				cout << "������ ȸ���� ��ȣ�� �Է��ϼ���" << endl;
				cin >> m_id;
				for (int i = 0; i < now_m; i++)
				{
					if (((members_f + i)->id) == m_id)
					{
						c++;
						(members_f + i)->id = 0;
						strcpy((members_f + i)->name, " ");
						break;
					}
				}
				if (c <= 0)
				{
					cout << "�߸��� ȸ�� ��ȣ�� �Է��ϼ̽��ϴ�. �ٽ� �Է����ּ���." << endl;
				}
			}

			for (int i = 0; i < now_b; i++)
			{
				if (((members_f + i)->id) == 0)
				{
					continue;
				}
				fprintf(fmem, "%d %s\n", (members_f + i)->id, (members_f + i)->name);
			}
			cout << "���� �Ϸ� �ƽ��ϴ�." << endl;

			fclose(fmem);
			break;


		// add a member
		case 9: // case 5�� ���� ����
			fopen_s(&fmem, "member.txt", "w+");
			if (fmem == NULL)
			{
				fprintf(stderr, "can not open the %s file.\n", "member.txt");
				exit(1);
			}

			while (1)
			{
				cout << "�߰��� ȸ���� ��ȣ�� �Է��ϼ���" << endl;
				cin >> m_id;
				for (int i = 0; i < now_m; i++)
				{
					if (m_id <= 0 || ((books_f + i)->id) == m_id)
					{
						cout << "�߸��ưų� �̹� �����ϴ� å ��ȣ�Դϴ�. �ٽ� �Է����ּ���." << endl;
						break;
					}
					c++;
				}

				if (c == now_m)
				{
					break;
				}
			}

			now_m++;
			cout << "�߰��� ȸ�� �̸��� �Է��ϼ���" << endl;
			(members_f + (now_m - 1))->id = m_id;
			cin >> (members_f + (now_m - 1))->name;
			for (int i = 0; i < now_m; i++)
			{
				fprintf(fmem, "%d %s\n", (members_f + i)->id, (members_f + i)->name);
			}
			cout << "�߰� �Ϸ� �ƽ��ϴ�." << endl;

			fclose(fmem);
			break;


		// borrow
		case 10:
			fopen_s(&fman, "manage.txt", "a+"); // ������ �߰� ���� ���� ��
			if (fmem == NULL) // ���� ���� ���н� ���� ���� ���� ���� ���
			{
				fprintf(stderr, "can not open the %s file.\n", "manage.txt");
				exit(1);
			}

			int borrow_m, borrow_b; // ���� ȸ���� å�� id�� �Է��� ���� ����
			while (c <= 0) // c�� 0�����̸� �Է¹��� id�� ���� ������ �ִ� ���̹Ƿ� �ٽ� �Է� ����
			{
				cout << "������ ȸ���� ��ȣ�� �Է��ϼ���" << endl;
				cin >> borrow_m; // ������ ȸ���� ��ȣ �Է�
				for (int i = 0; i < now_m; i++)  // for���� �̿��� ������ �Է¹��� id�� ���� ȸ�� id�� ��ġ�ϴ����� Ȯ��
				{
					if (((members_f + i)->id) == borrow_m) // ������ �Է¹��� ���̵�� ������ ȸ�� id�� �����ϸ�
					{
						if ((borrows_f + i)->mid != 0) // ���� borrows_f�� mid���� 0�� �� ���� ������ �̹� ���� ���� ȸ���̹Ƿ� 
						{
							cout << "�̹� ���� ���Դϴ�. �ݳ� �� �ٽ� �̿����ּ���." << endl; // �ݳ� �� �ٽ� �̿��ش޶�� �޽��� ���
							break;
						}
						index_m = i; // ���࿡ �������� ȸ���� �ƴϸ�
						c++; // �Է¹��� id�� ������ �����Ƿ� while���� ����� ���� c++�� ����
						(borrows_f + i)->mid = (members_f + i)->id; // ���� ������ �Է��� id�� ���� ������ index�� borrows_f �迭�� mid ��� ������ �־���
						strcpy((borrows_f + i)->mname, (members_f + i)->name); // ���� ������ ����� �̸��� ������ index�� borrows_f �迭�� mname ��� �����־���
						break;
					}
				}
				if (c <= 0) // ���� c�� 0�����̸� �߸��� id�� �Է¹��� ���̹Ƿ� ���� �޽��� ���
				{
					cout << "�߸��� ȸ�� ��ȣ�� �Է��ϼ̽��ϴ�. �ٽ� �Է����ּ���." << endl;
				}
			}

			c = 0;
			while (c <= 0) 
			{
				cout << "������ å�� ��ȣ�� �Է��ϼ���" << endl;
				cin >> borrow_b; // ������ å�� ��ȣ�� �Է�
				for (int j = 0; j < now_m; j++)
				{
					if (((borrows_f + j)->bid == borrow_b)) // ���࿡ borrows_f�� ����Լ��� bid�� borrow_b�� �����ϸ� �̹� ������ �ִ� å��
					{
						cout << "�̹� ���� ���� å�Դϴ�. �ٸ� å�� �Է����ּ���" << endl; // �̹� �������� å�� ���� �� �����Ƿ� �ٽ� �Է��ش޶�� ���� �Է�
						c--; // c--�� �� ���ָ� �Ʒ� for������ c++�� �Ǿ� �ٽ� while���� ������� �����Ƿ� �������
						break;
					}
				}
				for (int i = 0; i < now_b; i++) // �Է��� å ��ȣ�� ������ �����ϴ� å ��ȣ���� for���� ���� Ȯ��
				{
					if (((books_f + i)->id) == borrow_b) // ���� å ��ȣ�� �����ϴٸ� ������ �����ϴ� å�̹Ƿ� ������ ����
					{
						index_b = i; // i�� for�������� ��� ������ �������� �̹Ƿ� for�� �ۿ��� ����ϱ� ���� index_b ���� ���� ����
						(borrows_f + i)->bid = borrow_b; // å id�� borrow_f�� ������ �ε����� bid ��� ������ �Է�
						strcpy((borrows_f + i)->bname, (books_f + i)->name); // å id�� borrow_f�� ������ �ε����� bname ��� ������ �Է�
						c++; // while���� ���� ������ ���� c++�� ����
						break;
					}
				}
				if (c <= 0) // ���࿡ c�� 0 ���ϸ� ������ �����ϴ� å�� �ƴϹǷ�, �ٽ� �Է��϶�� ������ ���
				{
					cout << "�߸��� å ��ȣ�� �Է��ϼ̽��ϴ�. �ٽ� �Է����ּ���." << endl;
				}
			}


			fprintf(fman, "å ��ȣ/�̸� : %d/%s, ������ ��ȣ/�̸� : %d/%s\n", (borrows_f + index_b)->bid, (borrows_f + index_b)->bname, (borrows_f + index_b)->mid, (borrows_f + index_b)->mname);
			// ���� while���� ����������, ������ �����Ƿ�, ������ �Է¹��� ������ å id, �̸�, ������ id, �̸��� ���Ͽ� �Է���

			cout << "���� �Ϸ��߽��ϴ�. �̿����ּż� �����մϴ�.\n"; // ���� �Ϸ� �޽��� ���

			fclose(fman);
			break;


		// return
		case 11:
			fopen_s(&fman, "manage.txt", "a+"); // manage.txt ������ �߰����� ���� ��
			if (fmem == NULL)
			{
				fprintf(stderr, "can not open the %s file.\n", "manage.txt");
				exit(1);
			}

			int return_m; // �ݳ��� ȸ���� id �� �ݳ��� å�� id�� �Է¹ޱ� ���� ���� ����
			while (c <= 0) // c�� 0���ϸ� �Է��� id�� ���� ������ �ִ� ���̹Ƿ� �ݺ����� ���� id�� �ٽ� �Է� �ް� ��
			{
				cout << "�ݳ��� ȸ���� ��ȣ�� �Է��ϼ���" << endl;
				cin >> return_m; // �ݳ��� ȸ���� ��ȣ�� �Է¹��� 
				for (int i = 0; i < now_m; i++)
				{
					if (((borrows_f + i)->bid) != 0 && ((members_f + i)->id) == return_m) // ���� ȸ���� ��ȣ�� ������ borrows_f�� �ִ� mid ���� ��ġ�ϸ� ������ ������ ���� �ִ� ����
					{
						index_m = i; // i�� for�������� ��� ������ �������� �̹Ƿ� for�� �ۿ��� ����ϱ� ���� index_m ���� ���� ����
						c++; // if���� ����ϸ� �Էµ� ȸ�� ��ȣ�� ���� ������ ���� ���̹Ƿ� c++�� �Ͽ� while���� ������������ ��
						break;
					}
				}
				if (c <= 0)
				{
					cout << "�߸��� ȸ�� ��ȣ�� �Է��ϼ̽��ϴ�. �ٽ� �Է����ּ���." << endl;
				}
			}

			fprintf(fman, "å ��ȣ/�̸� : %d/%s, �ݳ��� ��ȣ/�̸� : %d/%s  (�ݳ�)\n", (borrows_f + index_m)->bid, (borrows_f + index_m)->bname, (borrows_f + index_m)->mid, (borrows_f + index_m)->mname);
			// �տ��� �ݳ��� å�� �ݳ����� �̸��� ���Ͽ� �Է�����

			(borrows_f + index_m)->mid = 0; // �ݳ��� å�� ���� �ε����� �ش��ϴ� ȸ���� ��ȣ�� 0�� �־���
			strcpy((borrows_f + index_m)->mname, " "); // �ݳ��� å�� ���� �ε����� �ش��ϴ� ȸ���� �̸��� ������ �־���
			(borrows_f + index_m)->bid = 0; // �ݳ��� å�� ���� �ε����� �ش��ϴ� å�� ��ȣ�� 0�� �־���
			strcpy((borrows_f + index_m)->bname, " "); // �ݳ��� å�� ���� �ε����� �ش��ϴ� å�� �̸��� ������ �־���

			cout << "�ݳ� �Ϸ��߽��ϴ�. �̿����ּż� �����մϴ�.\n"; // �ݳ� �Ϸ� ���� ���

			fclose(fman);
			break;

		default:
			cout << "�߸��� �޴��� �����߽��ϴ�. �ٽ� �Է����ּ���" << endl; // menu�� 1~11�� �ƴ� �ٸ� ���� �Է��ϸ�, ���� �ý����̹Ƿ� ���� ���� ���
			break;
		}
	}

	return 0;
}