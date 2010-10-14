/*
 * =====================================================================================
 *
 *       Filename:  10550.c
 *
 *    Description:  Combination Lock
 *    		    simulation
 *
 *        Created:  14.10.10
 *       Revision:  
 *       Compiler:  GCC 4.4
 *
 *         Author:  Yang Zhang, treblih.divad@gmail.com
 *        Company:  
 *
 * =====================================================================================
 */

#include <stdio.h>

enum {
	CONT_CLOCK,
	CLOCK
};
#ifdef DB
	#define getchar()		getc(fp)
	#define	scanf(...)		fscanf(fp, __VA_ARGS__)
	#define	ungetc(c, stdin)	ungetc(c, fp)
#endif
static FILE *fp;

int turn(int start, int end, int direct)
{
	int angle, diff = start - end;
	if (diff > 0)
		angle = direct ? diff * 9 : (40 - diff) * 9;
	else
		angle = direct ? (40 - (-diff)) * 9 : (-diff) * 9;
	return angle;
}

int main(int argc, const char *argv[])
{
#ifdef DB
	fp = fopen("input", "r");
#endif
	int pos[4], sum;
	while (scanf("%d%d%d%d", pos, pos + 1, pos + 2, pos + 3) != EOF) {
		if (!pos[0] && !pos[1] && !pos[2] && !pos[3]) break;
		sum = 0;
		sum += turn(pos[0], pos[1], CLOCK);
		sum += turn(pos[1], pos[2], CONT_CLOCK);
		sum += turn(pos[2], pos[3], CLOCK);
		printf("%d\n", sum + 1080);
	}
	return 0;
}
