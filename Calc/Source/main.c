/*
* Name : Calc
* Developer : Rhseung
* Date : 2019-10-05
*/

#include "head.h"
number calculate(char formula[]);

#if true
int main()
{
	// 변수 목록
	id id = { 0,0,0,0,0 };
	number dres = 0;
	bool find = false;
	char part[SIZE] = clean;
	char form[SIZE] = clean;
	char sres[SIZE] = clean;

	// 입력하기
	printf(" input: \n ");
	gets(form);

	do {
		// 변수 초기화 하기
		id.deep = 0; id.end = 0; id.n = 0; id.par = 0; id.start = 0;
		dres = 0;
		find = false;
		clear(part); clear(sres);

		// 곱하기 생략된거 삽입하기
		forin(i, 0, len(form), 1)
		{
			if (form[i] == ')') {
				if (form[i + 1] == '(') {
					inss(form, i + 1, '*');
					i--;
				}
			}
		}

		// 가장 깊은거 잘라내기
		forin(i, 0, len(form), 1)
		{
			if (form[i] == '(') {
				id.n++;
				id.par++;
				if (id.n > id.deep) {
					id.start = i;
					id.deep = id.n;
				}
			}
			elif(form[i] == ')') {
				id.n--;
				id.par++;
				if (id.n == id.deep - 1 and find == false) {
					id.end = i;
					find = true;
				}
			}
		}
		if (id.n != 0) continue;
		else
		{
			printf(" deep: %d, n : %d, par: %d, start : %d, end : %d\n", id.deep, id.n, id.par, id.start, id.end);
			strcpy(part, slice(form, id.start, id.end));
			dels(part, 0); dels(part, len(part) - 1);
			puts(part);

			// 괄호 사이 수식 계산하기
			if (strcmp(part, "") != 0) dres = calculate(part);
			else dres = 1;

			putd(" dres: ", dres);
			sprintf(sres, "%g", dres);
			endl(1);
			printf(" sres: "); puts(sres);
			putd(" size: ", len(sres));
			endl(1);

			// 계산값 다시 삽입하기
			forin(i, id.start, id.end + 1, 1)
				dels(form, id.start);
			forin(i, id.start, id.start + len(sres), 1)
				inss(form, i, sres[i - id.start]);
			printf("\n form: "); puts(form);
		}
	} while (id.par != 0);

	return 0;
}

number calculate(char formula[])
{
	number result = 0; // 계산 결과값을 저장
	clear(myop);
	char origin[SIZE];
	char input[SIZE];
	char buff[SIZE] = clean;

	strcpy(input, formula);
	strcpy(origin, input);

	// 변수, 배열 초기화
	int length = 0;

	// 수식 중에서 기호 배열과 일치하는 것이 있다면
	forin(i, 0, len(input), 1)
	{
		switch (input[i])
		{
		case '+':
			apps(myop, '+');
			input[i] = ',';
			break;

		case '*':
			apps(myop, '*');
			input[i] = ',';
			break;

		case '/':
			apps(myop, '/');
			input[i] = ',';
			break;
		}
	}
	strcpy(buff, input); // 숫자(문자열형) 복사
	endl(1);

	// oplist에 없었던 '-','/'를 넣음
	inss(oplist, 1, '-');

	line(30, '-');
	endl(1);
	//printf(" > 숫자에 기호가 있으면 제거 후 기호에 추가 중;\n");
	printf(" str: \"%s\"\n", buff);
	//printf(" oplist: %s\n", oplist);
	printf(" ope: \"%s\"\n", myop);

	printf("\n VALUE | ");
	forin(i, 0, len(buff), 1)
		printf("%c ", buff[i]);

	endl(1);

	int total = 0;	// 전체 쉼표 개수
	int next = 0;	// 자신 인덱스 이상의 쉼표개수

	printf(" MINUS | ");
	// 숫자에 기호가 있으면 제거 후 기호에 추가
	forin(i, 0, len(buff) - 1, 1)
	{
		total = 0;
		next = 0;
		if (buff[i] == '-')
		{
			if (i == 0)
			{
				printf("~~");
				continue;
			}
			else if (buff[i - 1] == ',')
			{
				printf("~~");
				continue;
			}
			else
			{
				// 전체 쉼표 개수
				forin(j, 0, len(buff), 1) {
					if (buff[j] == ',')
						total++;
				}
				// 자기 인덱스 이상의 쉼표 개수
				forin(j, i, len(buff), 1) {
					if (buff[j] == ',')
						next++;
				}
				printf("^~");
				inss(myop, total - next, '-');
				buff[i] = ',';
			}
		}
		else printf("~~");
	}

	endl(2);
	//printf(" > 숫자에 기호가 있으면 제거 후 기호에 추가 완료;\n");
	printf(" str: \"%s\"\n", buff);
	//printf(" oplist: %s\n", oplist);
	printf(" ope: \"%s\"\n", myop);

	// oplist에서 '-','/'를 다시 뺌
	dels(oplist, 1);
	line(30, '-');
	endl(2);

	length = toDoubleArray(buff, mynum);
	// '-' 기호를 '+' 기호로 변환
	forin(i, 0, len(myop), 1)
	{
		if (myop[i] == '-')
		{
			// -가 부호일때
			myop[i] = '+';
			mynum[i + 1] *= -1;
		}
	}

	//endl(2);

	// 잘 들어갔는지 테스트
	printf(" num >> ");
	printa(mynum, length);
	endl(1);
	printf(" ope >> \"%s\"\n", myop);

	// 본격 계산 코드
	line(30, '='); endl(1);
	printf(" ( ) "); printa(mynum, length); endl(1);

	forin(i, 0, len(myop), 1)
	{
		// 곱셈 계산
		if (myop[i] == '*')
		{
			printf(" (%c) ", myop[i]); result = Mult(mynum, i, length);
			dels(myop, i); i--; length--; endl(1);
		}
		// 곱셈 계산
		else if (myop[i] == '/')
		{
			printf(" (%c) ", myop[i]); result = Divi(mynum, i, length);
			dels(myop, i); i--; length--; endl(1);
		}
	}
	forin(i, 0, len(myop), 1)
	{
		// 덧셈 & 뺄셈 계산
		if (myop[i] == '+')
		{
			printf(" (%c) ", myop[i]); result = Add(mynum, 0, length);
			length--; endl(1);
		}
	}
	line(30, '='); endl(1);

	return result;
}
#endif
