/*
 * =====================================================================================
 *
 *       Filename:  1504.c
 *
 *    Description:  Adding Reversed Numbers
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

#define	LEN	64

int main(int argc, const char *argv[])
{
	int n, i, j, k, l;
	int add;
	int row;
	int cf = 0;
	char dec1[LEN], dec2[LEN], res[LEN];

	while (scanf("%d", &n) != EOF) {
		for (row = 0; row < n; row++) {
			scanf("%s%s", dec1, dec2);
			for (i = 0; dec1[i] && dec2[i]; i++) {
				add = dec1[i] - 0x30 + dec2[i] - 0x30 + cf;
				if (add > 9) {
					res[i] = add - 10 + 0x30;
					cf = 1;
				} else {
					res[i] = add + 0x30;
					cf = 0;
				}
			}
			j = i;
			for ( ; dec1[j]; j++) {
				add = dec1[j] - 0x30 + cf;
				if (add > 9) {
					res[j] = add - 10 + 0x30;
					cf = 1;
				} else {
					res[j] = add + 0x30;
					cf = 0;
				}
			}
			k = i;
			for ( ; dec2[k]; k++) {
				add = dec2[k] - 0x30 + cf;
				if (add > 9) {
					res[k] = add - 10 + 0x30;
					cf = 1;
				} else {
					res[k] = add + 0x30;
					cf = 0;
				}
			}
			l = (k > j ? k : j) - 1;
			/* print out reversely */
			while (res[l] == 0x30) {
				--l;
			}
			for (k = 0; k <= l; k++) {
				putchar(res[k]);
			}
			if (cf) {
				putchar('1');
			}
			putchar('\n');
		}
	}
	return 0;
}
