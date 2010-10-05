/*
 * =====================================================================================
 *
 *       Filename:  260.c
 *
 *    Description:  
 *    		    dfs & recursion
 *
 *        Created:  05.10.10
 *       Revision:  
 *       Compiler:  GCC 4.4
 *
 *         Author:  Yang Zhang, treblih.divad@gmail.com
 *        Company:  
 *
 * =====================================================================================
 */

/*-----------------------------------------------------------------------------
 *  oo 
 *  ooo
 *   oo	 to black, deal with down  & down-right
 *       to white, deal with right & down-right
 *-----------------------------------------------------------------------------*/

#include <stdio.h>
#include <string.h>

#define	SIZE		256
#define	ADJACENT	6

static int n;
static int win;
static char tmp[SIZE];
static char graph[SIZE][SIZE];
static char visit[SIZE][SIZE];
static int dy[ADJACENT] = {-1, 0, -1, 1, 0, 1};
static int dx[ADJACENT] = {-1, -1, 0, 0, 1, 1};

enum {
	FAIL,
	WIN
};

int dfs(int y, int x)
{
	/* graph[y][x] must == 'b' */
	/* if (graph[y][x] != 'b') return FAIL; */
	/* now 0 <= x&y < n */
	/* get to the last row */
	if (y == n - 1) {
		win = WIN;
		return WIN;
	}
	visit[y][x] = 1;
	int i;
	for (i = 0; i < ADJACENT; i++) {
		int y_adj = y + dy[i], x_adj = x + dx[i];
		if (visit[y_adj][x_adj]        ||
		    graph[y_adj][x_adj] != 'b' ||
		    y_adj == -1 || x_adj == -1 ||
		    y_adj == n  || x_adj == n) {
			continue;
		}
		if (dfs(y_adj, x_adj)) return WIN;
	}
	return FAIL;
}

int main(int argc, const char *argv[])
{
	int i;
	int cases = 0;
	while (scanf("%d", &n) != EOF && n) {
		++cases;
		/* getchar(); */
		fgets(tmp, SIZE, stdin);
		for (i = 0; i < n; i++) {
			fgets(graph[i], SIZE, stdin);
		}
		/* black(search the first line) mainly */
		for (i = 0; i < n; i++) {
			if (*((char *)graph + i) == 'b') {
				if (dfs(0, i)) {
					break;
				}
			} else {
				continue;
			}
		}
		printf("%d %c\n", cases, win ? 'B' : 'W');
		memset(visit, 0, SIZE * SIZE);
		n = win = 0;
	}
	return 0;
}
