/*
 * =====================================================================================
 *
 *       Filename:  1519.c
 *
 *    Description:  string
 *
 *        Created:  28.09.10
 *       Revision:  
 *       Compiler:  GCC 4.4
 *
 *         Author:  Yang Zhang, treblih.divad@gmail.com
 *        Company:  
 *
 * =====================================================================================
 */

#include <stdio.h>

int main(int argc, const char *argv[])
{
	int ch, total;
	char *p;
	char in[1024] = { 0 };
	char acc[1024] = { 0 };

	while (scanf("%s", in) != EOF && *in != '0') {
		/* scanf filters '\n' */
		for (p = in, total = 0; ch = *p; p++) {
			total += (ch - 0x30);
		}

		/* make '\n' as a sentinel, no need to memset(acc, 0, cnt) every time */
		sprintf(acc, "%d\n", total);
again:
		for (p = acc, total = 0; (ch = *p) != '\n'; p++) {
			total += (ch - 0x30);
		}
		if (total > 9) {
			sprintf(acc, "%d\n", total);
			goto again;
		}
		printf("%d\n", total);
	}
	return 0;
}
