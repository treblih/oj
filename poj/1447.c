/*
 * =====================================================================================
 *
 *       Filename:  1447.c
 *
 *    Description:  no algorithm
 *
 *        Created:  28.09.10
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
	int set = 0;
	int i;
	int n, total, avg, one;
	int high[128] = { 0 };

	while (scanf("%d", &n) != EOF && n != 0) {
		++set;
		total = 0;
		/* get total */
		for (i = 0; i < n; ++i) {
			scanf("%d", &high[i]);
			total += high[i];
		}
		avg = total / n;

		total = 0;
		for (i = 0; i < n; ++i) {
			if (high[i] > avg) {
				total += high[i] - avg;
			}
		}
		printf("Set #%d\n"
		       "The minimum number of moves is %d.\n\n", 
		       set, total);
	}
	return 0;
}
