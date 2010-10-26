/*
 * =====================================================================================
 *
 *       Filename:  594.c
 *
 *    Description:  One Little, Two Little, Tree Little Endians
 *    		    adhoc
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
#define	FORI(i, val, cond)	for ((i) = (val); (cond); ++(i))	
#define	FORIZ(i, cond)		FORI((i), 0, (cond))
#define	FORD(i, val, cond)	for ((i) = (val); (cond); --(i))
#define	FORDZ(i, val)		FORD((i), (val), i >= 0)
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

int main(int argc, const char *argv[])
{
#ifdef DB
	fp = fopen("input", "r");
#endif
	int i, little, big;
	char *p;
	while (scanf("%d", &little) != EOF) {
		p = (char *)&little;
		FORDZ(i, 3) *((char *)&big + i) = *p++;
		printf("%d converts to %d\n", little, big);
	}
	return 0;
}
