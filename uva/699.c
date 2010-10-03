/*
 * =====================================================================================
 *
 *       Filename:  699.c
 *
 *    Description:  The Falling Leaves
 *
 *        Created:  03.10.10
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

/* it says that at most the output contains 80 chars,
 * including the SPACE, but when i set it to 70, WA.. */
#define	WIDTH		80

#ifdef DB
	#define getchar()		getc(fp)
	#define	scanf(...)		fscanf(fp, __VA_ARGS__)
#endif

static int piles[WIDTH];
static FILE *fp;

void traverse(int pos, int num)
{
	int node;
	piles[pos] += num;
	scanf("%d", &node);
	if (node != -1) traverse(pos - 1, node);
	scanf("%d", &node);
	if (node != -1) traverse(pos + 1, node);
}

int main()
{
#ifdef DB
	fp = fopen("input.txt", "r");
#endif
	int root, i, amount;
	int cases = 0;
	while ((scanf("%d", &root)) != EOF && root != -1) {
		/* middle, 80 / 2 */
		traverse(40, root);
		printf("Case %d:\n", ++cases);
		/* this way, no ending ' ', otherwise PE */
		for (i = 0; !piles[i]; i++) ;
		printf("%d", piles[i++]);
		for (; i < WIDTH; i++) {
			if ((amount = piles[i])) {
				putchar(' ');
				printf("%d", amount);
			}
		}
		printf("\n\n");
		memset(piles, 0, sizeof(int) * WIDTH);
	}
	return 0;
}
