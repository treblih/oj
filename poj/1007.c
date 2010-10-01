/*
 * =====================================================================================
 *
 *       Filename:  1007.c
 *
 *    Description:  DNA Sorting
 *
 *        Created:  29.09.10
 *       Revision:  
 *       Compiler:  GCC 4.4 *
 *         Author:  Yang Zhang, treblih.divad@gmail.com
 *        Company:  
 *
 * =====================================================================================
 */

#include <stdio.h>

#define	ROW	128

static struct dna {
	int unsort;
	char *str;
} dna[ROW];

static char str[ROW][64];

int cmpr(const void *a1, const void *b1)
{
	const struct dna *a = a1;
	const struct dna *b = b1;
	return a->unsort > b->unsort;
}

int main(int argc, const char *argv[])
{
	int n, row, i, j, k, set;
	int same;
	int unsort;

	scanf("%d", &set);
	while (set--) {
		scanf("%d%d", &n, &row);
		for (i = 0; i < row; i++) {
			scanf("%s", str[i]);
			dna[i].str = str[i];
		}
		/* every row */
		for (i = 0; i < row; i++) {
			same = 1;
			unsort = 0;
			/* deal with n chars in one row */
			for (j = 0; j < n; ++j) {
				/* met with same consecutive char(s), 
				 * add unsortness directly */
				if (dna[i].str[j] == dna[i].str[j + 1]) {
					++same;
					continue;
				}
				/* here, same == 0, unsort */
				for (k = j + 1; k < n; k++) {
					if (dna[i].str[j] > dna[i].str[k]) {
						++unsort;
					}
				}
				/* if no same, no error */
				dna[i].unsort += unsort * same;
				same = 1;
				unsort = 0;
			}
		}
		/* got the unsortness of every row */
		qsort(dna, row, sizeof(struct dna), cmpr);
		for (i = 0; i < row; i++) {
			/* puts(dna[i].str); */
			printf("%s\n", dna[i].str);
		}
	}
	return 0;
}
