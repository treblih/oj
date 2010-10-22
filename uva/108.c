/*
 * =====================================================================================
 *
 *       Filename:  108.c
 *
 *    Description:  Maximum Sum
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

#define	SIZE	100
static int dms;
static int mat[SIZE][SIZE];
#ifdef DB
	#define getchar()		getc(fp)
	#define	scanf(...)		fscanf(fp, __VA_ARGS__)
	#define	ungetc(c, stdin)	ungetc(c, fp)
#endif
static FILE *fp;

int max_1d(int a[])
{
	int i, tmp, sum = 0, max = 0;
	for (i = 0; i < dms; ++i) {
		tmp = sum + a[i];
		sum = tmp > a[i] ? tmp : a[i];
		if (max < sum) max = sum;
	}
	return max;
}

int max_2d()
{
	int sum, i, j, k;
	int max = 0;
	int tmp[SIZE] = {0};
	for (i = 0; i < dms; ++i) {
		for (j = i; j < dms; ++j) {
			for (k = 0; k < dms; ++k) tmp[k] += mat[j][k];
			sum = max_1d(tmp);
			if (max < sum) max = sum;
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
	int i, j;
	scanf("%d", &dms);
	for (i = 0; i < dms; ++i)
		for (j = 0; j < dms; ++j) scanf("%d", &mat[i][j]);
	/* load done */
	printf("%d\n", max_2d());
	return 0;
}
