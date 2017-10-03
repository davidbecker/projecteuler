#include "stdio.h"
#include "stdint.h"
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

void euler3() {
	uintmax_t target = 600851475143;

	int largestPrime = 0, quotient = 2;
	while (target != 0 & quotient <= target)
	{
		if (target%quotient == 0) {
			if (quotient > largestPrime) {
				largestPrime = quotient;
			}
			target /= quotient;
		}
		else
		{
			quotient += 1;
		}
	}

	printf("lagest prime: %d", largestPrime);
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
		case 3: euler3(); break;
		default:
			break;
		}
	}
	
}