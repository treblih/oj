/*
 * =====================================================================================
 *
 *       Filename:  352.c
 *
 *    Description:  The Seasonal War
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
#include <stdbool.h>

#define	SIZE		64

static int eagles, ys, xs;
static char grid[SIZE][SIZE];
static _Bool visit[SIZE][SIZE];
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
		if (grid[y][x] != '1'  || 
		    visit[y][x]        ||
		    y == -1 || x == -1 ||
		    y == ys || x == xs) {
			continue;
		} else {
			visit[y][x] = true;
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
	int cases = 0;
	while (scanf("%d", &ys) != EOF) {
		fgets(queue, SIZE, stdin);
		for (i = 0; i < ys; i++) fgets(grid[i], SIZE, stdin);
		xs = strlen(grid[0]);
		for (i = 0; i < ys; i++) {
			for (j = 0; j < xs; j++) {
				if (grid[i][j] == '1' && !visit[i][j]) {
					bfs(i, j);
					eagles++;
				}
			}
		}
		++cases;
		printf("Image number %d contains %d war eagles.\n", 
			cases, eagles);
		eagles = 0;
		/* consecutive in mem */
		memset(visit, false, ys * SIZE);
	}
	return 0;
}
