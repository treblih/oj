/*
 * =====================================================================================
 *
 *       Filename:  10696.c
 *
 *    Description:  f91
 *    		    recursion
 *
 *        Created:  17.10.10
 *       Revision:  
 *       Compiler:  GCC 4.4
 *
 *         Author:  Yang Zhang, treblih.divad@gmail.com
 *        Company:  
 *
 * =====================================================================================
 */

#include <stdio.h>

int f91(int n)
{
	if (n <= 100) return f91(f91(n + 11));
	else return n - 10;
}

int main(int argc, const char *argv[])
{
	int n;
	while (scanf("%d", &n), n) {
		printf("f91(%d) = %d\n", n, f91(n));
	}
	return 0;
}
