#include <iostream>
#include <fstream>
#include <string>

const int MAX_SIZE = 100;

bool readMatrix(int matrix1[MAX_SIZE][MAX_SIZE], int matrix2[MAX_SIZE][MAX_SIZE], int& size, const std::string& filename) {
    std::ifstream file(filename);
    if(!file.is_open()){
        std::cerr<<"Error, file cannot be opened." << std::endl;
        return false;
    }
    file >> size;
    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size; ++j)
            file >> matrix1[i][j];
    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size; ++j)
            file >> matrix2[i][j];
    file.close();
    return 0;
}

void printMatrix(const int matrix[][MAX_SIZE], int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j)
            std::cout << matrix[i][j] << ' ';
        std::cout << '\n';
    }
    std::cout << '\n';
}

void addMatrices(const int matrixA[][MAX_SIZE], const int matrixB[][MAX_SIZE], int result[][MAX_SIZE], int size) {
    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size; ++j)
            result[i][j] = matrixA[i][j] + matrixB[i][j];
}

void multiplyMatrices(const int matrixA[][MAX_SIZE], const int matrixB[][MAX_SIZE], int result[][MAX_SIZE], int size) {
    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size; ++j) {
            int sum = 0;
            for (int k = 0; k < size; ++k)
                sum += matrixA[i][k] * matrixB[k][j];
            result[i][j] = sum;
        }
}

void subtractMatrices(const int matrixA[][MAX_SIZE], const int matrixB[][MAX_SIZE], int result[][MAX_SIZE], int size) {
    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size; ++j)
            result[i][j] = matrixA[i][j] - matrixB[i][j];
}

int main() {
    int size;
    int matrixA[MAX_SIZE][MAX_SIZE];
    int matrixB[MAX_SIZE][MAX_SIZE];
    int result[MAX_SIZE][MAX_SIZE];

    std::string filename= "matrix_input.txt";
    readMatrix(matrixA, matrixB, size, filename);

    std::cout << "Divit Kannan\nLab #6: Matrix manipulation\n";
    
    std::cout << "Matrix A:\n";
    printMatrix(matrixA, size);

    std::cout << "Matrix B:\n";
    printMatrix(matrixB, size);

    addMatrices(matrixA, matrixB, result, size);
    std::cout << "Matrix Sum (A + B):\n";
    printMatrix(result, size);

    multiplyMatrices(matrixA, matrixB, result, size);
    std::cout << "Matrix Product (A * B):\n";
    printMatrix(result, size);

    subtractMatrices(matrixA, matrixB, result, size);
    std::cout << "Matrix Difference (A - B):\n";
    printMatrix(result, size);

    return 0;
}
