#pragma once

#define _CRT_SECURE_NO_DEPRECATE

#include "stdio.h"
#include "stdint.h"
#include "stdbool.h"
#include "string.h"


const int PROBLEM_MIN = 1;
const int PROBLEM_MAX = 10;

void selectProblem();

void euler1();
void euler2();
void euler3();
void euler4();
void euler5();
void euler6();
void euler7();
void euler8();
void euler9();
void euler10();


// helper functions
bool isPalindrome(int*);
bool isEvenlyDivisible(int, int);
bool isPrimeNumber(int);
bool isPrimeNumberWithStart(int, int);
