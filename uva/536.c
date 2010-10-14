/*
 * =====================================================================================
 *
 *       Filename:  536.c
 *
 *    Description:  Tree Recovery
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

/* they say 26 is the sky */
#define	SIZE	32

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
	int len;
	char pre[SIZE];
	char in[SIZE];
	char post[SIZE];
	while (scanf("%s%s", pre, in) != EOF) {
		len = strlen(pre);
		prein_post(len, pre, in, post);
		post[len] = '\0';
		printf("%s\n", post);
	}
	return 0;
}
