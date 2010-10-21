/*
 * =====================================================================================
 *
 *       Filename:  10664.c
 *
 *    Description:  Luggage
 *    		    backtrack
 *
 *        Created:  20.10.10
 *       Revision:  
 *       Compiler:  GCC 4.4
 *
 *         Author:  Yang Zhang, treblih.divad@gmail.com
 *        Company:  
 *
 * =====================================================================================
 */

#include <stdio.h>

enum {
	NO,
	YES
};

static int half;
static int wght[32];

int cmpr(const void *a, const void *b)
{
	return *(int *)b - *(int *)a;
}

int backtrack(int idx)
{
	if (sum == half) {puts("YES"); return YES;}
	if (sum > half) return NO;
	
}

int main(int argc, const char *argv[])
{
	int cases, ch, cnt, sum;
	scanf("%d", &cases);
	while (cases--) {
		cnt = 0;
		while ((ch = getchar()) != '\n') {
			ungetc(ch, stdin);
			scanf("%d", &wght[cnt++]);
		}
		/* load done */
		for (i = 0, sum = 0; i < cnt; ++i) sum += wght[i];
		/* odd or only one -> can't split equally */
		if (sum & 1 || cnt == 1) {puts("NO"); continue;}
		half = sum >> 1;
		/* descending */
		qsort(wght, cnt, 4, cmpr);
		backtrack(0);
	}
	return 0;
}
