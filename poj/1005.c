/*
 * =====================================================================================
 *
 *       Filename:  1005.c
 *
 *    Description:  no algorithm
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

#include <math.h>
#include <stdio.h>

int main(int argc, const char *argv[])
{
	int n, i;
	double x, y, s;

	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%lf %lf", &x, &y);

		/*---------------------------------------
		 * (x^2 + y^2) * pi / 2 
		 * s = (x * x + y * y) * M_PI_2;
		 *
		 * POJ GCC doesn't recognize M_PI_2 ...
		 * use it's definition in math.h
		 *--------------------------------------*/
		s = (x * x + y * y) * 1.57079632679489661923;
		printf("Property %d: This property will begin eroding in year %d.\n", 
			i + 1, (int)ceil(s / 50));
	}
	puts("END OF OUTPUT.\n");
	return 0;
}
