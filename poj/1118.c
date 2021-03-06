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
	int i, x, y, cases, ch, len;
	int cnt, sentinel;
	_Bool found = false;

	scanf("%d", &cases);
	while (cases--) {
		cnt = len = 0;
		/* load all data */
		while (1) {
			if ((ch = getchar()) != '\n') ungetc(ch, stdin);
			else break;
			scanf("%d%d", &x, &y);
			/* if there's the same */
			for (i = 0; slope[i].cnt; i++) {
				if (slope[i].x * y == slope[i].y * x) {
					slope[i].cnt++;
					found = true;
					break;
				}
			}
			if (found) {
				found = false;
				continue;
			} else {
				/* not found, set a new */
				slope[len].cnt = 1;
				slope[len].x = x;
				slope[len++].y = y;
			}
		}
		/* find max */
		for (i = 0; sentinel = slope[i].cnt, i < len; i++) {
			if (sentinel > cnt) {
				cnt = sentinel;
			}
		}
		if (cases) printf("%d\n", cnt);
	}
	return 0;
}
