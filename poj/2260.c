/*
 * =====================================================================================
 *
 *       Filename:  2260.c
 *
 *    Description:  Error Correction
 *
 *        Created:  30.09.10
 *       Revision:  
 *       Compiler:  GCC 4.4
 *
 *         Author:  Yang Zhang, treblih.divad@gmail.com
 *        Company:  
 *
 * =====================================================================================
 */

#include <stdio.h>

#define	SIZE	128

static char matrix[SIZE][SIZE];

int main(int argc, const char *argv[])
{
	int i;
	while (scanf("%d", &row) != EOF && row) {
		for (i = 0; i < row; i++) {
			scanf("%s", matrix[i]);
		}
		for (i = 0; i < row; i++) {
			/* code */
		}
	}
	return 0;
}
