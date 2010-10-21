/*
 * =====================================================================================
 *
 *       Filename:  785.c
 *
 *    Description:  Grid Coloring
 *    		    floodfill
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
#include <ctype.h>

#define	COL	128

static char maze[64][COL];
static int dy[4] = {0, 1, 0, -1};
static int dx[4] = {1, 0, -1, 0};
static struct mark {
	int y, x;
	int mark;
} mark[64];
#ifdef DB
	#define getchar()		getc(fp)
	#define	scanf(...)		fscanf(fp, __VA_ARGS__)
	#define	ungetc(c, stdin)	ungetc(c, fp)
	#define	fgets(p, COL, stdin)	fgets(p, COL, fp)
#endif
static FILE *fp;

void floodfill(int y, int x, int ch)
{
	int ys, xs, i;
	for (i = 0; i < 4; ++i) {
		ys = y + dy[i];
		xs = x + dx[i];
		/* for the sake of "no outdoor door", 
		 * namely we are surrounded by at least 1 byte of wall
		 * all expansion are legal */
		if (maze[ys][xs] == ' ') {
			maze[ys][xs] = ch;
			floodfill(ys, xs, ch);
		}
	}
}

int main(int argc, const char *argv[])
{
#ifdef DB
	fp = fopen("input", "r");
#endif
	int row, y, x, i, j, ch, contour, mark_cnt;
	char *p;
	while (row = 0, fgets(maze[row], COL, stdin) != NULL) {
		/* row, excluding the line "___________" */
		while (p = maze[++row], fgets(p, COL, stdin), *p != '_') ;
		for (i = 0; i < row; ++i) {
			for (j = 0; (ch = maze[i][j]) != '\n'; ++j) {
				if (ch != ' ') {contour = ch; goto find_marks;}
			}
		}
find_marks:
		for (i = 0, mark_cnt = 0; i < row - 1; ++i) {
			for (j = 0; (ch = maze[i][j]) != '\n'; ++j) {
				if (ch != ' ' && ch != contour) {
					mark[mark_cnt].y = i;
					mark[mark_cnt].x = j;
					mark[mark_cnt++].mark = ch;
				}
			}
		}
		for (i = 0; i < mark_cnt; ++i) {
			y = mark[i].y;
			x = mark[i].x;
			floodfill(y, x, mark[i].mark);
		}
		/* paint done */
		/* fgets ate the '\n', %s\n */
		for (i = 0; i <= row; ++i) printf("%s", maze[i]);
	}
	return 0;
}
