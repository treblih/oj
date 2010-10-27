/*
 * =====================================================================================
 *
 *       Filename:  727.c
 *
 *    Description:  Equation
 *    		    stack
 *
 *        Created:  27.10.10
 *       Revision:  
 *       Compiler:  GCC 4.4
 *
 *         Author:  Yang Zhang, treblih.divad@gmail.com
 *        Company:  
 *
 * =====================================================================================
 */

#include <stdio.h>
#include <string.h>
#define	SIZE	1000000
#define	FORI(i, val, cond)	for ((i) = (val); (cond); ++(i))	
#define	FORIZ(i, cond)		FORI((i), 0, (cond))
#define	FORD(i, val, cond)	for ((i) = (val); (cond); --(i))
#define	FORDZ(i, val)		FORD((i), (val), i >= 0)
#define ZERO(a)			memset((a), 0, sizeof(a))
#define	MAX(a, b)		({__typeof__ (a) ta = (a);\
			  	__typeof__ (b) tb = (b);\
			  	ta > tb ? ta : tb;})
#define	MIN(a, b)		({__typeof__ (a) ta = (a);\
			  	__typeof__ (b) tb = (b);\
			  	ta < tb ? ta : tb;})
#ifdef DB
	#define getchar()		getc(fp)
	#define	scanf(...)		fscanf(fp, __VA_ARGS__)
	#undef	stdin
	#define stdin			fp
#endif
static FILE *fp;
static char str[SIZE];
static char stack[SIZE>>1];
static char infix[SIZE];
static char postfix[SIZE];

int main(int argc, const char *argv[])
{
#ifdef DB
	fp = fopen("input", "r");
#endif
	char ch, tmp, fst;
	int cases;
	char *stk, *in, *post, *p;
	scanf("%d", &cases);
	fgets(str, SIZE, stdin);
	fgets(str, SIZE, stdin);
	while (cases--) {
		for (in = infix; fgets(str, SIZE, stdin) != NULL; ) {
			fst = 1;
			FORI(p, str, (ch = *p)) {
				if (ch == '\n') {
					if (fst) goto process;
					else break;
				}
				else if (ch >= 0x28 && ch <= 0x39) {
					*in++ = ch;
					fst = 0;
				}
			}
#if 0
			if (str[0] != '\n') *in = str[0];
			else break;
#endif
		}
		process:
		*in = 0;
		/* load done */
		post = postfix;
		stk = stack;
		FORI(in, infix, (ch = *in)) {
			switch (ch) {
			case '(':
				*stk++ = ch;
				break;
			case ')':
				/* at last ch holds '(' */
				while ((tmp = *--stk) != '(') *post++ = tmp;
				/* a operand 1 byte ahead of '(' */
				if (stk != stack && *(stk-1) != '(') *post++ = *--stk;
				break;
			case '+':
			case '-':
				while (stk != stack && *(stk - 1) >= 0x2a) *post++ = *--stk;
				*stk++ = ch;
				break;
			case '*':
			case '/':
				while (stk != stack && (tmp = *(stk - 1)) != '(') {
					if (tmp == '*' || tmp == '/') *post++ = *--stk;
					else break;
				}
				*stk++ = ch;
				break;
			case '0': case '1': case '2': case '3': case '4': 
			case '5': case '6': case '7': case '8': case '9':
				*post++ = ch;
				break;
			}
		}
		while (stk != stack) *post++ = *--stk;
		*post++ = 0;
		printf("%s\n", postfix);
		if (cases) putchar('\n');
	}
	return 0;
}
