#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

#define mat vector<vector<double>>
#define row vector<double>

int zero_row(double arr[], int size); // ���� 0���� �̷���� ������ Ȯ�����ִ� �Լ�
void swap_row(double arr1[], double arr2[], int size); // arr1��� arr2���� �ٲ��ִ� �Լ�
void sort_array(double** arr, int size1, int size2, int count[]); // 2���� �迭�� leading-1�� ��ġ���� �������ִ� �Լ�

int zero_row(row& r); // ����� Ȯ�� �Լ�
int zero_mat(mat& m); // ��� �ȿ� �ִ� ����� ���� ��ȯ
int index_lead(row& r); // leading-1�� �ִ� ��ġ ��ȯ
int inconsistent(mat& m); // �ذ� �������� �ʴ��� Ȯ��
int consistent(mat& m); // �ذ� �����ϴ��� Ȯ��
int result(mat& m); // 3���� ���̽�(���� �� = 1, �ذ� ������ ���� = 2, ��x = 3) �з�
void print(mat& m); // ��� ��ȯ�Լ�
void sol(mat& m); // ���� ���� ��ȯ
void unique(mat& m); // �������ΰ��, �� ��ȯ
void infinite(mat& m); // ������ ���� ���, �� ��ȯ
int only_lead(row& r);

int main()
{
    int eq_num = 0; // ���� ����
    int var_num = 0; // ������ ����
    double pivot = 0; // ���� ����

    cout << "���� �������� �� ������ �Է��ϼ���." << endl; // �� ���� eq_num �Է¹ޱ�
    cin >> eq_num;
    cout << "������ ������ �Է��ϼ���." << endl; // ���� ���� var_num �Է¹ޱ�
    cin >> var_num;
    cout << "Augmented ����� �� ���� ������ ���ʴ�� �Է��ϼ���." << endl; // ����� �� ���ҵ��� �� �Է¹ޱ�

    double** linear_eq = new double* [eq_num]; // �� ����� ���� ���� 2���� �迭 ����
    for (int i = 0; i < eq_num; i++)
    {
        linear_eq[i] = new double[var_num + 1]; // 2���� �迭 �����Ҵ�
    }

    for (int i = 0; i < eq_num; i++) {
        for (int j = 0; j < var_num + 1; j++) {
            cin >> linear_eq[i][j]; // �� ��� ������ �Է� �ޱ�
        }
    }

    cout << endl << "�Է��� Augmented ���" << endl; // �Է¹��� �� ���� �� ���

    for (int i = 0; i < eq_num; i++) {
        for (int j = 0; j < var_num + 1; j++) {
            cout << setw(10) << linear_eq[i][j]; // �Է¹��� �� ���
        }
        cout << endl;
    }

    int* leading = new int[eq_num]; // �� ���� leading-1�� ��ġ�� ������ �迭 �����Ҵ�

    sort_array(linear_eq, eq_num, var_num, leading); // �������ִ� �Լ����� ���� �� �� ���� leading-1�� ��ġ ���� �迭�� �־��ִ� �Լ�

    cout << endl << "������ ���" << endl; // �Է¹��� ����� ������ �� �ѹ� �� ���

    for (int i = 0; i < eq_num; i++) {
        for (int j = 0; j < var_num + 1; j++) {
            cout << setw(10) << linear_eq[i][j]; // �Է¹��� �� ���
        }
        cout << endl;
    }

    for (int i = 0; i < eq_num; i++) { // row echelon form
        sort_array(linear_eq, eq_num, var_num, leading); // ���� �ٲ�鼭 ����� ������ �����ϱ� ���� for�� ��ܿ��� �ѹ��� �� ������
        pivot = linear_eq[i][leading[i]]; // ���� (leading-1�� �� ����)
        if (zero_row(linear_eq[i], var_num) == 1) {
            for (int j = 0; j < var_num + 1; j++) {
                linear_eq[i][j] /= pivot; // �纯�� ���� ������ �����ش�
                if (pivot < 0 && linear_eq[i][j] == 0) linear_eq[i][j] *= -1; // double data type���� 0�� ������ ������ �� -0�� ��µǴ� ���� ����
            }
        }
        for (int j = i + 1; j < eq_num; j++) {
            double lead = linear_eq[j][leading[i]]; // �� �࿡�� �� ���� �࿡ ������ �� ������ ���� (for���� ���鼭 ���� �ٲ�� ���� �����ϱ� ����)
            for (int k = i; k < var_num + 1; k++) {
                linear_eq[j][k] -= linear_eq[i][k] * lead; // ���� ������ ����� �� ���� ������ �����ذ� �ؿ� �Ŀ� ���ش�. (leading-1�� ���� ���� �ִ� ���� 0���� �����)
            }
        }
    }

    sort_array(linear_eq, eq_num, var_num, leading); // row echelong form�� ���� �� �ѹ� �� ����

    cout << "Row Echelon Form" << endl;

    for (int i = 0; i < eq_num; i++) {
        for (int j = 0; j < var_num + 1; j++) {
            cout << setw(10) << linear_eq[i][j]; // row echelon form ���
        }
        cout << endl;
    }
    cout << endl;

    double** pivot_arr = new double* [eq_num]; // �� ������ reduced row echelon form�� ���� ���ؼ� ���� �������� ������ 2���� �迭 ����
    for (int i = 0; i < eq_num; i++)
    {
        pivot_arr[i] = new double[var_num + 1]; // ������ ���� 2���� �迭 �����Ҵ�
    }

    for (int i = 1; i < eq_num; i++) { // reduced row echelon form
        sort_array(linear_eq, eq_num, var_num, leading); // ���� �ٲ�鼭 ����� ������ �����ϱ� ���� for�� ��ܿ��� �ѹ��� �� ������
        for (int a = 0; a < eq_num; a++) {
            for (int b = 0; b < var_num + 1; b++) {
                pivot_arr[a][b] = linear_eq[a][b]; // �� ������ �� ���� ���� ������ �� ������ ���� (for���� ���鼭 ���� �ٲ�� ���� �����ϱ� ����)
            }
        }
        for (int j = 0; j < i; j++) {
            for (int k = 0; k < var_num + 1; k++) {
                linear_eq[j][k] -= linear_eq[i][k] * pivot_arr[j][leading[i]]; // �� ���� ������ ���� ������ ����� �����ذ� �� �� ������ ���ش�.
            }
        }
    }

    cout << "Reduced Row Echelon Form" << endl;

    sort_array(linear_eq, eq_num, var_num, leading); // reduced row echelon form ������

    for (int i = 0; i < eq_num; i++) {
        for (int j = 0; j < var_num + 1; j++) {
            cout << setw(10) << linear_eq[i][j]; // ��� ���
        }
        cout << endl;
    }

    mat input;
    for (int i = 0; i < eq_num; i++)
    {
        row r;
        for (int j = 0; j < var_num + 1; j++) // ���� ũ��� ���� ���� + 1 �̹Ƿ� var + 1
        {
            r.push_back(linear_eq[i][j]);
        }
        input.push_back(r);
    }

    //print(input);

    sol(input);

    for (int i = 0;i < eq_num; i++) {
        delete[] linear_eq[i];
    }
    delete[] linear_eq;

    for (int i = 0;i < eq_num; i++) {
        delete[] pivot_arr[i];
    }
    delete[] pivot_arr;


    return 0;
}


int zero_row(row& r)
{
    for (int i = 0; i < r.size() - 1; ++i) // 0���� ������������(��� ������ �� ����)
    {
        if (r[i] != 0)
        {
            return -1; // 0�� �ƴ� �� �ϳ��� ������ -1�� return 
            // ������� �ƴ� ����
        }
    }
    return 0; // 0�� return�Ǹ� �ش� ���� ������� ����
    // ��������� Ȯ��
}

int zero_mat(mat& m)
{
    int count = 0; // ������� ����
    for (int i = 0; i < m.size(); i++) // 0���� �İ���-1 ���� 
    {
        if (zero_row(m[i]) == 0) // ���� ������̸�
        {
            count++; // ������� ������ �� ���� ����
        }
    }
    return count;
}

int index_lead(row& r) // leading-1�� ó�� ���� ���� �ε����� ��ȯ�ϴ� �Լ�
// 1�� ó������ ������ �װ��� leading-1�� ����
{
    for (int i = 0; i < r.size() - 1; i++) // 0��° ������ (������ ��-1)�� �������� (������ ���� �������� ������̹Ƿ� Ȯ�� �� �ʿ� ����)
    {
        if (r[i] == 1) // ó�� ���� 1�� ���� index ��ȯ
        {
            return i;
        }
    }
    return 0;
}

int inconsistent(mat& m)
{
    for (int i = 0; i < m.size(); i++) // 0���� �İ���-1 ���� 
    {
        if (zero_row(m[i]) == 0) // ���� m����� j���� ������ε�(������ �� ����)
        {
            if (m[i][m[0].size() - 1] != 0) // ����� j��(������� �κ�) ���������� 0�� �ƴϸ�
            {
                // ��� �߻�
                return -1;
            }
        }
    }
    return 0;
}


int consistent(mat& m)
{
    // ������� �ƴ� ������ ���� �� : m.size() - zero_mat(m)
    // ������ �� : m[0].size() - 1
    // [������� �ƴ� ������ ���� �� < ������ ��]�̸� �ذ� �������� �ʰ� ��
    if (m.size() - zero_mat(m) < m[0].size() - 1)
    {
        return 1; // �ذ� ������ ����
    }
    else
    {
        return 0; // ������(consistent �Լ��� �̿��ϱ� ���� inconsistent �Լ��� �̿��� ���̹Ƿ� �ذ� ���� ���� �̹� ���� ��)
    }
}

int result(mat& m)
{
    if (inconsistent(m) == -1) // ��ȯ���� -1�̸� �ش� reduced row echelon form�� �ذ� �������� �ʴ� ��
    {
        return 3; // �ذ� ���� ��쿡�� 3�� ��ȯ
    }
    else
    {
        if (consistent(m) == 1) // consistent�� ��ȯ���� 1�̸� �ذ� ������ ���� �����
        {
            return 2; // �ذ� ������ ���� ��쿡�� 2�� ��ȯ
        }
        else //consistent == 0�� ���(������)
        {
            return 1; // �������� ��쿡�� 1�� ��ȯ
        }
    }
}

void print(mat& m)
{
    for (int i = 0; i < m.size(); i++)
    {
        for (int j = 0; j < m[0].size(); j++)
        {
            cout << m[i][j] << " ";
        }
        cout << endl;
    }
}

void sol(mat& m)
{
    if (result(m) == 1) // return ���� 1�̸� ������
    {
        cout << "\n�������̴�" << endl;
        unique(m); // �������� ���� ���� ���� ����ϱ� ���� unique �Լ� �̿�
    }
    else if (result(m) == 2) // return ���� 2�̸� ������ ���� ��
    {
        cout << "\n�ذ� ������ ����" << endl;
        infinite(m); // �ذ� ������ ���� ���� ���� ���� ����ϱ� ���� infinite �Լ� �̿�
    }
    else // return ���� 3�̸� ��x
    {
        cout << "\n�ذ� �������� �ʴ´�" << endl;
    }
}

void unique(mat& m) // �������� ��� �ظ� ���
{
    for (int i = 0; i < m[0].size() - 1; i++)
    {
        cout << "X" << i + 1 << " = " << m[i][m[0].size() - 1] << endl;
    }
}

void infinite(mat& m) // �ذ� ������ ���� ��� �ظ� ���
{
    if (zero_mat(m) == m.size())
    {
        for (int i = 0; i < m[0].size() - 1; i++)
        {
            cout << "X" << i + 1 << " = " << "t" << i + 1 << endl;
        }
        return;
    }
    int* arr = new int[m[0].size() - 1]; // leading/free ���� �����ϱ� ���� �迭 ����
    for (int i = 0; i < m[0].size() - 1; i++)
    {
        arr[i] = 0; // �迭�� 0���� �ʱ�ȭ
    }
    for (int i = 0; i <= m.size() - zero_mat(m) - 1; i++) // ������� �ƴ� ������ ��(m.size() - zero_mat(m) - 1)���� ���� ù ��° ����� �������� �ö󰡸� �ظ� ����
    {
        arr[index_lead(m[i])] = 1; // leading 1�� �����ϴ� ������ leading �����̹Ƿ� 1�� �ٲ���
        cout << "X" << (index_lead(m[i]) + 1) << " = "; // ���� ���
        if (m[i][m[0].size() - 1] != 0 || only_lead(m[i]) == 0) /// ��ȣ(=) �������� ���� 0�̸� ����� �ʿ� �����Ƿ� ��� x, ��ȣ ������ ���� 0�� ��� �ش� �࿡ leading-1 �ϳ��� �����ϸ� 0�� ����ؾߵ�
        {
            cout << m[i][m[0].size() - 1];
        }
        //i�࿡�� leading-1�� ������ ���� ����
        //m[i][m[0].size() - 1]�� �ش� ���� �� ������ ���� ��ġ�ϴ� ��� ��
        for (int j = index_lead(m[i]) + 1; j < m[0].size() - 1; j++)
        {
            if (m[i][j] == 0) // m[i][j]�� 0�̸� ����� �ʿ䰡 �����Ƿ� ���x
            {
                continue;
            }
            if (m[i][j] < 0 && m[i][m[0].size() - 1] != 0) // m[i][j]�� ���� 0���� ���� ��� ������ ���� ��ȣ�� +�� �ǹǷ� ���� +�� ���
             //m[i][j]�� >0�� ��쿡�� ���� �Ǹ鼭 (-) ��ȣ�� �����Ƿ� ���� ������� �ʿ�x
            {
                cout << "+";
            }
            cout << -m[i][j] << "*t" << (j + 1); // m[i][j]�� (-)�� ���� ��(���� �Ǹ鼭 (-)�� ����)�� j+1��° ������ ��(*) ���
        }
        cout << endl;
    }
    for (int i = 0; i < m[0].size() - 1; i++) // free var ���
    {
        if (arr[i] == 0)
        {
            cout << "X" << i + 1 << " = " << "t" << i + 1 << endl;
        }
    }
    delete[] arr;
}

int zero_row(double arr[], int size) { // �迭���� �� �࿡ 0���� �̷���� �����ֳ� üũ���ִ� �Լ�
    for (int i = 0; i < size; i++) {
        if (arr[i] != 0) return 1; // 0�� �ƴ� ���� �ϳ��� ������ 1�� ��ȯ
    }
    return 0; // 0�� ���̸� 0�� ��ȯ
}

void swap_row(double arr1[], double arr2[], int size) { // �� ���� ��ġ�� ���� �ٲ��ִ� �Լ�
    double* alt = new double[size]; // �߰��� �ٲ� ���� �������ִ� �迭 �����Ҵ�
    for (int n = 0; n < size; n++) {
        alt[n] = arr1[n];
        arr1[n] = arr2[n];
        arr2[n] = alt[n];
    }
}
// sort_array(linear_eq, eq_num, var_num, leading);

void sort_array(double** arr, int size1, int size2, int count[]) { // �迭�� ������ �������ִ� �Լ����� �� ���� leading-1�� ��ġ�� �������ִ� �Լ�
    for (int i = 0; i < size1; i++) count[i] = 0;
    int colCount = 0; // �� ī����
    int rowCount = 0; // �� ī����
    while (rowCount < size1) { // �� ī���Ͱ� ���� �������� ���� �� ����
        colCount = 0; // �� ī���� �ʱ�ȭ
        while (colCount < size2) { // �� ī���Ͱ� ������ �������� ���� �� ����
            if (arr[rowCount][colCount] != 0) break; // �� ������ 0�� �ƴϸ� break, 0 �̸� ���� ������ �Ѿ (��, 0�� ������ ������)
            colCount++;
            count[rowCount]++;
        }
        rowCount++;
    }
    int temp = 0;
    int min_num = 0; //���������� ���� �ּڰ� �ε����� �����
    for (int j = 0; j < size1; j++) {
        min_num = j; //�� ��ġ�� �ּڰ� �ε����� �켱 �ʱ�ȭ
        for (int k = j + 1; k < size1; k++) {
            if (count[min_num] > count[k]) min_num = k; //���� �������� �ε����� ����
        }
        swap_row(arr[j], arr[min_num], size2 + 1); // �� ���� ��ġ �ٲ��ֱ�
        temp = count[j]; // ���� ��ġ�� �ٲ� ���� ���� �ٲ����� leadding-1�� ���� temp�� Ȱ���Ͽ� ��ġ �ٲٱ�
        count[j] = count[min_num];
        count[min_num] = temp;
    }
}

int only_lead(row& r) // �ش� �࿡ leading 1 ������ �ִ����� Ȯ���ϱ� ���� �Լ�
{
    for (int j = index_lead(r) + 1; j < r.size() - 1; j++)
    {
        if (r[j] != 0) // lead-1�� ���� �ڿ� �ϳ��� 0�� �ƴ� ���� ������ leading 1�� �ִ� �� x
        {
            return -1;
        }
    }
    return 0;
}