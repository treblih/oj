/*
 * =====================================================================================
 *
 *       Filename:  673.c
 *
 *    Description:  Parentheses balance
 *    		    stack
 *
 *        Created:  10.10.10
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
#define	SIZE	256
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
static int stk[SIZE];

int main(int argc, const char *argv[])
{
#ifdef DB
	fp = fopen("input", "r");
#endif
	int cases, idx, ch;
	char *p;
	scanf("%d\n", &cases);
	while (cases--) {
		fgets(str, SIZE, stdin);
		p = str, idx = -1;
		while ((ch = *p++) != '\n') {
			if (ch == '(' || ch == '[') stk[++idx] = ch;
			else if (ch == ')' && (stk[idx] != '(' || idx == -1))
				{idx = 0;goto out;}
			else if (ch == ']' && (stk[idx] != '[' || idx == -1))
				{idx = 0;goto out;}
			else --idx;
		}
out:
		if (idx != -1) puts("No");
		else puts("Yes");
	}
	return 0;
}
