/*
 * =====================================================================================
 *
 *       Filename:  3650.c
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
#include <string.h>

int main(int argc, const char *argv[])
{
	int ch;
	int cnt;
	char str[128] = { 0 };
	char *p = str;

	while ((ch = getchar()) != EOF && ch != '#') {
		switch (ch) {
		case ' ' :
			p += sprintf(p, "%%20");
			break;
		case '!' :
			p += sprintf(p, "%%21");
			break;
		case '$' :
			p += sprintf(p, "%%24");
			break;
		case '%' :
			p += sprintf(p, "%%25");
			break;
		case '(' :
			p += sprintf(p, "%%28");
			break;
		case ')' :
			p += sprintf(p, "%%29");
			break;
		case '*' :
			p += sprintf(p, "%%2a");
			break;
		case '\n' :
			*p = '\n';
			cnt = printf("%s", str);
			p = str;
			memset(str, 0, cnt);
			break;
		default :
			*p++ = ch;
			break;
		}
	}
	printf("\n");
	return 0;
}
