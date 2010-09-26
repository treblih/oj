/*
 * =====================================================================================
 *
 *       Filename:  1004.c
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

#include <stdio.h>

int main(int argc, const char *argv[])
{
	int i;
	double monthly, total;
	for (i = 0; i < 12; i++) {
		scanf("%lf", &monthly);
		total += monthly;
	}
	printf("$%3.2f\n", total / 12);
	return 0;
}
