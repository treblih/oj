/*
 * =====================================================================================
 *
 *       Filename:  10252.c
 *
 *    Description:  Common Permutation
 *    		    string
 *
 *        Created:  12.10.10
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
#include <ctype.h>

#define	SIZE	1028

static char str1[SIZE];
static char str2[SIZE];
static char lower[32];

int cmpr(const void *a, const void *b)
{
	return *(char *)a - *(char *)b;
}

int main(int argc, const char *argv[])
{
	char *p;
	int ch, cnt;
	while (fgets(str1, SIZE, stdin) != NULL) {
		fgets(str2, SIZE, stdin);
		for (p = str1; (ch = *p); ++p) {
			if (islower(ch)) ++lower[ch - 'a'];
		}
		for (p = str2, cnt = 0; (ch = *p); ++p) {
			if (islower(ch) && lower[ch - 'a']) {
				--lower[ch - 'a'];
				str1[cnt++] = ch;
			}
		}
		str1[cnt] = '\0';
		qsort(str1, cnt, 1, cmpr);
		printf("%s\n", str1);
		memset(lower, 0, 32);
	}
	return 0;
}
