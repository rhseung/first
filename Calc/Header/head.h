#pragma once
#pragma warning(disable : 4996)

#include <windows.h>    // 콘솔 창 관련 라이브러리
#include <stdio.h>      // 표준 입출력 라이브러리
#include <stdbool.h>    // bool상수 라이브러리
#include <stdlib.h>     // 표준 유틸리티 라이브러리
#include <string.h>     // 문자열 관련 라이브러리
#include <ctype.h>      // isdigit 관련 라이브러리
#include <time.h>       // 시간 관련 라이브러리
#include <math.h>       // 수학 함수 라이브러리
#include "control.h"    // 배열 조정 라이브러리
#include "calcf.h"      // 계산 함수 라이브러리

#define forin(var, start, stop, step) for (size_t var = start; var < stop; var += step)
#define color(n) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), n);
#define endl(n)                    \
    for (size_t i = 0; i < n; i++) \
        printf("\n");
#define line(n, c)                 \
    for (size_t i = 0; i < n; i++) \
        printf("%c", c);
#define elif else if
#define when switch
#define and &&
#define or ||
#define SIZE 1000
#define new(n) (char*)malloc(sizeof(char)*n)
#define len strlen
#define clean { '\0' }
#define clear(a) strcpy(a, "");

typedef double number;
typedef size_t lnt;
typedef struct id
{
    lnt deep;
    lnt start;
    lnt par;
    lnt end;
    lnt n;
} id;

char oplist[] = "+*/()";
char myop[SIZE] = clean;
number mynum[SIZE] = { 0 };