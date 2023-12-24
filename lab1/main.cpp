#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    //одномерный массив
    //Объявить массив на 10 элементов в коде, вывести его на экран
    int array1[10];
    cout << "Массив из 10 элементов:";
    for (int i = 0; i < 10; ++i) {
        cout << " " << array1[i];
    }
    cout << endl;

    //Заполняем массив на 10 элементов случайными числами -10 до 10
    srand(time(0));
    int array2[10];
    cout << "Случайные числа (-10 до 10):";
    for (int i = 0; i < 10; ++i) {
        array2[i] = rand() % 21 - 10;
        cout << " " << array2[i];
    }
    cout << endl;

    //создаем массив на 5 элементов
    int array3[5];
    cout << "Введите 5 чисел для массива:" << endl;
    for (int i = 0; i < 5; ++i) {
        cin >> array3[i];
    }
    cout << "Введенные значения:";
    for (int i = 0; i < 5; ++i) {
        cout << " " << array3[i];
    }
    cout << endl;

    // массив с случайными элементами
    int array2_transformed[10];
    cout << "Преобразованный массив:";
    for (int i = 0; i < 10; ++i) {
        array2_transformed[i] = (array2[i] % 2 == 0) ? array2[i] * 3 : array2[i] * 5;
        cout << " " << array2_transformed[i];
    }
    cout << endl;

    // Работа с двумерным массивом

    // создаем двумерный массив 5x5
    int array2d[5][5];
    cout << "\nДвумерный массив 5x5:" << endl;
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            array2d[i][j] = rand() % 21 - 10;
            cout << array2d[i][j] << " ";
        }
        cout << endl;
    }

    // считаем сумму в каждой строке
    int row_sums[5] = {0};
    cout << "\nСумма в каждой строке:" << endl;
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            row_sums[i] += array2d[i][j];
        }
        cout << "Строка " << i + 1 << ": " << row_sums[i] << endl;
    }

    // заменяем отрицательные элементы на 0
    cout << "\nЗамена отрицательных элементов на 0:" << endl;
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
