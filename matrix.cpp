//
// Created by rudri on 3/23/2022.
//
#include "matrix.h"

void utec::matrix::creacionMatriz() {
    this->pMatriz = new int *[this->row];

    for (int i = 0; i < row; i++) {
        this->pMatriz[i] = new int[this->col];
    }

    for(int i = 0;i < row;i++){
        for(int j = 0;j < col;j++){
            pMatriz[i][j] = 0;
        }
    }
}

utec::matrix::matrix(size_t _row, size_t _col) : row(_row), col(_col) {creacionMatriz();}

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

utec::matrix::~matrix() {
    for(int i = 0;i < this->row;i++){
        delete[] pMatriz[i];
    }

    delete[] pMatriz;
}

size_t utec::matrix::rows() const {
    return this->row;
}
size_t utec::matrix::cols() const {
    return this->col;
}

int &utec::matrix::operator()(int i, int j) {
    return pMatriz[i][j];
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

utec::matrix utec::matrix::operator*(utec::matrix &matriz){
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
    for (int i = 0; i < row;i++) {
        for (int j = 0; i < col; j++) {
            pMatriz[i][j] = pMatriz[i][j] * escalar;
        }
    }
    return *this;
}

utec::matrix utec::matrix::operator*=(int escalar) {
    for(int i = 0;i < row;i++){
        for(int j = 0;j < col;j++){
            pMatriz[i][j] = pMatriz[i][j] + escalar;
        }
    }
    return *this;
}



bool utec::matrix::operator==(matrix &matriz) {
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
}

bool utec::matrix::operator!=(matrix &matriz) {
    if ((row != matriz.row) || (col != matriz.col)) {
        return true;
    } else return false;
}


utec::matrix utec::operator*(int escalar, utec::matrix &matriz) {
    for (int i = 0; i < matriz.row; i++) {
        for (int j = 0; i < matriz.col; j++) {
            matriz.pMatriz[i][j] = matriz.pMatriz[i][j] * escalar;
        }
    }
    return matriz;
}

