/*
 * =====================================================================================
 *
 *       Filename:  3438.c
 *
 *    Description:  sprintf
 *
 *        Created:  28.09.10
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

int main(int argc, const char *argv[])
{
	char ori[1010] = { 0 };
	char res[2020] = { 0 };
	char *ori_p;
	char *res_p;
	int cnt, val;
	int n, i;

	/* while (scanf("%d", &n) != EOF) { */
	scanf("%d", &n);
		for (i = 0; i < n; i++) {
			res_p = res;
			scanf("%s", ori);
			for (ori_p = ori; *ori_p; ) {
				val = *ori_p++;
				cnt = 1;
				while (*ori_p == val) {
					++ori_p;
					++cnt;
				}
				res_p += sprintf(res_p, "%d%d", cnt, val - 0x30);
			}
			cnt = printf("%s\n", res);
			memset(res, 0, cnt);
		}
	/* } */
	return 0;
}
