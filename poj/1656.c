/*
 * =====================================================================================
 *
 *       Filename:  1656.c
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
	int n, i;
	int xs, ys;
	int color;
	int x, y, l;
	int cnt = 0;
	char cmd[8] = { 0 };
	int matrix[100][100] = { { 0 } };

	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%s %d %d %d", cmd, &x, &y, &l);
		/* 1-100 to 0-99 */
		x -= 1;
		y -= 1;
		/* TEST */
		if (cmd[0] == 'T') {
			for (xs = x; xs < x + l; xs++) {
				for (ys = y; ys < y + l; ys++) {
					(!matrix[xs][ys]) ? : ++cnt;
				}
			}
			printf("%d\n", cnt);
			cnt = 0;
		/* WHITE / BLACK */
		} else {
			color = (cmd[0] == 'W') ? 0 : 1;
			for (xs = x; xs < x + l; xs++) {
				for (ys = y; ys < y + l; ys++) {
					matrix[xs][ys] = color;
				}
			}
		}
	}
	return 0;
}
