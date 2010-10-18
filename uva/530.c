/*
 * =====================================================================================
 *
 *       Filename:  530.c
 *
 *    Description:  Binomial Showdown
 *    		    math
 *
 *        Created:  16.10.10
 *       Revision:  
 *       Compiler:  GCC 4.4
 *
 *         Author:  Yang Zhang, treblih.divad@gmail.com
 *        Company:  
 *
 * =====================================================================================
 */

#include <stdio.h>

int main(int argc, const char *argv[])
{
	int C, n;
	long long product, s;
	while (scanf("%d%d", &C, &n), C) {
		if (!n || C == n) {puts("1");; continue;}
		/* use the larger */
		n = C >> 1 > n ? C - n : n;
		product = ++n;
		s = 2;
		/* multiply before divide */
		while (n < C) {
			product *= ++n;
			if (!(product % s)) {
				product /= s;
				++s;
			} else s *= (s + 1);
		}
		printf("%lld\n", product);
	}
	return 0;
}
