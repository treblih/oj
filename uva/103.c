/*
 * =====================================================================================
 *
 *       Filename:  103.c
 *
 *    Description:  Stacking Boxes
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

static boxes[32][10];

int main(int argc, const char *argv[])
{
	while (scanf("%d%d", &n, &dms) != EOF) {
		for (i = 1; i <= n; ++i) {
			for (j = 0; j < dms; ++j) {
				scanf("%d", &boxes[i][j]);
			}
		}
	}
	return 0;
}
