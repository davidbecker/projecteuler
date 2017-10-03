#include "stdio.h"
#include "projecteuler.h"

const int PROBLEM_MIN = 1;
const int PROBLEM_MAX = 1;

int main()
{
	selectProblem();
	getchar();
	return 0;
}

void euler1() {
	int sum = 0;
	for (int i = 0; i < 1000; i++)
	{
		if (i % 3 == 0 | i % 5 == 0) {
			sum += i;
		}
	}
	printf("sum: %d", sum);
	getchar();
}

void selectProblem() {
	int selection;
	printf("select problem between %d and %d\n", PROBLEM_MIN, PROBLEM_MAX);
	scanf_s("%d", &selection);
	
	if (selection >= PROBLEM_MIN & selection <= PROBLEM_MAX) {
		switch (selection)
		{
		case 1: euler1(); break;
		default:
			break;
		}
	}
	
}