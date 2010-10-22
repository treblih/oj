/*
 * =====================================================================================
 *
 *       Filename:  10827.c
 *
 *    Description:  Maximum Sum on a Torus
 *		    matrix dp 
 *
 *        Created:  22.10.10
 *       Revision:  
 *       Compiler:  GCC 4.4
 *
 *         Author:  Yang Zhang, treblih.divad@gmail.com
 *        Company:  
 *
 * =====================================================================================
 */

#include <stdio.h>
#include <string.h>

#define	SIZE	80
static int dms;
static int mat[SIZE<<1][SIZE];
#ifdef DB
	#define getchar()		getc(fp)
	#define	scanf(...)		fscanf(fp, __VA_ARGS__)
	#define	ungetc(c, stdin)	ungetc(c, fp)
#endif
static FILE *fp;
/*--------------------------------
 *  111111111
 *  222222222
 *  333333333
 *  444444444
 *  111111111
 *  222222222
 *  333333333
 *--------------------------------*/

int max_1d(int a[])
{
	int i, tmp_ax, tmp_in;
	int sum_ax = 0, sum_in = 0, max = 0, min = 0, total = 0;
	for (i = 0; i < dms; ++i) {
		total += a[i];
		tmp_ax = sum_ax + a[i];
		tmp_in = sum_in + a[i];
		sum_ax = tmp_ax > a[i] ? tmp_ax : a[i];
		sum_in = tmp_in < a[i] ? tmp_in : a[i];
		if (max < sum_ax) max = sum_ax;
		if (min > sum_in) min = sum_in;
	}
	return max > (total - min) ? max : total - min;
}

int max_2d()
{
	int sum, i, j, x;
	int max = 0;
	int tmp[SIZE] = {0};
	/* for every i, j will expand dms lines */
	for (i = 0; i < dms; ++i) {
		for (j = i; j < dms + i; ++j) {
			for (x = 0; x < dms; ++x) tmp[x] += mat[j][x];
			sum = max_1d(tmp);
			if (max < sum) max = sum;
			/* printf("i:%d  j:%2d  sum:%4d  max:%4d\n", i, j, sum, max); */
		}
		memset(tmp, 0, dms << 2);
	}
	return max;
}

int main()
{
#ifdef DB
	fp = fopen("input", "r");
#endif
	int i, j, cases;
	scanf("%d", &cases);
	while (cases--) {
		scanf("%d", &dms);
		for (i = 0; i < dms; ++i)
			for (j = 0; j < dms; ++j) {
				scanf("%d", &mat[i][j]);
				/* the last line is useless */
				mat[i+dms][j] = mat[i][j];
			}
		/* load done */
		printf("%d\n", max_2d());
	}
	return 0;
}
