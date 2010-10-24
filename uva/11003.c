/*
 * =====================================================================================
 *
 *       Filename:  11003.c
 *
 *    Description:  Boxes
 *    		    dp & lds
 *    		    load[i]=min{load[i-1]-weight[i], load[i]}
 *
 *        Created:  23.10.10
 *       Revision:  
 *       Compiler:  GCC 4.4
 *
 *         Author:  Yang Zhang, treblih.divad@gmail.com
 *        Company:  
 *
 * =====================================================================================
 */

#include <stdio.h>
#define	SIZE	1010
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
static int cnt;
static int weight[SIZE];
static int load[SIZE];

void lis_process()
{
	int i, tmp;
	FORI(i, 1, i < cnt) {
		if (/* condition */) {
			/* code */
		}
	}
	if (i == cnt) printf("%d\n", level);
}

int main(int argc, const char *argv[])
{
#ifdef DB
	fp = fopen("input", "r");
#endif
	int i, level, tmp;
	while (scanf("%d", &cnt), cnt) {
		FORIZ(i, i < cnt) scanf("%d%d", &weight[i], &load[i]);
		lis[0] = level = 1;
		lis_process();
	}
	return 0;
}
