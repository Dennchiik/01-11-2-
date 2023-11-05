#include <iostream>

void transposeMatrix(int** matrix, int& rows, int& columns) {
    int** transposedMatrix = new int* [columns];
    for (int i = 0; i < columns; i++) {
        transposedMatrix[i] = new int[rows];
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            transposedMatrix[j][i] = matrix[i][j];
        }
    }

    for (int i = 0; i < rows; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;

    std::swap(rows, columns);

    matrix = transposedMatrix;
}

int main() {
    int rows = 3;
    int columns = 4;
    int** matrix = new int* [rows];
    for (int i = 0; i < rows; i++) {
        matrix[i] = new int[columns];
    }

    int value = 1;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            matrix[i][j] = value;
            value++;
        }
    }

    std::cout << "Исходная матрица:" << std::endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }

    transposeMatrix(matrix, rows, columns);

    std::cout << "Транспонированная матрица:" << std::endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }

    for (int i = 0; i < rows; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}
