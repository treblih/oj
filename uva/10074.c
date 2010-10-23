/*
 * =====================================================================================
 *
 *       Filename:  10074.c
 *
 *    Description:  Take the Land
 *    		    linear dp & 2d maxsum
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

#define	SIZE	128
static int row, col;
static int mat[SIZE][SIZE];
#ifdef DB
	#define getchar()		getc(fp)
	#define	scanf(...)		fscanf(fp, __VA_ARGS__)
	#define	ungetc(c, stdin)	ungetc(c, fp)
#endif
static FILE *fp;
int max_1d(int a[])
{
	int i, cnt = 0, max = 0;
	for (i = 0; i < col; ++i) {
		if (!a[i]) ++cnt;
		else {
			if (max < cnt) max = cnt;
			cnt = 0;
		}
	}
	/* for the 1100111, last time won't invole into 'else' part */
	if (max < cnt) max = cnt;
	return max;
}

/*-----------------------------------------------------------------------------
 *  111001
 *  111011
 *  111010 will be 
 *
 *  111000 don't like 836, this time we need 0
 *-----------------------------------------------------------------------------*/
int max_2d()
{
	int sum, i, j, k;
	int max = 0;
	int tmp[SIZE] = {0};
	for (i = 0; i < row; ++i) {
		for (j = i; j < row; ++j) {
			for (k = 0; k < col; ++k) {
				/* first set tmp[] */
				if (j == i) tmp[k] = mat[j][k];
				/* if any 0 in the COL, set to 0 */
				else tmp[k] |= mat[j][k];
			}
			sum = max_1d(tmp) * (j - i + 1);
			if (max < sum) max = sum;
		}
		memset(tmp, 0, col << 2);
	}
	return max;
}

int main()
{
#ifdef DB
	fp = fopen("input", "r");
#endif
	int i, j;
	while (scanf("%d%d", &row, &col), row) {
		for (i = 0; i < row; ++i)
			for (j = 0; j < col; ++j) scanf("%d", &mat[i][j]);
		printf("%d\n", max_2d());
	}
	return 0;
}
