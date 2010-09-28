/*
 * =====================================================================================
 *
 *       Filename:  3094.c
 *
 *    Description:  no algorithm
 *
 *        Created:  27.09.10
 *       Revision:  
 *       Compiler:  GCC 4.4
 *
 *         Author:  Yang Zhang, treblih.divad@gmail.com
 *        Company:  
 *
 * =====================================================================================
 */

#include <stdio.h>

#define	SIZE	300

int main(int argc, const char *argv[])
{
	int ch, i;
	int total = 0;
	char *p;
	char str[SIZE] = { 0 };

	/* scanf() regards "aaa bbb" as 2 words */
	/* while (scanf("%[^\n]", str) != EOF && *str != '#') { */
	/* while (fgets(str, SIZE, stdin) && *str != '#') { */
	while (gets(str) && *str != '#') {
		for (i = 1, p = str; (ch = *p) && ch != '\n'; i++, p++) {
			if (ch == ' ') {
				continue;
			}
			/* 0x40, not 0x41 */
			total += i * (ch - 0x40);
		}
		printf("%d\n", total);
		total = 0;
	}
	return 0;
}
