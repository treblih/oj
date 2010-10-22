/*
 * =====================================================================================
 *
 *       Filename:  836.c
 *
 *    Description:  Largest Submatrix
 *    		    dp
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

#define	SIZE	32
static int dms;
static char mat[SIZE][SIZE];
#ifdef DB
	#define getchar()		getc(fp)
	#define	scanf(...)		fscanf(fp, __VA_ARGS__)
	#define	ungetc(c, stdin)	ungetc(c, fp)
#endif
static FILE *fp;
int max_1d(char a[])
{
	int i, cnt = 0, max = 0;
	char *p = a;
	for (i = 0; i < dms; ++i, ++p) {
		if (*p == 1) ++cnt;
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
 *  111000
 *-----------------------------------------------------------------------------*/
int max_2d()
{
	int sum, i, j, k;
	int max = 0;
	char tmp[SIZE] = {0};
	for (i = 0; i < dms; ++i) {
		for (j = i; j < dms; ++j) {
			for (k = 0; k < dms; ++k) {
				/* first set tmp[] */
				if (j == i) tmp[k] = mat[j][k] - 0x30;
				/* if any 0 in the COL, set to 0 */
				else tmp[k] &= (mat[j][k] - 0x30);
			}
			sum = max_1d(tmp) * (j - i + 1);
			if (max < sum) max = sum;
		}
		memset(tmp, 0, dms);
	}
	return max;
}

int main()
{
#ifdef DB
	fp = fopen("input", "r");
#endif
	int i, cases;
	scanf("%d", &cases);
	while (cases--) {
		scanf("%s", mat[0]);
		dms = strlen(mat[0]);	/* n*n */
		for (i = 1; i < dms; ++i) scanf("%s", mat[i]);
		/* load done */
		printf("%d\n", max_2d());
		if (cases) putchar('\n');
	}
	return 0;
}
