/*
 * =====================================================================================
 *
 *       Filename:  1657.c
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
#include <stdlib.h>

int main(int argc, const char *argv[])
{
	char start[3] = { 0 };
	char end[3] = { 0 };
	int xs, xe, ys, ye, x, y;
	int n, i;
	int king, queen, rook, bishop;

	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%s %s", start, end);
		xs = start[0] - 0x41;
		ys = start[1] - 0x30;
		xe = end[0] - 0x41;
		ye = end[1] - 0x30;
		x = abs(xe - xs);
		y = abs(ye - ys);
		if (x == 0 && y == 0) {
			printf("0 0 0 0\n");
			continue;
		}
		king = x > y ? x : y;
		if (x == 0 || y == 0 || x == y) {
			queen = 1;
		} else {
			queen = 2;
		}
		if (x == 0 || y == 0) {
			rook = 1;
		} else {
			rook = 2;
		}
		/* parity judge */
		if ((start[0] - start[1]) % 2 == (end[0] - end[1]) % 2) {
			bishop = (x == y) ? 1 : 2;
		} else {
			bishop = 0;
		}

		bishop ?
		printf("%d %d %d %d\n", king, queen, rook, bishop) :
		printf("%d %d %d Inf\n", king, queen, rook);
	}
	return 0;
}
