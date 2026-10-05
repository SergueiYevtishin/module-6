#pragma once
#include <vector>
#include <iostream>

namespace math
{
    typedef float real;

    class Matrix
    {
        private:
        int cols_;
        int rows_;
        std::vector<real>mvec_;

        public: Matrix(){};

        Matrix(int rows, int cols): cols_(cols), rows_(rows), mvec_(std::vector<real>(rows*cols)){};
        
        real& operator()(int row, int col);
        real operator()(int row, int col)const;
        
        void print();
        Matrix& operator+=(const Matrix& A);
        Matrix& operator-=(const Matrix& A);
        Matrix& operator*=(const Matrix& A);
        std::istream& operator>>(Matrix &A(int rows, int cols));
        std::ostream& operator<<(const Matrix &A);

        friend Matrix operator+(const Matrix &A, const Matrix &B);
        friend Matrix operator-(const Matrix &A, const Matrix &B);
        friend Matrix operator*(const Matrix &A, const Matrix &B);
    };
}