#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define forin(var, start, stop, step) for (size_t var = start; var < stop; var += step)
#define UP_SORT 1
#define DOWN_SORT 0
#define len strlen

// 문자열 string에 저장된 숫자들을 double의 배열 result로 변환해주는 함수
// 반환된 배열의 길이 반환

int toDoubleArray(char* string, double* result)
{
	char* ptr = strtok(string, ",");

	int length = 0;
	while (ptr)
	{
		result[length++] = atof(ptr);
		ptr = strtok(NULL, ",");
	}

	return length;
}

void printa(double ar[], int length)
{
	printf("[ ");
	for (int i = 0; i < length; i++)
	{
		if (i != length - 1)
			printf("%G, ", ar[i]);
		else
			printf("%G ", ar[i]);
	}
	printf("]");
}

void putd(char txt[], double n)
{
	printf("%s%g", txt, n);
}

void inss(char ar[], int idx, char ch)
{
	memmove(ar + idx + 1, ar + idx, len(ar) - idx + 1);
	ar[idx] = ch;
}

void dels(char ar[], int idx)
{
	memmove(ar + idx, ar + idx + 1, len(ar) - idx);
}

void apps(char ar[], char ch)
{
	inss(ar, len(ar), ch);
}

void insi(double ar[], int length, int idx, double input_num)
{
	memmove(ar + idx + 1, ar + idx, sizeof(*ar) * (length - idx + 1));
	ar[idx] = input_num;
}

void deli(double ar[], int length, int idx)
{
	memmove(ar + idx, ar + idx + 1, sizeof(*ar) * (length - idx));
}

void appi(double ar[], int length, double input_num)
{
	ar[length] = input_num;
}

void swap(double a, double b)
{
	a = a + b;
	b = a - b;
	a = a - b;
}

void sort(double arr[], int length, int reverse)
{
	if (reverse == UP_SORT)
	{
		forin(i, 1, length, 1)
		{
			if (arr[i - 1] < arr[i])
				swap(arr[i - 1], arr[i]);
		}
	}
	else if (reverse == DOWN_SORT)
	{
		forin(i, 1, length, 1)
		{
			if (arr[i - 1] > arr[i])
				swap(arr[i - 1], arr[i]);
		}
	}
}

void replace(char str[], int start, char from, char to)
{
	for (size_t i = start; i < len(str) - 1; i++)
	{
		if (str[i] == from)
			str[i] = to;
	}
}
char* slice(char str[], int start, int end)
{
	char sliced[500] = {'\0'};

	for (int i = 0; i < (end - start + 1); i++)
		sliced[i] = str[start + i];

	return sliced;
}