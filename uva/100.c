/*
 * =====================================================================================
 *
 *       Filename:  100.c
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

static long long int seq[1000010];

/* return the sequence length of a certain number */
long long int deal(long long int dec)
{
	long long int n = 1;
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

long long int max(long long int low, long long int high)
{
	long long int i;
	long long int tmp;
	for (i = low; i <= high; i++) {
		if (seq[i] > tmp) {
			tmp = seq[i];
		}
	}
	return tmp;
}

long long int main(long long int argc, const char *argv[])
{
	long long int i;
	long long int tmp = 0;
	long long int low, high;

	while (scanf("%d%d", &low, &high) != EOF) {
		if (low <= 0 || high <= 0 || low >= 1000000 || high >= 1000000) {
			 break;
		}
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
