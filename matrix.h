//
// Created by rudri on 3/23/2022.
//

#ifndef PROG3_UNIT1_TAREA_INTRODUCTORIA_V2022_1_MATRIX_H
#define PROG3_UNIT1_TAREA_INTRODUCTORIA_V2022_1_MATRIX_H

#include <iomanip>
#include <iostream>
using namespace std;

namespace utec {

    using SIZE_TYPE = int;

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
        /////////////////////////
        size_t rows() const;
        size_t cols() const;


        int &operator()(int i, int j);

        friend ostream &operator<<(ostream &os, const matrix &matriz);
        friend matrix operator*(int escalar,matrix &matriz);

        bool operator==(matrix &matriz);
        bool operator!=(matrix &matriz);

        matrix operator+(matrix &matriz);
        matrix operator*(matrix &matriz);

        matrix operator*(int escalar);
        matrix operator*=(int escalar);
    };

    ostream &operator<<(ostream &os, const matrix &matriz) {
        for (int i = 0; i < matriz.row; i++) {
            for (int j = 0; j < matriz.col; j++) {
                os << setw(3) << matriz.pMatriz[i][j] << " ";
            }
            os << endl;
        }
        return os;
    }

}

using SIZE_TYPE = int;

#endif //PROG3_UNIT1_TAREA_INTRODUCTORIA_V2022_1_MATRIX_H
