#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <Windows.h>

void ShowResult(int roll, int userGuess) {
	printf("出目は%dでした。\n", roll);

	if (roll % 2 == userGuess) {
		printf("正解\n");
	} else {
		printf("不正解\n");
	}
}

void DelayReveal(void (*fn)(int, int), unsigned int delayMs, int roll, int userGuess) {
	Sleep(delayMs);
	fn(roll, userGuess);
}

int main()
{
	SetConsoleOutputCP(CP_UTF8);

	srand((unsigned)time(NULL));

	int userGuess;
	printf("出目を予想してください（奇数: 1、偶数: 0）: ");
	scanf_s("%d", &userGuess);

	int roll = rand() % 6 + 1;

	DelayReveal(ShowResult, 3000, roll, userGuess);

    return 0;
}
