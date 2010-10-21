/*
 * =====================================================================================
 *
 *       Filename:  10340.c
 *
 *    Description:  All in All
 *    		    string
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

#define	SIZE	1000000

static char a[SIZE];
static char b[SIZE];

int main(int argc, const char *argv[])
{
	int no, ca, cb;
	char *pa, *pb;
	while (scanf("%s%s", a, b) != EOF) {
		no = 0;
		pa = a;
		pb = b;
		while ((ca = *pa)) {
			if (!(cb = *pb)) {no = 1; break;}
			if (ca == cb) ++pa;
			++pb;
		}
		if (no) puts("No");
		else puts("Yes");
	}
	return 0;
}
