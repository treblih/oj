/*
 * =====================================================================================
 *
 *       Filename:  494.c
 *
 *    Description:  Kindergarten Counting Game
 *		    string
 *        Created:  08.10.10
 *       Revision:  
 *       Compiler:  GCC 4.4
 *
 *         Author:  Yang Zhang, treblih.divad@gmail.com
 *        Company:  
 *
 * =====================================================================================
 */

#include <stdio.h>
#include <ctype.h>

#define	SIZE		256

static char tmp[SIZE];

int main(int argc, const char *argv[])
{
	int flag, cnt, ch;
	char *p;
	while (fgets(tmp, SIZE, stdin) != NULL) {
		flag = cnt = 0;
		p = tmp;
		while ((ch = *p++) != '\n') {
			if (isalpha(ch) && !flag) {cnt++; flag = 1;}
			if (!isalpha(ch) && flag) flag = 0;
		}
		printf("%d\n", cnt);
	}
	return 0;
}
