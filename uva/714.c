/*
 * =====================================================================================
 *
 *       Filename:  714.c
 *
 *    Description:  Copying Books
 *		    bsearch & greedy
 *        Created:  08.10.10
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
#include <stdint.h>

#define	SIZE		512

static char slash_pos[SIZE];
static int npeople, nbook;
static int64_t books[SIZE];

int min_of_max(int64_t max)
{
	int people = 0, i = nbook - 1;
	int64_t sum;
	while (1) {
		++people;
		/* reverse counting */
		for (sum = 0; ; i--) {
			/* not >= max */
			if ((sum += books[i]) > max) break;
			if (!i) goto end;
		}
	}
end:
	return people;
}

int main(int argc, const char *argv[])
{
	int cases, i, sum, one_by_one;
	int64_t low, high, mid, tmp;

	scanf("%d", &cases);
	while (cases--) {
		low = high = 0LL;
		scanf("%d%d", &nbook, &npeople);
		for (i = 0; i < nbook; i++) {
			scanf("%lld", &tmp);
			if (low < tmp) low = tmp;
			high += tmp;
			books[i] = tmp;
		}
		/* load done */
		/* high is always ok while low always fails 
		 * low is the maxmium in the books, while high is the total
		 * bsearch to find the fittest high */
		while (low < high) {
			mid  = (low + high) >> 1;
			if (min_of_max(mid) <= npeople)
				high = mid;
			/* essential 1, low9-high10 */
			else low = mid + 1;
		}
		/* mark the slash position 
		 * n people, n-1 slashes */
		for (i = nbook - 1, sum = books[i], --npeople; ; --i) {
			/* reverse counting */
			if (i == npeople) break;
			if (sum + books[i - 1] > high) {
				slash_pos[i] = 1;
				sum = books[i - 1];
				--npeople;
			} else sum += books[i - 1];
		}
		for ( ; npeople; npeople--) slash_pos[npeople] = 1;

		/* print out */
		printf("%lld", books[0]);
		for (i = 1; i < nbook; i++) {
			if (slash_pos[i]) printf(" /");
			printf(" %lld", books[i]);
		}
		printf("\n");
		memset(slash_pos, 0, nbook);
	}
	return 0;
}
