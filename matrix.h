//
// Created by rudri on 3/23/2022.
//

#ifndef PROG3_UNIT1_TAREA_INTRODUCTORIA_V2022_1_MATRIX_H
#define PROG3_UNIT1_TAREA_INTRODUCTORIA_V2022_1_MATRIX_H

#include <iostream>
using namespace std;

namespace utec {

    class matrix {
    private:
        size_t row;
        size_t col;
        int **pMatriz;
    private:
        void creacionMatriz();

    public:
        matrix() = default;

        matrix(size_t _row, size_t _col);

        matrix(const matrix &other); //Constructor Copy
        matrix &operator=(const matrix &other); //Copy Assignment Operator

        matrix(matrix &&other) noexcept; //Constructor Move
        matrix &operator=(matrix &&other) noexcept; //Move Assignment Operator

        ~matrix();

        size_t rows() const;

        size_t cols() const;

        friend ostream &operator<<(ostream &os, const matrix &matriz);

        int &operator()(int i, int j);

        friend bool operator==(matrix &matriz, matrix &matriz2);

        friend bool operator!=(matrix &matriz, matrix &matriz2);

        matrix operator+(matrix &matriz);

        matrix operator*(matrix &matriz);

        matrix operator*(int escalar);
    };

    ostream &operator<<(ostream &os, const matrix &matriz) {
        for (int i = 0; i < matriz.row; i++) {
            for (int j = 0; j < matriz.col; j++) {
                os << matriz.pMatriz[i][j] << "  ";
            }
            os << endl;
        }
        return os;
    }

    bool operator==(matrix &matriz, matrix &matriz2) {
        if ((matriz.row == matriz2.row) && (matriz.col == matriz2.col)) {
            for (int i = 0; i < matriz.row; i++) {
                for (int j = 0; j < matriz.col; j++) {
                    if (matriz.pMatriz[i][j] != matriz2.pMatriz[i][j]) {
                        return false;
                    }
                }
            }
            return true;
        } else return false;
    }

    bool operator!=(matrix &matriz, matrix &matriz2) {
        if ((matriz.row != matriz2.row) || (matriz.col != matriz2.col)) {

            return true;
        } else return false;
    }
}


#endif //PROG3_UNIT1_TAREA_INTRODUCTORIA_V2022_1_MATRIX_H
