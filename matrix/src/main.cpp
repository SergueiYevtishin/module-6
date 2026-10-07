#include <src/matrix.h>
#include <iostream>

int main()
{
    math::Matrix m(3,3);
    m(0,0)=1.;
    m(1,1)=1.;

    math::Matrix m1(3,3);
    m1(0,0)=5.;
    m1(1,1)=5.;

    std::cout<<"Matrix m is:"<<std::endl;
    m.print();

    std::cout<<std::endl
            <<"Matrix m1 is:"<<std::endl;
    m1.print();

    std::cout<<std::endl<<"Sum of Matrices m and m1 is:"<<std::endl;
    math::Matrix m2 = m + m1;
    m2.print();

    std::cout<<std::endl<<"Difference of Matrices m and m1 is:"<<std::endl;
    math::Matrix m3 = m - m1;
    m3.print();

    std::cout<<std::endl<<"Product of Matrices m and m1 is:"<<std::endl;
    math::Matrix m4 = m * m1;
    m4.print();

    std::cout<<std::endl<<"Matrix m augmented by matrix m1 is:"<<std::endl;
    m += m1;
    //Использование перегруженного метода вывода:
    std::cout<<m;

    std::cout<<std::endl<<"Matrix m diminished by matrix m1 is:"<<std::endl;
    m -= m1;
    std::cout<<m;

    std::cout<<std::endl<<"Matrix m miltiplied by matrix m1 is:"<<std::endl;
    m *= 5;
    std::cout<<m;

    //Использование перегруженного метода ввода:
    std::cout<<"Do you want to create a new matrix (y/n)?"<<std::endl;
    char User_choice;
    std::cin>>User_choice;
    if (User_choice == 'y')
    {
        std::cout<<"Enter parameters of the matrix."<<std::endl;
        std::cout<<"Number of rows:"<<std::endl;
        int user_rows=0;
        std::cin>>user_rows;
        std::cout<<"Number of cols:"<<std::endl;
        int user_cols=0;
        std::cin>>user_cols;
        math::Matrix user_m(user_rows, user_cols);
        std::cout<<"Enter elements of the new matrix in one line:"<<std::endl;
        std::cin>>user_m;

    }

    return 0;
}