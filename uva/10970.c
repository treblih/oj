/*
 * =====================================================================================
 *
 *       Filename:  10970.c
 *
 *    Description:  Big Chocolate
 *    		    simulation
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
	int m, n;
	while (scanf("%d%d", &m, &n) != EOF) {
		printf("%d\n", m * n - 1);
	}
	return 0;
}
