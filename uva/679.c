/*
 * =====================================================================================
 *
 *       Filename:  679.c
 *
 *    Description:  Dropping Balls
 *    		    iterate
 *
 *        Created:  20.10.10
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

int main(int argc, const char *argv[])
{
#ifdef DB
	fp = fopen("input", "r");
#endif
	int cases, depth, idx, num, i;
	scanf("%d", &cases);
	while (cases--) {
		scanf("%d%d", &depth, &idx);
		for (i = 1, num = 1; i < depth; ++i) {
			if (idx & 1) {
				idx = (idx + 1) >> 1;
				num <<= 1;
			} else {
				idx >>= 1;
				num = (num << 1) + 1;
			}
		}
		printf("%d\n", num);
	}
	return 0;
}
