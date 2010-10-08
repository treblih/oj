/*
 * =====================================================================================
 *
 *       Filename:  105.c
 *
 *    Description:  The Skyline Problem
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

#ifdef DB
	#define getchar()		getc(fp)
	#define	scanf(...)		fscanf(fp, __VA_ARGS__)
	#define	ungetc(c, stdin)	ungetc(c, fp)
#endif
#define	SIZE	10010

static int x[SIZE];
static FILE *fp;

int main(int argc, const char *argv[])
{
#ifdef DB
	fp = fopen("input", "r");
#endif
	int start, height, end, i;
	int x_max = 0;
	while (scanf("%d%d%d", &start, &height, &end) != EOF) {
		if (x_max < end) x_max = end;
		for (i = start; i < end; i++) {
			if (x[i] < height) x[i] = height;
		}
	}
	/* ignore 0 */
	for (i = 1, height = 0; i < x_max; i++) {
		if (x[i] != height) {
			height = x[i];
			printf("%d %d ", i, height);
		}
	}
	printf("%d 0\n", x_max);
	return 0;
}
