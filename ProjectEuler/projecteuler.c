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
		if ((i % 3 == 0) | (i % 5 == 0))
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
	while ((target != 0) & (quotient <= target))
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
		if (str[i] != str[length - i - 1])
		{
			return false;
		}
	}

	return true;
}

void euler5()
{
	int result = 1, max = 20;
	while (!isEvenlyDivisible(result, max))
	{
		result += 1;
	}
	printf("result: %d", result);
	getchar();
}

bool isEvenlyDivisible(int result, int max)
{
	for (int i = 1; i <= max; i++)
	{
		if (result%i != 0)
		{
			return false;
		}
	}
	return true;
}

void euler6()
{
	int sum = 0;
	for (int i = 1; i <= 100; i++)
	{
		sum += i;
	}
	sum *= sum;
	for (int i = 1; i <= 100; i++)
	{
		sum -= i*i;
	}
	printf("result: %d", sum);
	getchar();
}

void euler7()
{
	int count = 0, primeNumber = 0, temp = 1;
	while (count < 10001)
	{
		temp += 1;
		if (isPrimeNumber(temp))
		{
			primeNumber = temp;
			count += 1;
		}
	}
	printf("result: %d", primeNumber);
	getchar();
}

bool isPrimeNumber(int toTest)
{
	if (toTest < 2)
	{
		return false;
	}
	for (int i = 2; i < toTest; i++)
	{
		if (toTest%i == 0)
		{
			return false;
		}
	}
	return true;
}

bool isPrimeNumberWithStart(int toTest, int start)
{
	if (toTest < 2 || toTest < start)
	{
		return false;
	}
	if (start < 2)
	{
		start = 2;
	}
	for (int i = start; i < toTest; i++)
	{
		if (toTest%i == 0)
		{
			return false;
		}
	}
	return true;
}

void euler8()
{
	// extra for \0 (will be at number[1000] )
	char number[1001];
	strcpy(number, "7316717653133062491922511967442657474235534919493496983520312774506326239578318016984801869478851843858615607891129494954595017379583319528532088055111254069874715852386305071569329096329522744304355766896648950445244523161731856403098711121722383113622298934233803081353362766142828064444866452387493035890729629049156044077239071381051585930796086670172427121883998797908792274921901699720888093776657273330010533678812202354218097512545405947522435258490771167055601360483958644670632441572215539753697817977846174064955149290862569321978468622482839722413756570560574902614079729686524145351004748216637048440319989000889524345065854122758866688116427171479924442928230863465674813919123162824586178664583591245665294765456828489128831426076900422421902267105562632111110937054421750694165896040807198403850962455444362981230987879927244284909188845801561660979191338754992005240636899125607176060588611646710940507754100225698315520005593572972571636269561882670428252483600823257530420752963450");

	/*
	* 9^13 is 2.541.865.828.329 -> 13 digits in base 10 (more than 32bit Integer)
	* = 24fd3027fe9 in base 16 (11 digits)
	*/
	unsigned long long result = 0;
	unsigned long long temp;

	// magic number 987 = 1000 - 13
	for (int i = 0; i < 987; i++)
	{
		temp = 1;
		for (int j = 0; j < 13; j++)
		{
			// in number[] is ascii coded - we get our number by substracting the offset for zero
			temp *= number[i + j] - '0';
		}
		if (temp > result)
		{
			result = temp;
		}
	}

	printf("result: %llu", result);
	getchar();
}

void euler9()
{
	bool found = false;
	int a = 0, b = 0, c = 0;
	while (a < 1000 && !found)
	{
		b = 0;
		while (b < 1000 && !found)
		{
			c = 0;
			while (c < 1000 && !found)
			{
				c += 1;
				found = a < b && b < c;
				found = found && (a * a + b * b == c * c);
				found = found && (a + b + c == 1000);
				if (found)
				{
					printf("result: %d", a * b * c);
					getchar();
				}
			}
			b += 1;
		}
		a += 1;
	}
}

void euler10()
{
	uintmax_t count = 0, lastKnownPrime = 2;
	unsigned long long result = 0;
	while (count < 2000000)
	{
		if (isPrimeNumberWithStart(count, lastKnownPrime))
		{
			result += count;
			lastKnownPrime = count;
		}
		count += 1;
	}
	printf("result: %llu", result);
	getchar();
}

void selectProblem()
{
	int selection;
	printf("select problem between %d and %d\n", PROBLEM_MIN, PROBLEM_MAX);
	scanf("%d", &selection);

	if ((selection >= PROBLEM_MIN) & (selection <= PROBLEM_MAX)) {
		switch (selection)
		{
		case 1: euler1(); break;
		case 2: euler2(); break;
		case 3: euler3(); break;
		case 4: euler4(); break;
		case 5: euler5(); break;
		case 6: euler6(); break;
		case 7: euler7(); break;
		case 8: euler8(); break;
		case 9: euler9(); break;
		case 10: euler10(); break;
		default:
			break;
		}
	}

}
