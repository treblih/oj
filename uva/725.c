/*
 * =====================================================================================
 *
 *       Filename:  725.c
 *
 *    Description:  Division
 *    		    backtrack & pruning
 *
 *        Created:  21.10.10
 *       Revision:  
 *       Compiler:  GCC 4.4
 *
 *         Author:  Yang Zhang, treblih.divad@gmail.com
 *        Company:  
 *
 * =====================================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifdef DB
	#define getchar()		getc(fp)
	#define	scanf(...)		fscanf(fp, __VA_ARGS__)
	#define	ungetc(c, stdin)	ungetc(c, fp)
#endif
static FILE *fp;

#define	SIZE	16

static bool printed;
static bool used[SIZE];
static char solutions[8];
static int quotient;

bool unique(int num)
{
	bool not_ten_digits = false;
	int i;
	int digit[5];
	for (i = 0; i < 5; ++i) {
		if (used[digit[i] = num % 10]) break;
		num /= 10;
		used[digit[i]] = true;
	}
	/* 2956 / 01478 = 2 */
	if (i != 5) not_ten_digits = true;
	/* for all, need to clear the bits */
	while (i--) used[digit[i]] = false;
	/* 2 situations -- 
	 * num has more than 5 digits;
	 * num has at least one digit reused */
	if (num || not_ten_digits) return false;
	return true;
}

void process_solutions()
{
	/* solutions[5] = '\0'; always be 0 */
	int dividend = atoi(solutions) * quotient;
	if (unique(dividend)) {
		/* 0 won't be the highest bit of dividend */
		printf("%d / %s = %d\n", dividend, solutions, quotient);
		printed = true;
	}
}

void construct_solutions(int dms, int candidates[], int *n)
{
	int i;
	for (i = 0, *n = 0; i < 10; ++i) if (!used[i]) candidates[(*n)++] = i;
}

void backtrack(int dms)
{
	int i, ncandidate, tmp;
	int candidates[10];
	if (dms == 5) process_solutions();
	else {
		construct_solutions(dms, candidates, &ncandidate);
		for (i = 0; i < ncandidate; ++i) {
			tmp = candidates[i];
			/* solutions[] holding the ascii char */
			solutions[dms] = tmp + 0x30;
			used[tmp] = true;
			backtrack(dms + 1);
			used[tmp] = false;
		}
	}
}

int main(int argc, const char *argv[])
{
#ifdef DB
	fp = fopen("input", "r");
#endif
	int fst = 1;
	while (scanf("%d", &quotient), quotient) {
		if (fst) fst = 0;
		else putchar('\n');
		/* in this case, a divisor won't be larger than 9999, so pruning */
		if (quotient > 9) {
			used[0] = true;
			solutions[0] = '0';
			backtrack(1);
		} else backtrack(0);
		if (!printed) printf("There are no solutions for %d.\n", quotient);
		memset(used, false, sizeof(used));
		printed = false;
	}
	return 0;
}
