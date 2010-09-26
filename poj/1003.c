/*
 * =====================================================================================
 *
 *       Filename:  1003.c
 *
 *    Description:  force
 *    		    've test that 276 can make it be 5.20
 *
 *        Created:  26.09.10
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
	int i;
	int n = 276;
	double total = 0;
	double mid;
	double aux[n];

	for (i = 0; i < n; i++) {
		mid = i + 2;
		total += 1 / mid;
		aux[i] = total;
	}
	while (1) {
		scanf("%lf", &mid);
		/* can't be (!mid) */
		if (mid < 0.01) {
			break;
		}
		for (i = 0; i < n; i++) {
			if (mid <= aux[i]) {
				break;
			}
		}
		printf("%d card(s)\n", i + 1);
	}
	return 0;
}
