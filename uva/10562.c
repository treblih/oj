/*
 * =====================================================================================
 *
 *       Filename:  10562.c
 *
 *    Description:  Undraw the Trees
 *    		    dfs & recursion
 *
 *    		    could be multiple trees in one shape...
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

#ifdef DB
	#define	scanf(...)		fscanf(fp, __VA_ARGS__)
#endif

#define	SIZE		256

static FILE *fp;
static char output[2 * SIZE];
static char shape[SIZE][SIZE];
static char *pos;

static struct dash {
	char *start;
	char *end;
} dash;

void get_dash_ends(char *s)
{
	char *s_bak = s;
	/* x--, from the spot */
	while (*s_bak-- == '-') ;
	dash.start = s_bak + 2;	/* not 1 */
	/* --x, from one byte right of the spot */
	while (*++s == '-') ;
	dash.end = s - 1;
}

char *find_label(char *s)
{
	int ch;
	do {
		if ((ch = *s++) == '\n') return NULL;
	} while (ch == ' ' || ch == '#' ||
		 ch == '|' || ch == '-');
	/* s has gone over */
	return s - 1;
}

void dfs(char *label)
{
	char *child;
	char *end;

	/* arg given by find_label() */
	/* if (!label) return ; */
	*pos++ = *label;
	*pos++ = '(';
	if (*(label + SIZE) == '|') {
		get_dash_ends(label + SIZE + SIZE);
		/* one line after dash line */
		end = dash.end + SIZE;
		for (child = dash.start + SIZE; 
		    (child = find_label(child)) <= end && child; ++child) {
			dfs(child);
		}
	}
	*pos++ = ')';
}

int main(int argc, const char *argv[])
{
#ifdef DB
	fp = fopen("input", "r");
#endif
	int cases;
	int y;
	char *label, *end;

	scanf("%d", &cases);
	while (cases--) {
		y = 0;
		while (1) {
			/* until either a terminating newline or EOF, 
			 * which it replaces with '\0' */
#ifdef DB
			fgets(shape[y], SIZE, fp);
#else
			fgets(shape[y], SIZE, stdin);
#endif
			if (*shape[y] == '\n') continue;
			if (*shape[y] == '#') break;
			++y;
		}
		pos = output;
		*pos++ = '(';
		end = (char *)shape + SIZE;
		/* < not <= */
		for (label = (char *)shape; 
		    (label = find_label(label)) < end && label; ++label) {
			dfs(label);
		}
		*pos++ = ')';
		*pos = '\0';
		printf("%s\n", output);
		if (cases) memset(shape, 0, y * SIZE);
	}
	return 0;
}
