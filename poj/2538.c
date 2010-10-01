/*
 * =====================================================================================
 *
 *       Filename:  2538.c
 *
 *    Description:  WERTYU
 *
 *        Created:  02.10.10
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
	int ch, i;
	/* input will not include ` Q Z A */
	char *s = "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";

	while ((ch = getchar()) != EOF) {
		for (i = 0; s[i] && s[i] != ch; i++) ;

		/* namely, ch found in the string */
		if (s[i]) {
			putchar(s[i - 1]);
		} else {
			putchar(ch);
		}
	}
	return 0;
}
