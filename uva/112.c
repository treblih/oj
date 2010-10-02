/*
 * =====================================================================================
 *
 *       Filename:  112.c
 *
 *    Description:  Tree Summing
 *    		    recursion
 *
 *        Created:  02.10.10
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

enum {
	NO_CHILD,
	FAIL,
	FOUND,
};

static int wanted;
static FILE *fp;

/*-----------------------------------------------------------------------------
 *  ME, ought to deal with
 *  	'(' + num + whether have child + ')'
 *  
 *  when found, can't go out immediately, for the sake of input buffer
 *-----------------------------------------------------------------------------*/
int path(int val)
{
	int c;
	int sign = 1;
	int ret_l, ret_r;
	int found = FAIL;

	while ((c = getchar()) != '(') ;
	while ((c = getchar()) == ' ' || c == '\n') ;
	/* empty */
	if (c == ')') {
		return NO_CHILD;
	} else if (c == '-') {
		sign = -1;
	} else {
		ungetc(c, stdin);
	}
	scanf("%d", &c);
	val += (c * sign);
	
	/* midium, transfer */
	ret_l = path(val);
	ret_r = path(val);
	if (ret_l == FOUND || ret_r == FOUND) {
		found = FOUND;
	/* end of the path, found it myself */
	} else if (ret_l == NO_CHILD && ret_r == NO_CHILD && val == wanted) {
		found = FOUND;
	}
	while ((c = getchar()) != ')') ;
	return found;
}

int main()
{
#ifdef DB
	fp = fopen("input.txt", "r");
#endif
	while (scanf("%d", &wanted) != EOF) {
		if (path(0) == FOUND) {
			printf("yes\n");
		} else {
			printf("no\n");
		}
	}
	return 0;
}
