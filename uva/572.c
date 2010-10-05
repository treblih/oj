/*
 * =====================================================================================
 *
 *       Filename:  572.c
 *
 *    Description:  Oil Deposits
 *    		    flood fill & bfs
 *
 *        Created:  04.10.10
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

#define	SIZE		128

static int deposits, ys, xs;
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
		if (grid[y][x] != '@'  || 
		    visit[y][x]        ||
		    y == -1 || x == -1 ||
		    y == ys || x == xs) {
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
	int i, j;
	while (scanf("%d%d", &ys, &xs) != EOF && ys) {
		fgets(queue, SIZE, stdin);
		for (i = 0; i < ys; i++) fgets(grid[i], SIZE, stdin);
		for (i = 0; i < ys; i++) {
			for (j = 0; j < xs; j++) {
				if (grid[i][j] == '@' && !visit[i][j]) {
					bfs(i, j);
					deposits++;
				}
			}
		}
		printf("%d\n", deposits);
		deposits = 0;
		/* consecutive in mem */
		memset(visit, 0, ys * SIZE);
	}
	return 0;
}
