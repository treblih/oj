/*
 * =====================================================================================
 *
 *       Filename:  2159.c
 *
 *    Description:  hash / string
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

#define	SIZE	26

int main(int argc, const char *argv[])
{
	int ch, i;
	int hash_a = 0, hash_b = 0;
	int a[SIZE] = { 0 };
	int b[SIZE] = { 0 };

	while ((ch = getchar()) != EOF && ch != '\n')
		++a[ch - 'A'];
	while ((ch = getchar()) != EOF && ch != '\n')
		++b[ch - 'A'];

	for (i = 0; i < SIZE; i++) {
		if (a[i]) {
			hash_a += a[i] * a[i];
		}
		if (b[i]) {
			hash_b += b[i] * b[i];
		}
	}

	if (hash_a == hash_b) {
		puts("YES");
	} else {
		puts("NO");
	}
	return 0;
}
