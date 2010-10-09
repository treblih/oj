/*
 * =====================================================================================
 *
 *       Filename:  541.c
 *
 *    Description:  Error Correction
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

#define	SIZE	128

static int mat[SIZE][SIZE];
static FILE *fp;
#ifdef DB
	#define getchar()		getc(fp)
	#define	scanf(...)		fscanf(fp, __VA_ARGS__)
	#define	ungetc(c, stdin)	ungetc(c, fp)
#endif

int main(int argc, const char *argv[])
{
#ifdef DB
	fp = fopen("input", "r");
#endif
	int n, i, j, ch, sum;
	int err_row, err_col;

next:
	while (scanf("%d", &n) != EOF && n) {
		err_row = err_col = 0;
		/* loading & adding rows */
		for (i = 0; i < n; i++) {
			for (j = 0; j < n; j++) {
				scanf("%d", &mat[i][j]);
			}
		}
		for (i = 0; i < n; i++) {
			for (sum = 0, j = 0; j < n; j++) {
				sum += (mat[i][j]);
			}
			if (sum & 0x1) {
				if (err_row) {
					puts("Corrupt");
					goto next;
				/* index from 1 */
				} else err_row = i + 1;
			}
		}
		/* adding cols */
		for (j = 0; j < n; j++) {
			for (sum = 0, i = 0; i < n; i++) {
				sum += (mat[i][j]);
			}
			if (sum & 0x1) {
				if (err_col) {
					puts("Corrupt");
					goto next;
				/* index from 1 */
				} else err_col = j + 1;
			}
		}
		if (!err_row && !err_col) puts("OK");
		else if ((!err_row && err_col) || (err_row && !err_col))
			puts("Corrupt");
		else printf("Change bit (%d,%d)\n", err_row, err_col);
	}
	return 0;
}

#if 0
#include <stdio.h>

#define	SIZE	256

static char mat[SIZE][SIZE];

int main(int argc, const char *argv[])
{
	int n, i, j, ch, sum;
	int err_row, err_col;

next:
	while (scanf("%d", &n) != EOF && n) {
		err_row = err_col = 0;
		/* loading & adding rows */
		getchar();
		for (i = 0; i < n; i++) fgets(mat[i], SIZE, stdin);
		for (i = 0; i < n; i++) {
			for (sum = 0, j = 0; j < (n << 1); j += 2) {
				sum += (mat[i][j] - 0x30);
			}
			if (sum & 0x1) {
				if (err_row) {
					puts("Corrupt");
					goto next;
				/* index from 1 */
				} else err_row = i + 1;
			}
		}
		/* adding cols */
		for (j = 0; j < (n << 1); j += 2) {
			for (sum = 0, i = 0; i < n; i++) {
				sum += (mat[i][j] - 0x30);
			}
			if (sum & 0x1) {
				if (err_col) {
					puts("Corrupt");
					goto next;
				/* index from 1 */
				} else err_col = (j >> 1) + 1;
			}
		}
		if (!err_row && !err_col) puts("OK");
		else if ((!err_row && err_col) || (err_row && !err_col))
			puts("Corrupt");
		else printf("Change bit (%d,%d)\n", err_row, err_col);
	}
	return 0;
}
#endif
