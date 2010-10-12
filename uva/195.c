/*
 * =====================================================================================
 *
 *       Filename:  195.c
 *
 *    Description:  Anagram
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

#define	SIZE	128

/* cnt is the string length we've got, 
 * while cnt_unique is the number of unique chars 
 * for "aabbc", cnt = 5, cnt_unique = 3 */
static int cnt, cnt_unique;
/* alignment */
static char str[SIZE];
static char list[64];
/* AaBbCc ... XxYyZz */
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
	char candidates[52];
	if (dms == cnt) {
		str[cnt] = '\0';
		printf("%s\n", str);
	} else {
		construct_solutions(dms, candidates, &ncandidate);
		for (i = 0; i < ncandidate; ++i) {
			/* see in construct_solutions() */
			tmp = candidates[i];
			if (tmp & 0x1) {
				ch = ((tmp - 1) >> 1) + 'a';
			} else {
				ch = (tmp >> 1) + 'A';
			}
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
			/* lower, 2n+1 */
			if (ch - 'A' > 26) ++alpha[((ch - 'a') << 1) + 1];
			/* upper, 2n */
			else ++alpha[(ch - 'A') << 1];
			++cnt;
		}
		/* sizeof(list) == cnt_unique */
		for (cnt_unique = 0, i = 0; i < 52; ++i) {
			if(alpha[i]) list[cnt_unique++] = i;
		}
		backtrack(0);
		/* 26 is adequate */
		memset(alpha, 0, 64);
	}
	return 0;
}
