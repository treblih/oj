/*
 * =====================================================================================
 *
 *       Filename:  1118.c
 *
 *    Description:  force
 *    		    y1/x1 == y2/x2 => x2*y1 == x1*y2 => no double
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
#include <stdbool.h>

#define	SIZE	700

static struct slope {
	int x;
	int y;
	int cnt;
} slope[SIZE];

int main(int argc, const char *argv[])
{
	int n, i, j;
	int cnt = 0;
	_Bool found = false;
	int sentinel;
	int x, y;

	while (scanf("%d", &n) != EOF && n) {
		for (i = 0; i < n; i++) {
			scanf("%d%d", &x, &y);
			/* if there's the same */
			for (j = 0; slope[j].cnt; j++) {
				if (slope[j].x * y == slope[j].y * x) {
					slope[j].cnt++;
					found = true;
					break;
				}
			}
			if (found) {
				found = false;
				continue;
			} else {
				/* not found, set a new */
				slope[j].cnt = 1;
				slope[j].x = x;
				slope[j].y = y;
			}
		}
		/* find max */
		for (j = 0; sentinel = slope[j].cnt; j++) {
			if (sentinel > cnt) {
				cnt = sentinel;
			}
		}
	}
	printf("%d\n", cnt);
	
	return 0;
}
