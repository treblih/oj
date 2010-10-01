/*
 * =====================================================================================
 *
 *       Filename:  1207.c
 *
 *    Description:  3n + 1
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

static int seq[1000010];

/* return the sequence length of a certain number */
int deal(int dec)
{
	int n = 1;
	while (dec != 1) {
		/* odd */
		if (dec & 0x1) {
			dec = dec * 3 + 1;
		/* even */
		} else {
			dec >>= 1;
		}
		++n;
	}
	return n;
}

int max(int low, int high)
{
	int i;
	int tmp;
	for (i = low; i <= high; i++) {
		if (seq[i] > tmp) {
			tmp = seq[i];
		}
	}
	return tmp;
}

int main(int argc, const char *argv[])
{
	int i;
	int tmp = 0;
	int low, high;

	while (scanf("%d%d", &low, &high) != EOF) {
		if (low > high) {
			tmp = low; low = high; high = tmp;
		}
		for (i = low; i <= high; i++) {
			if (!seq[i]) {
				seq[i] = deal(i);
			}
		}
		if (tmp) {
			printf("%d %d %d\n", high, low, max(low, high));
		} else {
			printf("%d %d %d\n", low, high, max(low, high));
		}
	}
	return 0;
}
