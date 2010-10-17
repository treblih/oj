/*
 * =====================================================================================
 *
 *       Filename:  119.c
 *
 *    Description:  Greedy Gift Giver
 *    		    simulation
 *
 *        Created:  16.10.10
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

static char name[10][16];
static char given_list[10][16];
static int amount[10];

int name_cmp(char *s)
{
	int i;
	for (i = 0; i < 10; ++i) {
		if (!strncmp(s, name[i], 14)) return i;
	}
	return -1;
}

int main(int argc, const char *argv[])
{
	int np, idx, i, j, amt, num, given, remainder;
	int fst = 1;
	char name_tmp[16];
	while (scanf("%d", &np) != EOF) {
		if (!fst) putchar('\n');
		else fst = 0;
		for (i = 0; i < np; ++i) scanf("%s", name[i]);
		for (i = 0; i < np; ++i) {
			scanf("%s", name_tmp);
			idx = name_cmp(name_tmp);
			scanf("%d%d", &amt, &num);
			if (!num) continue;
			remainder = amt % num;
			given = amt / num;
			amount[idx] += remainder ? -(amt - remainder) : -amt;
			for (j = 0; j < num; ++j) {
				scanf("%s", given_list[j]);
				amount[name_cmp(given_list[j])] += given;
			}

		}
		/* load done, print */
		for (i = 0; i < np; ++i) {
			printf("%s %d\n", name[i], amount[i]);
		}
		memset(amount, 0, 4 * np);
	}
	return 0;
}
