/*
 * =====================================================================================
 *
 *       Filename:  270.c
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
#ifdef DB
	#define getchar()		getc(fp)
	#define	scanf(...)		fscanf(fp, __VA_ARGS__)
	#define	ungetc(c, stdin)	ungetc(c, fp)
#endif

#define	SIZE	700

static FILE *fp;
static struct slope {
	int x;
	int y;
	int cnt;
} slope[SIZE];

int main(int argc, const char *argv[])
{
#ifdef DB
	fp = fopen("input", "r");
#endif
	int i, x, y, cases, ch, len;
	int cnt, sentinel;
	int found = 0;

	scanf("%d", &cases);
	getchar();
	getchar();
	while (cases--) {
		cnt = len = 0;
		/* load all data */
		while (1) {
			if ((ch = getchar()) != EOF && ch != '\n') ungetc(ch, stdin);
			else break;
			scanf("%d%d", &x, &y);
			/* if there's the same */
			for (i = 0; i < len; i++) {
				if (slope[i].x * y == slope[i].y * x) {
					slope[i].cnt++;
					found = 1;
					break;
				}
			}
			if (found) found = 0;
			else {
				/* not found, set a new */
				slope[len].cnt = 1;
				slope[len].x = x;
				slope[len++].y = y;
			}
			getchar();
		}
		/* find max */
		for (i = 0; sentinel = slope[i].cnt, i < len; i++) {
			if (sentinel > cnt) {
				cnt = sentinel;
			}
		}
 		printf("%d\n", cnt);
		if (cases) printf("\n");
	}
	return 0;
}
