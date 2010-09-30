/*
 * =====================================================================================
 *
 *       Filename:  3117.c
 *
 *    Description:  
 *
 *        Created:  30.09.10
 *       Revision:  
 *       Compiler:  GCC 4.4
 *
 *         Author:  Yang Zhang, treblih.divad@gmail.com
 *        Company:  
 *
 * =====================================================================================
 */

#include <stdio.h>

static char name[16];

int main(int argc, const char *argv[])
{
	int i;
	int team, match;
	int score;
	int score_total;

	while (scanf("%d%d", &team, &match) != EOF && team != 0) {
		score_total = 0;
		for (i = 0; i < team; i++) {
			scanf("%s%d", name, &score);
			score_total += score;
		}
		printf("%d\n", match * 3 - score_total);
	}
	return 0;
}
