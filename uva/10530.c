/*
 * =====================================================================================
 *
 *       Filename:  10530.c
 *
 *    Description:  Guessing Game
 *    		    bsearch
 *
 *        Created:  09.10.10
 *       Revision:  
 *       Compiler:  GCC 4.4
 *
 *         Author:  Yang Zhang, treblih.divad@gmail.com
 *        Company:  
 *
 * =====================================================================================
 */

#include <stdio.h>

static int low, high;
static FILE *fp;
#ifdef DB
	#define getchar()		getc(fp)
	#define	scanf(...)		fscanf(fp, __VA_ARGS__)
	#define	ungetc(c, stdin)	ungetc(c, fp)
#endif

int main(int argc, const char *argv[])
{
#ifdef DB
	fp = fopen("input", "r");
#endif
	int num;
	char tmp[8], judge[8];
next:
	low = 1;
	high = 10;
	while (scanf("%d", &num) != EOF && num) {
		scanf("%s %s", tmp, judge);
		if (judge[0] == 'h' && high >= num) high = num - 1;
		else if (judge[0] == 'l' && low <= num) low  = num + 1;
		if (low > high) {
			while (judge[0] != 'o') {
				scanf("%d%s%s", &num, tmp, judge);
			}
			puts("Stan is dishonest");
			goto next;
		} else if (judge[0] == 'o') {
			if (low <= num && num <= high)
				puts("Stan may be honest");
			else puts("Stan is dishonest");
			goto next;
		}
	}
	return 0;
}
