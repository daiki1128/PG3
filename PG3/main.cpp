#include <iostream>

int main()
{
    const int normalHourlyWage = 1226;
    int recurringHourlyWage = 1000;
    int normalTotalWage = 0;
    int recurringTotalWage = 0;
    int hours = 0;

    std::cout << "Hours  Normal  Recurring\n";

    // 再帰的賃金の累計が通常賃金の累計を上回るまで計算する
    do {
        ++hours;
        normalTotalWage += normalHourlyWage;
        recurringTotalWage += recurringHourlyWage;

        std::cout << hours << "      "
                  << normalTotalWage << "    "
                  << recurringTotalWage << '\n';

        // 次の1時間分の再帰的賃金を計算する
        recurringHourlyWage = recurringHourlyWage * 2 - 50;
    } while (recurringTotalWage <= normalTotalWage);

    std::cout << "\nRecurring wage becomes higher after "
              << hours << " hours.\n";

    return 0;
}
