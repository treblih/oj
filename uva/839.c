/*
 * =====================================================================================
 *
 *       Filename:  839.c
 *
 *    Description:  Not so Mobile
 *    		    recursion
 *
 *        Created:  04.10.10
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
	#define	scanf(...)		fscanf(fp, __VA_ARGS__)
#endif

static FILE *fp;
static int fail;

int traverse()
{
	int wl, dl, wr, dr;
	scanf("%d%d%d%d", &wl, &dl, &wr, &dr);
	if (!wl) wl = traverse();
	if (!wr) wr = traverse();
	if (wl * dl != wr * dr) fail = 1;
	return wl + wr;
}

int main(int argc, const char *argv[])
{
#ifdef DB
	fp = fopen("input.txt", "r");
#endif
	int cases;
	scanf("%d", &cases);
	while (cases--) {
		traverse();
		if (fail) {
			puts("NO");
		} else {
			puts("YES");
		}
		fail = 0;
		if (cases) {
			putchar('\n');
		}
	}
	return 0;
}
