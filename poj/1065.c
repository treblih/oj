/*
 * =====================================================================================
 *
 *       Filename:  1065.c
 *
 *    Description:  greedy & qsort
 *
 *        Created:  27.09.10
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

#define	SIZE	5200

struct wood {
	int len;
	int wei;
};

int cmp_len(const void *a1, const void *b1)
{
	const struct wood *a = a1;
	const struct wood *b = b1;
	if (a->len == b->len) {
		return a->wei > b->wei;
	}
	return a->len > b->len;
}

int cmp_wei(const void *a1, const void *b1)
{
	const struct wood *a = a1;
	const struct wood *b = b1;
	if (a->wei == b->wei) {
		return a->len > b->len;
	}
	return a->wei > b->wei;
}

int main(int argc, const char *argv[])
{
	int n, i, j;
	int num;
	int setup_len, setup_wei;
	struct wood *sticks = calloc(SIZE, sizeof(struct wood));
	/* while (scanf("%d", &n) != EOF) { */
		scanf("%d", &n);
		for (i = 0; i < n; i++) {
			/* get data */
			scanf("%d", &num);
			for (j = 0; j < num; j++) {
				scanf("%d%d", &sticks[j].len, &sticks[j].wei);
			}

			/* sort by length mainly, weight secondly */
			qsort(sticks, num, sizeof(struct wood), cmp_len);
			for (j = 0, setup_len = 1; j < num - 1; ++j) {
				if (sticks[j].len == sticks[j + 1].len) {
					continue;
				}
				/* ought to be j.len < j+1.len */
				/* namely, a boundary */
				if (sticks[j].wei <= sticks[j + 1].wei) {
					continue;
				}
				++setup_len;
			}
			/* sort by weight mainly, length secondly */
			qsort(sticks, num, sizeof(struct wood), cmp_wei);
			for (j = 0, setup_wei = 1; j < num - 1; ++j) {
				if (sticks[j].wei == sticks[j + 1].wei) {
					continue;
				}
				/* ought to be j.wei < j+1.wei */
				if (sticks[j].len <= sticks[j + 1].len) {
					continue;
				}
				++setup_wei;
			}
			printf("%d\n", setup_len > setup_wei ? setup_wei : setup_len);
		}
	/* } */
	free(sticks);
	return 0;
}
