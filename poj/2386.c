/*
 * =====================================================================================
 *
 *       Filename:  2386.c
 *
 *    Description:  Oil Deposits
 *    		    flood fill & bfs
 *
 *        Created:  04.10.10
 *       Revision:  
 *       Compiler:  GCC 4.4
 *
 *         Author:  Yang Zhang, treblih.divadWgmail.com
 *        Company:  
 *
 * =====================================================================================
 */

#include <stdio.h>
#include <string.h>

#define	SIZE		128

static int deposits;
static char grid[SIZE][SIZE];
static char visit[SIZE][SIZE];
static char queue[SIZE * SIZE];

void bfs(int y, int x)
{
	char *front = queue;
	char *rear = queue;
	*rear++ = y;
	*rear++ = x;
	while (front != rear) {
		y = *front++;
		x = *front++;
		if (grid[y][x] != 'W' || visit[y][x]) {
			continue;
		} else {
			visit[y][x] = 1;
		}
		/* up */
		*rear++ = y - 1;
		*rear++ = x - 1;
		*rear++ = y - 1;
		*rear++ = x;
		*rear++ = y - 1;
		*rear++ = x + 1;
		/* mid */
		*rear++ = y;
		*rear++ = x - 1;
		*rear++ = y;
		*rear++ = x + 1;
		/* down */
		*rear++ = y + 1;
		*rear++ = x - 1;
		*rear++ = y + 1;
		*rear++ = x;
		*rear++ = y + 1;
		*rear++ = x + 1;
	}
}

int main(int argc, const char *argv[])
{
	int y, x, i, j;
	/* left & top sides, whole */
	for (i = 0; i < SIZE; i++) grid[0][i] = '.';
	for (i = 1; i < SIZE; i++) grid[i][0] = '.';
	scanf("%d%d", &y, &x);
		/* fgets(queue, SIZE, stdin); */
	getchar();
	for (i = 1; i <= y; i++) {
		fgets(grid[i] + 1, SIZE, stdin);
	}
	/* every time we get the boundary, so no memset */
	/* right & bottom sides */
	for (i = 1; i <= x + 1; i++) grid[y + 1][i] = '.';
	for (i = 1; i <= y + 1; i++) grid[i][x + 1] = '.';
	for (i = 1; i <= y; i++) {
		for (j = 1; j <= x; j++) {
			if (grid[i][j] == 'W' && !visit[i][j]) {
				bfs(i, j);
				deposits++;
			}
		}
	}
	printf("%d\n", deposits);
	/* deposits = 0; */
	/* consecutive in mem */
	/* memset(visit, 0, (y + 2) * (x + 2)); */
	/* memset(visit, 0, (y + 2) * SIZE); */
	return 0;
}
