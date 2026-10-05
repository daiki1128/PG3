#include <iostream>

// 指定した時間の賃金を表示し、再帰的な賃金が上回るまで自身を呼び出す。
int FindProfitableHour(int hours, long long hourlyWage, long long recurringTotal)
{
    const long long normalTotal = 1226LL * hours;
    recurringTotal += hourlyWage;

    std::cout << hours << "      "
              << normalTotal << "    "
              << recurringTotal << '\n';

    // 累計額が上回ったら再帰を終了する。
    if (recurringTotal > normalTotal) {
        return hours;
    }

    // 次の1時間の時給は「前の時給 * 2 - 50円」。
    return FindProfitableHour(hours + 1, hourlyWage * 2 - 50, recurringTotal);
}

int main()
{
    std::cout << "Hours  Normal  Recurring\n";
    const int hours = FindProfitableHour(1, 100, 0);

    std::cout << "\nRecurring wage becomes higher after "
              << hours << " hours.\n";

    return 0;
}
