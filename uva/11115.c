/*
 * =====================================================================================
 *
 *       Filename:  11115.c
 *
 *    Description:  Uncle Jack
 *    		    combinatorics & bignum
 *
 *        Created:  25.10.10
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
#define	FORI(i, val, cond)	for ((i) = (val); (cond); ++(i))	
#define	FORIZ(i, cond)		FORI((i), 0, (cond))
#define	FORD(i, val, cond)	for ((i) = (val); (cond); --(i))
#define	FORDZ(i, val)		FORD((i), (val), i >= 0)
#define	MAX(a, b)		({__typeof__ (a) ta = (a);\
			  	__typeof__ (b) tb = (b);\
			  	ta > tb ? ta : tb;})
#define	MIN(a, b)		({__typeof__ (a) ta = (a);\
			  	__typeof__ (b) tb = (b);\
			  	ta < tb ? ta : tb;})
#ifdef DB
	#define getchar()		getc(fp)
	#define	scanf(...)		fscanf(fp, __VA_ARGS__)
	#undef	stdin
	#define stdin			fp
#endif
static FILE *fp;

/* useless in here */
void square(char *big)
{
	int i, j, len = strlen(big);
	int res, cf = 0, sum;
	char bak[SIZE] = {0};
	FORIZ(i, i < len) {
		FORIZ(j, j < len) {
			res = big[i] * big[j];
			sum = bak[i] + res + cf;
			bak[i] = sum % 10;
			cf = sum / 10;
		}
	}
	strncpy(big, bak, SIZE);
}

/* digits are not ascii, so ZERO is 0, 
 * means end of the string, leading alot of troubles 
 * strcpy doesn't survive */
int bignum_len(char *big, int whole)
{
	int i;
	FORDZ(i, whole - 1) if (big[i]) return i + 1;
	return 0;
}

void multiply(char *nph, char *base)
{
	int i, j, k, n, b, res, cf = 0, sum;
	int len_n = bignum_len(nph, SIZE);
	int len_b = bignum_len(base, SIZE);
	char bak[SIZE] = {0};
	FORIZ(i, i < len_b) {
		b = base[i];
		FORIZ(j, j < len_n) {
			n = nph[j];
			k = i + j;
			res = b * n;
			sum = bak[k] + res + cf;
			bak[k] = sum % 10;
			cf = sum / 10;
		}
/*-----------------------------------------------------------------------------
 *  	999
 *   x	 99
 *   ------
 *     8991
 *    8991	here, k+1 will always occupy the highest digit, 
 *    		so =, no need  +=
 *-----------------------------------------------------------------------------*/
		bak[i+j] = cf;
	}
	/* strncpy */
	memcpy(nph, bak, SIZE);
}

int main(int argc, const char *argv[])
{
#ifdef DB
	fp = fopen("input", "r");
#endif
	int i, cd;
	char nph[SIZE] = {0}, base[SIZE] = {0};
	/* can't use %s, is big-endian */
	while (scanf("%d%d", &i, &cd), i || cd) {
		if (!cd) 	{puts("1"); continue;}
		else if (!i)	{puts("0"); continue;}
		nph[0] = base[0] = i % 10;
		if (i > 9) nph[1] = base[1] = i / 10;
		FORIZ(i, i < cd - 1) multiply(nph, base);
		FORDZ(i, bignum_len(nph, SIZE) - 1) printf("%c", nph[i] + 0x30);
		putchar('\n');
		memset(nph, 0, SIZE);
	}
	return 0;
}
