/*
 * =====================================================================================
 *
 *       Filename:  2871.c
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
	float n;
	float sub;
	while (scanf("%f", &n) != EOF) {
		sub = n;
		while (1) {
			scanf("%f", &n);
			if (n == 999) {
				goto end;
			}
			printf("%.2f\n", n - sub);
			sub = n;
		}
	}
end:
	printf("End of Output\n");
	return 0;
}
