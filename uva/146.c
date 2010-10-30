/*
 * =====================================================================================
 *
 *       Filename:  146.c
 *
 *    Description:  ID Codes 
 *    		    dijkstra permutation
 *    		    next_permutation in STL also works
 *
 *        Created:  29.10.10
 *       Revision:  
 *       Compiler:  GCC 4.4
 *
 *         Author:  Yang Zhang, treblih.divad@gmail.com
 *        Company:  
 *
 * =====================================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define	SIZE	64
#define	FORI(i, val, cond)	for ((i) = (val); (cond); ++(i))	
#define	FORIZ(i, cond)		FORI((i), 0, (cond))
#define	FORD(i, val, cond)	for ((i) = (val); (cond); --(i))
#define	FORDZ(i, val)		FORD((i), (val), i >= 0)
#define	MAX(a, b) 	({__typeof__(a) _a=(a), _b=(b); _a>_b?_a:_b;})
#define	MIN(a, b)	({__typeof__(a) _a=(a), _b=(b); _a<_b?_a:_b;})
#define	SWAP(a, b)	({__typeof__(a) tmp=(a); (a)=(b); (b)=tmp;})
#define	ZERO(a)		memset((a), 0, sizeof(a))
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
	int ch, wanted;
	char str[SIZE];
	/* right most */
	char *p, *rm_increase, *rm_larger;
	while (fgets(str, SIZE, stdin), str[0] != '#') {
		rm_increase = 0;
		FORI(p, str, (ch = *p) != '\n') if (ch < *(p + 1)) rm_increase = p;
		*p = 0;		/* '\n' to 0 */
		/* all in non-increasing order */
		if (!rm_increase) {puts("No Successor"); continue;}
		wanted = *rm_increase;
		FORI(p, rm_increase + 1, (ch = *p)) 
			if (wanted < ch) rm_larger = p;
		SWAP(*rm_increase, *rm_larger);
		/* from wanted+1 to the last */
		while (rm_increase + 1 < p) {
			++rm_increase, --p;
			/* can't ++ -- in SWAP */
			SWAP(*rm_increase, *p);
		}
		printf("%s\n", str);
	}
	return 0;
}
