#include <src/matrix.h>
using namespace math;
#include <iostream>

real& Matrix::operator()(int row, int col)
{
    if (row >= this->rows_) 
    {
        std::cerr <<"Matrix: row number out of bounds"<<std::endl;
        //return (0);
    }

     if (col >= this->cols_) 
    {
        std::cerr <<"Matrix: col number out of bounds"<<std::endl;
        //return (0);
    }

    int pos{0};
    pos = cols_*row + col;
    return this->mvec_.at(pos);
}

real Matrix::operator()(int row, int col)const
{
    if (row >= this->rows_) 
    {
        std::cerr <<"Matrix: row number out of bounds"<<std::endl;
        //return (0);
    }

     if (col >= this->cols_) 
    {
        std::cerr <<"Matrix: col number out of bounds"<<std::endl;
        //return (0);
    }

    int pos{0};
    pos = cols_*row + col;
    return this->mvec_.at(pos);
}

void Matrix::print()
{
    for (int i=0; i<this->rows_; ++i)
    { 
        for (int j=0; j<this->cols_; ++j)
        {
            std::cout<<this->mvec_.at(cols_*i + j)<<" ";
        }
        std::cout<<std::endl;
    }
}

Matrix math::operator+(const Matrix &A, const Matrix &B)
{
    if ((A.cols_ != B.cols_) || (A.rows_ != B.rows_))
    {
        std::cerr << "Matrix: Matrices can not be added!" << std::endl;
        return Matrix(0, 0);
    }

    Matrix M(A.cols_, A.rows_);
    for(int i=0; i<M.mvec_.size(); ++i)
    {
        M.mvec_.at(i)= A.mvec_.at(i) + B.mvec_.at(i);
    }
    return M;
}

Matrix math::operator-(const Matrix &A, const Matrix &B)
{
    if ((A.cols_ != B.cols_) || (A.rows_ != B.rows_))
    {
        std::cerr << "Matrix: Matrices can not be subtracted!" << std::endl;
        return Matrix(0, 0);
    }

    Matrix M(A.cols_, A.rows_);
    for(int i=0; i<M.mvec_.size(); ++i)
    {
        M.mvec_.at(i)= A.mvec_.at(i) - B.mvec_.at(i);
    }
    return M;
}

Matrix math::operator*(const Matrix &A, const Matrix &B)
{
    if (A.cols_ != B.rows_)
    {
        std::cerr << "Matrix: Matrices can not be multiplied!" << std::endl;
        return Matrix(0, 0);
    }

    Matrix M(A.rows_, B.rows_);
    for(int pos=0; pos<M.mvec_.size(); ++pos)
    {
        int row = (int)std::floor(pos/M.cols_);
        int col = pos - row*M.cols_;

        for (int i=0; i<A.cols_; ++i)
        {
            M.mvec_.at(pos) += A(row,i)*B(i,col);
        }
    }
    return M;
}

//Опеделение перегруженного метода сложения с присваиванием (вариант 1 - с двумя параметрами)
Matrix math::operator+=(Matrix &A, const Matrix &B)
{
    if ((A.cols_ != B.cols_) || (A.rows_ != B.rows_))
    {
        std::cerr << "Matrix: Matrices can not be added!" << std::endl;
        return Matrix(0, 0);
    }

    for(int i=0; i<A.mvec_.size(); ++i)
    {
        A.mvec_.at(i)+= B.mvec_.at(i);
    }
    return A;
}

//Опеделение перегруженного метода сложения с присваиванием (вариант 2 - с одним параметром)
//Matrix& math::operator+=(const Matrix &B)
//{
    //if ((this->cols_ != B.cols_) || (this->rows_ != B.rows_))
    //{
        //std::cerr << "Matrix: Matrices can not be added!" << std::endl;
        //return Matrix(0, 0);
    //}

    //for(int i=0; i<this->mvec_.size(); ++i)
    //{
        //this->mvec_.at(i)+= B.mvec_.at(i);
    //}
    //return &this;
//}

//Опеделение перегруженного метода ввода
std::istream& operator>>(std::istream &in, Matrix &A)
{
    Matrix M(A.cols_, A.rows_);
    for (int i=0; i<M.rows_; ++i)
    {
        for (int j=0; j<A.cols_; ++j)
        in>>M[i,j];
    }
    return M;
}

//Опеделение перегруженного метода вывода
std::ostream& operator<<(std::ostream &out, const Matrix &A)
{
    Matrix M(A.cols_, A.rows_);
    for (int i=0; i<rows_; ++i)
    {
        for(int j=0; j<cols_, ++j)
        out<<A.at(i,j);
    }
    std::cout<<std::endl;
}