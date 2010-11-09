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
#define NOT	-1
#define	SIZE	16000

static int not_cnt, not, max;
static int tree[SIZE];
#ifdef DB
	#define getchar()		getc(fp)
	#define	scanf(...)		fscanf(fp, __VA_ARGS__)
	#define	ungetc(c, stdin)	ungetc(c, fp)
#endif
static FILE *fp;

/* fill the data into array */
void position(char *p)
{
	int val, ch, idx = 1;
	sscanf(p, "%d", &val);
	while (*++p != ',') ;
	while ((ch = *++p) != ')') {
		/* not complete yet */
		if (!tree[idx]) {
			/* mark as NOT at the moment */
			tree[idx] = NOT;
			++not_cnt;
		}
		if (ch == 'L') idx <<= 1;
		else idx = (idx << 1) + 1;
	}
	/* not (tree[idx]), because NOT also != 0 */
	/* namely, 2 data occupied the same position */
	if (tree[idx] > 0) not = 1;
	if (max < idx) max = idx;	/* used max */
	/* if has been marked */
	if (tree[idx] == NOT) --not_cnt;
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
		/* the first won't be in trouble */
		position(expr + 1);
		while (scanf("%s", expr), expr[1] != ')') {
			/* if not, continue to read all bytes in buf */
			if (!not) position(expr + 1);
		}
		/* not_cnt must be sub to 0, otherwise the tree is not complete */
		if (!not && !not_cnt) {
			printf("%d", tree[1]);
			for (i = 2; i <= max; ++i) {
				/* we care about an empty node during a path, not after */
				if (tree[i]) printf(" %d", tree[i]);
			}
			putchar('\n');
		} else puts("not complete");
		not_cnt = not = max = 0;
		/* memset(tree, 0, (max + 1) << 2); WA, don't know why */
		memset(tree, 0, sizeof(tree));
	}
	return 0;
}
int main(int argc, const char *argv[])
{
    SDF_PROXY
        sdf
        return 0;
}
int main(int argc, const char *argv[])
{
        if (1) {
            do {
            s   a       sdfs    aaa     aaaa    
            } while (1);
        }
        return 0;
}
