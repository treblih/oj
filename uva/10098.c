/*
 * =====================================================================================
 *
 *       Filename:  10098.c
 *
 *    Description:  Generating Fast, Sorted Permutation
 *    		    backtrack
 *    		    list & candidates are always hold the unique chars, not the occurence
 *
 *        Created:  11.10.10
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

/* cnt is the string length we've got, 
 * while cnt_unique is the number of unique chars 
 * for "aabbc", cnt = 5, cnt_unique = 3 */
static int cnt, cnt_unique;
/* alignment */
static char str[SIZE];
static char list[64];
/* 012...9ABC...XYZabc...xyz */
static char alpha[64];

void construct_solutions(int dms, char *candidates, int *n)
{
	int i;
	/* sizeof(list) == cnt_unique */
	for (i = 0, *n = 0; i < cnt_unique; ++i) {
		if (alpha[list[i]]) {
			/* won't regard aa as 2 diff chars,
			 * because candidates are the unique holder */
			candidates[(*n)++] = list[i];
		}
	}
}

void backtrack(int dms)
{
	int i, ncandidate, ch, tmp;
	/* SIZE is enough */
	char candidates[SIZE];
	if (dms == cnt) {
		str[cnt] = '\0';
		printf("%s\n", str);
	} else {
		construct_solutions(dms, candidates, &ncandidate);
		for (i = 0; i < ncandidate; ++i) {
			/* see in construct_solutions() */
			tmp = candidates[i];
			if (tmp < 10) ch = tmp + 0x30;
			else if (tmp >= 36) ch = tmp - 36 + 'a';
			else ch = tmp - 10 + 'A';
			str[dms] = ch;
			--alpha[tmp];		/* set */
			backtrack(dms + 1);
			++alpha[tmp];		/* unset */
		}
	}
}

int main(int argc, const char *argv[])
{
#ifdef DB
	fp = fopen("input", "r");
#endif
	int cases, i, ch;
	char *p;
	scanf("%d", &cases);
	while (cases--) {
		scanf("%s", str);
		/* load */
		for (cnt = 0, p = str; (ch = *p); ++p) {
			/* num, 0-9 */
			if (ch < 'A') {
				++alpha[ch - 0x30];
			/* lower, 36-61 */
			}
			else if (ch >= 'a') {
				++alpha[ch - 'a' + 36];
			}
			/* upper, 10-35 */
			else {
				++alpha[ch - 'A' + 10];
			}
			++cnt;
		}
		/* sizeof(list) == cnt_unique */
		for (cnt_unique = 0, i = 0; i < 62; ++i) {
			if(alpha[i]) list[cnt_unique++] = i;
		}
		backtrack(0);
		memset(alpha, 0, 64);
		putchar('\n');
	}
	return 0;
}
