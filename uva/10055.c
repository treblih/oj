/*
 * =====================================================================================
 *
 *       Filename:  10055.c
 *
 *    Description:  Hashmat the brave warrior
 *
 *        Created:  08.10.10
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
	long long a, b;
	while (scanf("%lld%lld", &a, &b) != EOF) {
		printf("%lld\n", a > b ? a - b : b - a);
	}
	return 0;
}
