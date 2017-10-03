#include "projecteuler.h"


int main()
{
	selectProblem();
	getchar();
	return 0;
}

void euler1()
{
	int sum = 0;
	for (int i = 0; i < 1000; i++)
	{
		if (i % 3 == 0 | i % 5 == 0)
		{
			sum += i;
		}
	}
	printf("sum: %d", sum);
	getchar();
}

void euler2()
{
	int seqLast = 1, seqCurrent = 1, sum = 0;
	while (seqCurrent < 4000000)
	{
		seqCurrent += seqLast;
		seqLast = seqCurrent - seqLast;
		if (seqCurrent % 2 == 0)
		{
			sum += seqCurrent;
		}
	}
	printf("sum: %d", sum);
	getchar();
}

void euler3()
{
	uintmax_t target = 600851475143;

	int largestPrime = 0, quotient = 2;
	while (target != 0 & quotient <= target)
	{
		if (target%quotient == 0)
		{
			if (quotient > largestPrime)
			{
				largestPrime = quotient;
			}
			target /= quotient;
		}
		else
		{
			quotient += 1;
		}
	}

	printf("largest prime: %d", largestPrime);
	getchar();
}

void euler4()
{
	int result = 0, iTemp = 1001;
	isPalindrome(&iTemp);
	for (int i = 100; i < 1000; i++)
	{
		for (int j = 100; j < 1000; j++)
		{
			iTemp = i * j;
			if (isPalindrome(&iTemp))
			{
				if (iTemp > result)
				{
					result = iTemp;
				}
			}
		}
	}
	printf("result: %d", result);
	getchar();
}

bool isPalindrome(int *input)
{
	if (*input <= 0)
	{
		return false;
	}
	char str[12];
	snprintf(str, 12, "%d", *input);
	int length = strlen(str);

	for (int i = 0; i < length; i++)
	{
		if (str[i] != str[length-i-1])
		{
			return false;
		}
	}

	return true;
}

void selectProblem()
{
	int selection;
	printf("select problem between %d and %d\n", PROBLEM_MIN, PROBLEM_MAX);
	scanf_s("%d", &selection);

	if (selection >= PROBLEM_MIN & selection <= PROBLEM_MAX) {
		switch (selection)
		{
		case 1: euler1(); break;
		case 2: euler2(); break;
		case 3: euler3(); break;
		case 4: euler4(); break;
		default:
			break;
		}
	}

}