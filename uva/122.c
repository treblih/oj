/*
 * =====================================================================================
 *
 *       Filename:  122.c
 *
 *    Description:  Trees on the Level
 *    		    brute force & matrix
 *
 *        Created:  19.10.10
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

/* for start from 1, and 256 is the max */
#define	SIZE	260

static int not, max;
static int tree[SIZE];
#ifdef DB
	#define getchar()		getc(fp)
	#define	scanf(...)		fscanf(fp, __VA_ARGS__)
	#define	ungetc(c, stdin)	ungetc(c, fp)
#endif
static FILE *fp;


void position(char *p)
{
	int val, ch, idx = 1;
	sscanf(p, "%d", &val);
	while (*++p != ',') ;
	while ((ch = *++p) != ')') {
		if (ch == 'L') idx <<= 1;
		else idx = (idx << 1) + 1;
	}
	if (tree[idx]) not = 1;
	if (max < idx) max = idx;
	tree[idx] = val;
}

int main(int argc, const char *argv[])
{
#ifdef DB
	fp = fopen("input", "r");
#endif
	char expr[64];
	int i;
	while (scanf("%s", expr) != EOF) {
		/* empty */
		if (expr[1] == ')') {putchar('\n'); continue;}
		position(expr + 1);
		while (scanf("%s", expr), expr[1] != ')') {
			if (!not) position(expr + 1);
		}
		if (!not) {
			printf("%d", tree[1]);
			for (i = 2; i <= max; ++i) {
				if (tree[i]) printf(" %d", tree[i]);
			}
			putchar('\n');
		} else puts("not complete");
		not = max = 0;
		memset(tree, 0, max << 2);
	}
	return 0;
}
