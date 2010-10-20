/*
 * =====================================================================================
 *
 *       Filename:  113.c
 *
 *    Description:  Power of Cryptography
 *    		    math
 *
 *        Created:  19.10.10
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
	int n, p, base;
	while (scanf("%d%d", &n, &p) != EOF) {
		if (pow(base, n) == p) printf("%d\n", base);
	}
	return 0;
}
