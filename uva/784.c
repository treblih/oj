/*
 * =====================================================================================
 *
 *       Filename:  784.c
 *
 *    Description:  Maze Exploration
 *    		    floodfill & dfs
 *
 *        Created:  21.10.10
 *       Revision:  
 *       Compiler:  GCC 4.4
 *
 *         Author:  Yang Zhang, treblih.divad@gmail.com
 *        Company:  
 *
 * =====================================================================================
 */

#include <stdio.h>

#define	COL	84

static int dy[4] = {0, 1, 0, -1};
static int dx[4] = {1, 0, -1, 0};
static char maze[32][COL];
static int row;
#ifdef DB
	#define getchar()		getc(fp)
	#define	scanf(...)		fscanf(fp, __VA_ARGS__)
	#define	ungetc(c, stdin)	ungetc(c, fp)
	#define	fgets(p, COL, stdin)	fgets(p, COL, fp)
#endif
static FILE *fp;

void floodfill(int y, int x)
{
	int ys, xs, i;
	for (i = 0; i < 4; ++i) {
		ys = y + dy[i];
		xs = x + dx[i];
		/* for the sake of "no outdoor door", 
		 * namely we are surrounded by at least 1 byte of wall
		 * all expansion are legal */
		if (maze[ys][xs] == ' ') {
			maze[ys][xs] = '#';
			floodfill(ys, xs);
		}
	}
}

int main(int argc, const char *argv[])
{
#ifdef DB
	fp = fopen("input", "r");
#endif
	int cases, y, x, i, ch;
	char *p;
	scanf("%d", &cases);
	while ((ch = getchar()) != '\n') ;
	while (cases--) {
		/* row, excluding the line "___________" */
		y = x = 0;
		while (p = maze[row], fgets(p, COL, stdin), *p != '_') {
			/* start point won't be (0,0), 'cause it's wall */
			if (!y) {
				for ( ; (ch = *p) != '\n'; ++p) {
					if (ch == '*') {
						y = row; 
						x = p - maze[row];
						break;
					}
				}
			}
			++row;
		}
		/* load done */
		maze[y][x] = '#';
		floodfill(y, x);
		/* paint done */
		/* fgets ate the '\n', %s\n */
		for (i = 0; i <= row; ++i) printf("%s", maze[i]);
		row = 0;
	}
	return 0;
}
