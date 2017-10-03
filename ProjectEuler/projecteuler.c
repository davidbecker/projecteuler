#include "stdio.h"
#include "projecteuler.h"

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

void euler2() {
	int seqLast = 1, seqCurrent = 1, sum = 0;
	while (seqCurrent < 4000000)
	{
		seqCurrent += seqLast;
		seqLast = seqCurrent - seqLast;
		if (seqCurrent % 2 == 0) {
			sum += seqCurrent;
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
		case 2: euler2(); break;
		default:
			break;
		}
	}
	
}