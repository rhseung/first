#pragma once

#include <stdio.h>
#include "control.h"
#define len strlen
typedef double number;


number Add(number mynum[], int idx, int length)
{
	number dresult = 0; // 덧셈 결과값을 저장

	dresult = mynum[idx] + mynum[idx+1];

	deli(mynum, length, idx);
	mynum[idx] = dresult;
	length--;

	printa(mynum, length);

	return dresult;
}

number Mult(number mynum[], int idx, int length)
{
	number dresult = 0; // 곱셈 결과값을 저장

	dresult = mynum[idx] * mynum[idx+1];

	deli(mynum, length, idx);
	mynum[idx] = dresult;
	length--;

	printa(mynum, length);

	return dresult;
}

number Divi(number mynum[], int idx, int length)
{
	number dresult = 0; // 나눗셈 결과값을 저장

	dresult = mynum[idx] / mynum[idx+1];

	deli(mynum, length, idx);
	mynum[idx] = dresult;
	length--;

	printa(mynum, length);

	return dresult;
}
