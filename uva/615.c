/*
 * =====================================================================================
 *
 *       Filename:  615.c
 *
 *    Description:  Is It A Tree?
 *    		    directional graph & dfs
 *
 *        Created:  15.10.10
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

#define	SIZE	1024
#ifdef DB
	#define getchar()		getc(fp)
	#define	scanf(...)		fscanf(fp, __VA_ARGS__)
	#define	ungetc(c, stdin)	ungetc(c, fp)
#endif
static FILE *fp;

static int max = -1, cnt;
static char roots[SIZE];
static char graph[SIZE][SIZE];
static char visit[SIZE];

int dfs(int start)
{
	int i;
	if (visit[start]) return 1;
	else visit[start] = 1;
	++cnt;
	for (i = 0; i <= max; ++i) {
		if (graph[start][i] > 1) return 1;
		else if (graph[start][i] == 1) {
				if (dfs(i)) return 1;
		}
	}
	return 0;
}

int main(int argc, const char *argv[])
{
#ifdef DB
	fp = fopen("input", "r");
#endif
	int a, b, i, root;
	int cases = 0;
	int not = 0;
	int edges = 0;
	int vertices = 0;
	while (scanf("%d%d", &a, &b) != EOF) {
		/* if (a < 0) { */
		if (a < 0 && b < 0) break;
		else if (!a && !b) goto load_done;
		else {
			if (max < a) max = a;
			if (max < b) max = b;
			if (!roots[a]) roots[a] = 1;
			if (roots[b] == -1) not = 1;
			else roots[b] = -1;
			if (!visit[a]) {
				visit[a] = 1;
				++vertices;
			}
			if (!visit[b]) {
				visit[b] = 1;
				++vertices;
			}
			++graph[a][b];
			++edges;
			continue;
		}
load_done:
		++cases;
		if (!vertices && !edges) goto is;
		if (vertices != edges + 1) goto not;
		for (i = 0, root = -1; i <= max; ++i) {
			if (roots[i] == 1) {
				if (root > -1) {
					goto not;
				} else root = i;
			}
		}
		/* assembly style */
		/* max >= 0   -> at least 1 node 
		 * root == -1 -> cycle */
		if (root == -1 && max >= 0) goto not;
		memset(visit, 0, max + 1);
		if (dfs(root)) goto not;
		if (vertices != cnt) goto not;
is:
		printf("Case %d is a tree.\n", cases);
		goto reset;
not:
		printf("Case %d is not a tree.\n", cases);
reset:
		memset(roots, 0, max + 1);
		memset(visit, 0, max + 1);
		memset(graph, 0, sizeof(graph));
		max = -1;
		vertices = edges = not = cnt = 0;
	}
	
	return 0;
}
