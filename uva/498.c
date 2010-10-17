/*
 * =====================================================================================
 *
 *       Filename:  498.c
 *
 *    Description:  Polly the Polynomial
 *    		    math & simulation
 *
 *        Created:  16.10.10
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
#include <ctype.h>

#define	SIZE	128
#ifdef DB
	#define getchar()		getc(fp)
	#define	scanf(...)		fscanf(fp, __VA_ARGS__)
	#define	ungetc(c, stdin)	ungetc(c, fp)
#endif
static FILE *fp;

static char expr[400000];
static long long polynomial[1000001];

char *find_left(char *s)
{
	while (*s == ' ') --s;
	while (isdigit(*s) || *s == '-') --s;
	return s + 1;
}

char *find_right(char *s)
{
	while (isdigit(*s) || *s == '-') ++s;
	while (*s == ' ') ++s;
	return s;
}

int main(int argc, const char *argv[])
{
#ifdef DB
	fp = fopen("input", "r");
#endif
	int n, len, i, flag;
	long long x, y;
	char *p;
		/* polynomial */
	while (fgets(expr, SIZE, fp) != NULL) {
		len = strlen(expr) - 1;	/* '\n' followed */
		for (p = find_left(expr + len - 1), n = 0; p >= expr; ) {
			sscanf(p, "%lld", &polynomial[n++]);
			if (p - 1 <= expr) break;
			p = find_left(p - 1);
		}
		/* x0 .. xm */
		fgets(expr, SIZE, fp);
		len = strlen(expr) - 1;
		for (p = expr, flag = 0; p < expr + len; ) {
			sscanf(p, "%lld", &x);
			for (i = 0, y = 0; i < n; ++i) {
				if (i >= 2) x *= x;
				if (!i) y += polynomial[0];
				else y += polynomial[i] * x;
			}
			if (!flag) {printf("%lld", y); flag = 1;}
			else printf(" %lld", y);
			if (p < expr + len) p = find_right(p);
			else break;
		}
		memset(expr, 0, SIZE);
		putchar('\n');
	}
	return 0;
}
