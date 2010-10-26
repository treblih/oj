/*
 * =====================================================================================
 *
 *       Filename:  482.c
 *
 *    Description:  Permutation Arrays
 *    		    hash & string
 *
 *        Created:  26.10.10
 *       Revision:  
 *       Compiler:  GCC 4.4
 *
 *         Author:  Yang Zhang, treblih.divad@gmail.com
 *        Company:  
 *
 * =====================================================================================
 */

#include <stdio.h>
#include <ctype.h>
#define	SIZE	1000000
#define	FORI(i, val, cond)	for ((i) = (val); (cond); ++(i))	
#define	FORIZ(i, cond)		FORI((i), 0, (cond))
#define	FORD(i, val, cond)	for ((i) = (val); (cond); --(i))
#define	FORDZ(i, cond)		FORD((i), 0, (cond))
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
/* 512 is for 1 number which has at most 512 digits */
static char str[SIZE][512];
static char tmp[SIZE];
static int hash[SIZE];

int main(int argc, const char *argv[])
{
#ifdef DB
	fp = fopen("input", "r");
#endif
	int i, cases, cnt, ch, fst = 1;
	char *p;
	scanf("%d", &cases);
	while (cases--) {
		if (fst) fst = 0;
		else putchar('\n');
		/* tmp will be "\n\n" */
		scanf("%[\n]", tmp);
		fgets(tmp, SIZE, stdin);
		cnt = 0;
		FORI(p, tmp, (ch = *p) != '\n') {
			if (ch == ' ') continue;
			sscanf(p, "%d", &hash[cnt++]);
			do ch = *++p; while (isdigit(ch));
			--p;	/* for loop has a ++p */
		}
		/* hash starts from 1 */
		FORIZ(i, i < cnt) scanf("%s", str[hash[i]]);
		FORI(i, 1, i <= cnt) printf("%s\n", str[i]);
	}
	return 0;
}
