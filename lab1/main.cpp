#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    //���������� ������
    //�������� ������ �� 10 ��������� � ����, ������� ��� �� �����
    int array1[10];
    cout << "������ �� 10 ���������:";
    for (int i = 0; i < 10; ++i) {
        cout << " " << array1[i];
    }
    cout << endl;

    //��������� ������ �� 10 ��������� ���������� ������� -10 �� 10
    srand(time(0));
    int array2[10];
    cout << "��������� ����� (-10 �� 10):";
    for (int i = 0; i < 10; ++i) {
        array2[i] = rand() % 21 - 10;
        cout << " " << array2[i];
    }
    cout << endl;

    //������� ������ �� 5 ���������
    int array3[5];
    cout << "������� 5 ����� ��� �������:" << endl;
    for (int i = 0; i < 5; ++i) {
        cin >> array3[i];
    }
    cout << "��������� ��������:";
    for (int i = 0; i < 5; ++i) {
        cout << " " << array3[i];
    }
    cout << endl;

    // ������ � ���������� ����������
    int array2_transformed[10];
    cout << "��������������� ������:";
    for (int i = 0; i < 10; ++i) {
        array2_transformed[i] = (array2[i] % 2 == 0) ? array2[i] * 3 : array2[i] * 5;
        cout << " " << array2_transformed[i];
    }
    cout << endl;

    // ������ � ��������� ��������

    // ������� ��������� ������ 5x5
    int array2d[5][5];
    cout << "\n��������� ������ 5x5:" << endl;
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            array2d[i][j] = rand() % 21 - 10;
            cout << array2d[i][j] << " ";
        }
        cout << endl;
    }

    // ������� ����� � ������ ������
    int row_sums[5] = {0};
    cout << "\n����� � ������ ������:" << endl;
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            row_sums[i] += array2d[i][j];
        }
        cout << "������ " << i + 1 << ": " << row_sums[i] << endl;
    }

    // �������� ������������� �������� �� 0
    cout << "\n������ ������������� ��������� �� 0:" << endl;
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            if (array2d[i][j] < 0) {
                array2d[i][j] = 0;
            }
            cout << array2d[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
