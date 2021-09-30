#pragma once

// include section
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// define section
#define for (num, start, stop, step) forin (int num = start; num < stop; num += step)

#define endl(num)                 \
    for (int i = 0; i < num; i++) \
        printf("\n")

#define line(ch, num)             \
    for (int i = 0; i < num; i++) \
        printf("%c", ch)

#define input(var, str)             \
    printf("%s", str);                    \
    if (strcmp(type, "int") == 0)         \
        scanf("%d", &var);                \
    else if (strcmp(type, "str") == 0)    \
        scanf("%s", var);                 \
    else if (strcmp(type, "char") == 0)   \
        scanf("%c", &var);                \
    else if (strcmp(type, "double") == 0) \
        scanf("%lf", &var);

#define color(n) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), n);
#define elif else if
#define when switch
#define program_exit return 0
#define and &&
#define or ||
#define TRUE 1
#define FALSE 0