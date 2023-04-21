//
// Created by rudri on 3/23/2022.
//

#include "matrix.h"

void utec::matrix::creacionMatriz() {
    this->pMatriz = new int*[this->row];

    for(int i = 0 ; i < row ; i++){
        pMatriz[i] = new int[col];
    }

    for(int i = 0 ; i < row ; i++){
        for(int j = 0 ; j < col ; j++){
            pMatriz[i][j] = 0;
        }
    }
}

utec::matrix::matrix() {
    creacionMatriz();
}

utec::matrix::matrix(int _rows, int _cols) : row(_rows), col(_cols){
    creacionMatriz();
}

utec::matrix::matrix(const utec::matrix &other) {
    this->row = other.row;
    this->col = other.col;
    this->pMatriz = other.pMatriz;
}
utec::matrix &utec::matrix::operator=(const utec::matrix &other) {
    if(this != &other){
        this->row = other.row;
        this->col = other.col;
        this->pMatriz = other.pMatriz;
    }
    return *this;
}

utec::matrix::matrix(utec::matrix &&other)  noexcept {
    this->row = other.row;
    this->col = other.col;
    this->pMatriz = other.pMatriz;

    other.row = 0;
    other.col = 0;
    other.pMatriz = nullptr;
}
utec::matrix &utec::matrix::operator=(utec::matrix &&other) noexcept {
    if (this != &other){
        this->row = other.row;
        this->col = other.col;
        this->pMatriz = other.pMatriz;

        other.row = 0;
        other.col = 0;
        other.pMatriz = nullptr;
    }
    return *this;
}

int utec::matrix::rows(){
    return this->row;
}
int utec::matrix::cols(){
    return this->col;
}

int &utec::matrix::operator()(int i, int j) {
    return pMatriz[i][j];
}
int &utec::matrix::operator()(int i,int j) const{
    return pMatriz[i][j];
}

bool utec::matrix::operator==(utec::matrix &matriz) {
    if ((row == matriz.row) && (col == matriz.col)) {
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (pMatriz[i][j] != matriz.pMatriz[i][j]) {
                    return false;
                }
            }
        }
        return true;
    }
    else
        return false;
}

bool utec::matrix::operator!=(utec::matrix &matriz) {
    if ((row != matriz.row) || (col != matriz.col)) {
        return true;
    } else return false;
}

utec::matrix utec::matrix::operator+(utec::matrix &matriz) {
    matrix suma(row,col);
    if((this->row == matriz.row) && (this->col == matriz.col)){
        for(int i = 0;i < row;i++){
            for(int j = 0;j < col;j++){
                suma.pMatriz[i][j] = pMatriz[i][j] + matriz.pMatriz[i][j];
            }
        }

    }
    return suma;
}
utec::matrix utec::matrix::operator*(utec::matrix &matriz) {
    matrix producto(this->row,matriz.col);
    if(this->col == matriz.row){
        for(int i = 0;i < producto.row;i++){
            for(int j = 0;j < producto.col;j++){
                for(int z = 0;z < matriz.row;z++){
                    producto.pMatriz[i][j] += pMatriz[i][z] * matriz.pMatriz[z][j];
                }
            }
        }

    }
    return producto;
}

utec::matrix utec::matrix::operator*(int escalar) {
    matrix producto(row,col);

    for(int i = 0;i < row;i++){
        for(int j = 0;j < col;j++){
            producto.pMatriz[i][j] = pMatriz[i][j] * escalar;
        }
    }

    return producto;
}

utec::matrix &utec::matrix::operator*=(int escalar) {
    for(int i = 0 ; i < row ; i++){
        for(int j = 0 ; j < col ; j++){
            pMatriz[i][j] = pMatriz[i][j] * escalar;
        }
    }
    return *this;
}



