/*
 * =====================================================================================
 *
 *       Filename:  1488.c
 *
 *    Description:  TEX Quotes
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
	int i, ch;
	int flag = 0;

	while ((ch = getchar()) != EOF) {
		if (ch == '"') {
			printf("%s", flag ? "''" : "``");
			flag = !flag;
		} else {
			putchar(ch);
		}
	}
	return 0;
}
