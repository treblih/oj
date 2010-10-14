/*
 * =====================================================================================
 *
 *       Filename:  253.c
 *
 *    Description:  Cube painting
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

#ifdef DB
	#define getchar()		getc(fp)
	#define	scanf(...)		fscanf(fp, __VA_ARGS__)
	#define	ungetc(c, stdin)	ungetc(c, fp)
#endif
static FILE *fp;
void turn_west(char *a)
{
	int tmp;
	tmp = a[1];
	a[1] = a[2];
	a[2] = a[4];
	a[4] = a[3];
	a[3] = tmp;
}

void turn_north(char *a)
{
	int tmp;
	tmp = a[0];
	a[0] = a[1];
	a[1] = a[5];
	a[5] = a[4];
	a[4] = tmp;
}

void turn_clockwise(char *a)
{
	int tmp;
	tmp = a[0];
	a[0] = a[3];
	a[3] = a[5];
	a[5] = a[2];
	a[2] = tmp;
}

int equal(char *a, char *b)
{
	int i;
	for (i = 0; i < 6; ++i) if (*(a + i) != *(b + i)) return 0;
	return 1;
}

int same(char *a, char *b)
{
	int i, j;
	for (i = 0; i < 4; ++i) {
		for (j = 0; j < 4; ++j) {
			turn_west(a);
			if (equal(a, b)) return 1;
		}
		for (j = 0; j < 4; ++j) {
			turn_clockwise(a);
			if (equal(a, b)) return 1;
		}
		turn_north(a);
		if (equal(a, b)) return 1;
	}
	return 0;
}

int main(int argc, const char *argv[])
{
#ifdef DB
	fp = fopen("input", "r");
#endif
	char dice1[16];
	char *dice2 = dice1 + 6;
	while (scanf("%s", dice1) != EOF) {
		if (same(dice1, dice2)) puts("TRUE");
		else puts("FALSE");
	}
	return 0;
}
