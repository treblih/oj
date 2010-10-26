/*
 * =====================================================================================
 *
 *       Filename:  11340.c
 *
 *    Description:  A-Newspaper
 *    		   hash & string
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
#include <string.h>
#include <ctype.h>
#define	SIZE	10010
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
static int ascii[256];
static unsigned char line[SIZE]; 
int main(int argc, const char *argv[])
{
#ifdef DB
	fp = fopen("input", "r");
#endif
	char ch;
	int i, cases, val, cnt, sum, tmp;
	char *p;
	scanf("%d", &cases);
	while (cases--) {
		scanf("%d", &cnt); getchar();
		FORIZ(i, i < cnt) {
			ch = getchar();
			scanf("%d", &val); getchar();
			ascii[ch] = val;
		}
		sum = 0;
		scanf("%d", &cnt); getchar();
		FORIZ(i, i < cnt) {
			fgets(line, SIZE, stdin);
			FORI(p, line, (tmp = *p) != (int)'\n') sum += ascii[tmp];
		}
		printf("%d.%02d$\n", sum / 100, sum % 100);
		ZERO(ascii);
	}
	return 0;
}
