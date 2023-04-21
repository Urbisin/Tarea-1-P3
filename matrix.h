//
// Created by rudri on 3/23/2022.
//

#ifndef PROG3_UNIT1_TAREA_INTRODUCTORIA_V2022_1_MATRIX_H
#define PROG3_UNIT1_TAREA_INTRODUCTORIA_V2022_1_MATRIX_H

#include <iostream>
#include <iomanip>
using namespace std;

namespace utec{

    class matrix{
    private:
        int row,col;
        int** pMatriz;
    private:
        void creacionMatriz();
    public:
        matrix();

        matrix(int _rows,int _cols);

        matrix(const matrix &other); //Constructor copy
        matrix &operator=(const matrix &other); //Copy Assignment Operator

        matrix(matrix &&other) noexcept; //Constructor move
        matrix &operator=(matrix &&other) noexcept;//Move Assignment Operator

        int rows();
        int cols();

        int &operator() (int i,int j);
        int &operator() (int i,int j) const;

        friend ostream &operator<<(ostream &os,const matrix &matriz){
            for (int i = 0; i < matriz.row; i++) {
                for (int j = 0; j < matriz.col; j++) {
                    os << setw(3) << matriz(i,j) << " ";
                }
                os << '\n';
            }
            return os;
        }

        bool operator==(matrix &matriz);
        bool operator!=(matrix &matriz);

        matrix operator+(matrix &matriz);
        matrix operator*(matrix &matriz);

        matrix operator*(int escalar);
        friend matrix operator*(int escalar,matrix &other){
            matrix producto(other.row,other.col);
            for(int i = 0 ; i < other.row ; i++){
                for(int j = 0 ; j < other.col ; j++){
                    producto.pMatriz[i][j] = other.pMatriz[i][j] * escalar;
                }
            }
            return producto;
        }

        matrix &operator*=(int escalar);
    };
}

using SIZE_TYPE = int;

#endif //PROG3_UNIT1_TAREA_INTRODUCTORIA_V2022_1_MATRIX_H
