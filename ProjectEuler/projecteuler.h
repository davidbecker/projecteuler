#pragma once
#include "stdio.h"
#include "stdint.h"
#include "stdbool.h"


const int PROBLEM_MIN = 1;
const int PROBLEM_MAX = 6;

void selectProblem();

void euler1();
void euler2();
void euler3();
void euler4();
void euler5();
void euler6();

// helper functions
bool isPalindrome(int*);
bool isEvenlyDivisible(int, int);