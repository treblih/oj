/*
 * =====================================================================================
 *
 *       Filename:  1928.c
 *
 *    Description:  The Peanuts
 *
 *        Created:  01.10.10
 *       Revision:  
 *       Compiler:  GCC 4.4
 *
 *         Author:  Yang Zhang, treblih.divad@gmail.com
 *        Company:  
 *
 * =====================================================================================
 */

#include <stdio.h>

static struct peanut {
	int x, y;
	int amount;
} peanut[2550];

int cmpr(const void *a1, const void *b1)
{
	const struct peanut *a = a1;
	const struct peanut *b = b1;
	return b->amount - a->amount;
}

int main(int argc, const char *argv[])
{
	int x, y, xs, ys, time, amount, size, cost;
	int i, j, k, n;

	scanf("%d", &n);
	while (n--) {
		scanf("%d%d%d", &y, &x, &time);
		for (i = 1, k = 0; i <= y; i++) {
			for (j = 1; j <= x; j++) {
				scanf("%d", &amount);
				if (amount) {
					peanut[k].x = j;
					peanut[k].y = i;
					peanut[k++].amount = amount;
				}
			}
		}
		/* only first k hold val, namely not 0
		 * big -> small */
		qsort(peanut, k, sizeof(struct peanut), cmpr);
		amount = 0;
		x = y = 0;

		/* get started
		 * cost == goto + pluck + go out */
		for (i = 0; i < k; i++, x = xs, y = ys) {
			xs = peanut[i].x;
			ys = peanut[i].y;
			if (!x) {
				/* get into field, no x */
				cost = (ys + 1 + ys);
			} else {
				cost = (abs(ys - y) + \
					abs(xs - x) + 1 + ys);
			}
			if (time < cost) {
				break;
			}
			/* excluding "go out" */
			time -= (cost - ys);
			amount += peanut[i].amount;
		}
		printf("%d\n", amount);
	}
	return 0;
}
