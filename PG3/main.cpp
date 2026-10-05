#include <iostream>

// 2つの値を比較して、小さい値を返す関数テンプレート
template <typename T>
T Min(T a, T b)
{
    return (a < b) ? a : b;
}

int main()
{
    int intA = 12;
    int intB = 5;

    float floatA = 3.5f;
    float floatB = 7.2f;

    double doubleA = 9.81;
    double doubleB = 6.02;

    std::cout << "int: " << Min(intA, intB) << '\n';
    std::cout << "float: " << Min(floatA, floatB) << '\n';
    std::cout << "double: " << Min(doubleA, doubleB) << '\n';

    return 0;
}
