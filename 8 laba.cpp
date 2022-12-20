#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    cout << "Введите количество строк матрицы: ";
    int* line = new int;
    cin >> *line;

    cout << "Введите количество столбцов матрицы: ";
    int* columns = new int;
    cin >> *columns;

    int** matrix = new int* [*line];
    for (int i = 0; i < *line; i++) {
        matrix[i] = new int[*columns];
    }

    int* minElement = new int;
    *minElement = INT32_MAX;

    int* minelementColumn = new int;
    for (int i = 0; i < *line; i++) {
        for (int j = 0; j < *columns; j++) {
            int* element = new int;
            cout << "Введите элемент матрицы [" << i << "][" << j << "]: ";
            cin >> *element;
            matrix[i][j] = *element;

            if (*element < *minElement) {
                *minElement = *element;
                *minelementColumn = j;
            }
        }
    }

    for (int i = 0; i < *line; i++) {
        for (int j = 0; j < *columns; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    cout << "Миниммальный элемент матрицы: " << *minElement << endl;
    delete[] minElement;
    for (int i = 0; i < *line; ++i) {
        if (matrix[i][*minelementColumn] < 0) {
            matrix[i][*minelementColumn] = 0;
        }
    }
    delete[] minelementColumn;

    for (int i = 0; i < *line; i++) {
        for (int j = 0; j < *columns; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }


    for (int i = 0; i < *line; i++) {
        delete matrix[i];
    }

    delete[] matrix;


    return 0;
}
