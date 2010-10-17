/*
 * =====================================================================================
 *
 *       Filename:  10035.c
 *
 *    Description:  Primary Arithmetic
 *    		    bignum
 *
 *        Created:  SIZE.10.10
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
#ifdef DB
	#define getchar()		getc(fp)
	#define	scanf(...)		fscanf(fp, __VA_ARGS__)
	#define	ungetc(c, stdin)	ungetc(c, fp)
#endif
static FILE *fp;

#define	SIZE	16

static int max;

int n2big(int a, int big[])
{
	int i;
	for (i = 0; a; i++) {
		big[i] = a % 10;
		a /= 10;
	}
	return i;
}

void carry_cnt(int a[], int b[])
{
	int i, carry = 0, cf = 0;
	/* high bits of short arr will be 0 */
	for (i = 0; i < max; i++) {
		if (a[i] + b[i] + cf > 9) {
			++carry; 
			cf = 1;
		}
		else cf = 0;
	}
	if (!carry) {puts("No carry operation."); return;}
	printf("%d carry operation", carry);
	if (carry == 1) puts(".");
	else puts("s.");
}

int main(int argc, const char *argv[])
{
#ifdef DB
	fp = fopen("input", "r");
#endif
	int a, b, len_a, len_b;
	int big_a[SIZE];
	int big_b[SIZE];
	while (scanf("%d%d", &a, &b), a || b) {
		/* int not char */
		memset(big_a, 0, SIZE << 2);
		memset(big_b, 0, SIZE << 2);
		len_a = n2big(a, big_a);
		len_b = n2big(b, big_b);
		max = len_a > len_b ? len_a : len_b;
		carry_cnt(big_a, big_b);
	}
	return 0;
}
