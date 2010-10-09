/*
 * =====================================================================================
 *
 *       Filename:  488.c
 *
 *    Description:  Triangle Wave
 *
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

int main(int argc, const char *argv[])
{
	int cases, wave, n, a, f, i, j, flag;
	scanf("%d", &cases);
	while (cases--) {
		scanf("%d%d", &a, &f);
		while (f--) {
			for (flag = 1, wave = 0, n = (a << 1) - 1, i = 0; i < n; i++) {
				if (flag) wave++;
				else wave--;
				for (j = 0; j < wave; j++) {
					putchar(wave + 0x30);
				}
				printf("\n");
				if (wave == a) flag = 0;
			}
			if (cases || f) printf("\n");
		}
	}
	return 0;
}
