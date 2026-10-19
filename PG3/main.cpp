#include <iostream>

template <typename T,typename U>
class Minimum {
private:
	T first;
	U second;
public:
	Minimum(T a, U b) : first(a), second(b) {}

	auto Min() const {
		return (first < second) ? first : second;
	}
};

int main()
{
    Minimum<int, int> intInt(7, 4);
    Minimum<float, float> floatFloat(5.5f, 2.25f);
    Minimum<double, double> doubleDouble(3.14, 2.718);

    Minimum<int, float> intFloat(3, 2.5f);
    Minimum<int, double> intDouble(8, 6.75);
    Minimum<float, double> floatDouble(1.25f, 1.125);

    std::cout << "int, int: " << intInt.Min() << '\n';
    std::cout << "float, float: " << floatFloat.Min() << '\n';
    std::cout << "double, double: " << doubleDouble.Min() << '\n';
    std::cout << "int, float: " << intFloat.Min() << '\n';
    std::cout << "int, double: " << intDouble.Min() << '\n';
    std::cout << "float, double: " << floatDouble.Min() << '\n';

    return 0;
}