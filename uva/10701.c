/*
 * =====================================================================================
 *
 *       Filename:  10701.c
 *
 *    Description:  Pre, in and post
 *    		    pre + in -> post & recursion
 *
 *        Created:  13.10.10
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

/* they say 52 is the sky */
#define	SIZE	64

void prein_post(int len, char *pre, char *in, char *post)
{
	int left_len = strchr(in, pre[0]) - in;
	/* left child */
	if (left_len > 0) prein_post(left_len, pre + 1, in, post);
	/* left_len + root + right_len = len */
	int right_len = len - 1 - left_len;
	if (right_len > 0) {
		prein_post(right_len, 
			   pre + 1 + left_len, 
			   in  + 1 + left_len, 
			   post    + left_len);
	}
	post[len - 1] = pre[0];
}

int main(int argc, const char *argv[])
{
	int len, cases;
	char pre[SIZE];
	char in[SIZE];
	char post[SIZE];
	scanf("%d", &cases);
	while (cases--) {
		scanf("%d%s%s", &len, pre, in);
		prein_post(len, pre, in, post);
		post[len] = '\0';
		printf("%s\n", post);
	}
	return 0;
}
