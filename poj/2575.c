/*
 * =====================================================================================
 *
 *       Filename:  2575.c
 *
 *    Description:  Jolly Jumper
 *
 *        Created:  01.10.10
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
#include <stdlib.h> 

#define	SIZE	3010
#define	TRUE	1
#define	FALSE	0

static int arr[SIZE];
/* bool[0] useless */
static int bool[SIZE];

int main(int argc, const char *argv[])
{
	int n, i;
	int idx;

	while (scanf("%d", &n) != EOF && n) {
		for (i = 0; i < n; i++) {
			scanf("%d", &arr[i]);
		}
		for (i = 0; i < n - 1; i++) {
			idx = abs(arr[i] - arr[i + 1]);
			if (!idx || bool[idx]) {
				printf("Not jolly\n");
				goto end;
			}
			bool[idx] = TRUE;
		}
		/* i from 1 to n-1 */
		for (i = 1; i < n; i++) {
			if (!bool[i]) {
				printf("Not jolly\n");
				goto end;
			}
		}
		printf("Jolly\n");
end:
		/* bool[0] useless */
		memset((char *)bool + 4, FALSE, sizeof(int) * n);
	}
	return 0;
}
