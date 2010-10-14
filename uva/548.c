/*
 * =====================================================================================
 *
 *       Filename:  548.c
 *
 *    Description:  Tree
 *    		    post + in -> least path & recursion
 *
 *    		    all values will be different
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
#include <stdlib.h>
#include <stdint.h>

#define SIZE 10010

#ifdef DB
	#define	scanf(...)		fscanf(fp, __VA_ARGS__)
#endif

static int in[SIZE], post[SIZE];
static int min;
static int leaf;
FILE *fp;

int inorder_root(int in_start, int in_end, int val)
{
	int i;
	for (i = in_start; i < in_end; i++) {
		if (in[i] == val) {
			return i;
		}
	}
	return -1;
}

void path(int in_start, int in_end, int post_start, int post_end, int sum)
{
	int pos;
	int root = post[post_end];

	/* if root is the leftmost one in inorder(no left child namely), 
	 * while inorder doesn't have only one element,
	 * post_start > post_end */
	if (post_start > post_end) return;
	sum += root;
	/* i'm a piece of leaf */
	if (post_start == post_end) {
		if (sum < min) {
			min = sum;
			leaf = root;
		} else if (sum == min) {
			if (root < leaf) {
				leaf = root;
			}
		}
		return ;
	}
	/* find every root in inorder, namely the postorder's last */
	if ((pos = inorder_root(in_start, in_end, post[post_end])) == -1) {
		fprintf(stderr, "the last one in postorder isn't in inorder, "
				"data corruption\n");
		exit(EXIT_FAILURE);
	}
	path(in_start, pos - 1, post_start, post_start + (pos - in_start) -1, sum);
	path(pos + 1, in_end, post_start + (pos - in_start), post_end - 1, sum);
}

int main()
{
	int i;
	int n = 0;
	int sum = 0;
	/* %c only set the lowest 1 byte, must set to 0 */
	int ch = 0;
#ifdef 	DB
	fp = fopen("input.txt", "r");
#endif

	/* no direct way to determin how long the tree is */
	while (scanf("%d%c", &in[n++], &ch) != EOF) {
		if (ch != '\n') {
			continue;
		}
		/* now we have */
		for (i = 0; i < n; i++) {
			scanf("%d", &post[i]);
		}
		min = leaf = INT32_MAX;
		path(0, n - 1, 0, n - 1, sum);
		printf("%d\n", leaf);
		n = sum = 0;
	}
	return 0;
}
