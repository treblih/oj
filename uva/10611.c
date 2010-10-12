/*
 * =====================================================================================
 *
 *       Filename:  10611.c
 *
 *    Description:  The Playboy Chimp
 *    		    bsearch
 *
 *        Created:  10.10.10
 *       Revision:  
 *       Compiler:  GCC 4.4
 *
 *         Author:  Yang Zhang, treblih.divad@gmail.com
 *        Company:  
 *
 * =====================================================================================
 */

#include <stdio.h>

#define	SIZE		50010
#ifdef DB
	#define getchar()		getc(fp)
	#define	scanf(...)		fscanf(fp, __VA_ARGS__)
	#define	ungetc(c, stdin)	ungetc(c, fp)
#endif

static FILE *fp;
static int girls[SIZE];

int left(int val, int pos)
{
	int tmp;
	while ((tmp = girls[--pos]) == val) ;
	return tmp;
}

int right(int val, int pos)
{
	int tmp;
	while ((tmp = girls[++pos]) == val) ;
	return tmp;
}

int main(int argc, const char *argv[])
{
#ifdef DB
	fp = fopen("input", "r");
#endif
	int ngirl, nboy, boy, low, mid, high, last, fst;
	int i, tmp;
	scanf("%d", &ngirl);
	for (i = 0; i < ngirl; i++) scanf("%d", &girls[i]);
	scanf("%d", &nboy);
	for (i = 0; i < nboy; i++) {
next:
		scanf("%d", &boy);
		/* special cases, out of all girls */
		last = girls[ngirl - 1];
		fst = girls[0];
		if (boy > last) {printf("%d X\n", last); continue;}
		else if (boy == last) {
			/* 1 2 3 3 3 <-> 3 */
			printf("%d X\n", left(boy, ngirl - 1));
			continue;
		} 
		else if (boy < fst) {printf("X %d\n", fst); continue;}
		else if (boy == fst) {
			/* 1 <-> 1 1 1 2 3 */
			printf("X %d\n", right(boy, 0));
			continue;
		}
		/* normal cases, among girls */
		low = 0, high = ngirl - 1;
		while (low <= high) {
			mid = (low + high) >> 1;
			tmp = girls[mid];
			if (tmp < boy) 	  low = mid + 1;
			else if (tmp > boy) high = mid - 1;
			else {
				printf("%d %d\n", left(tmp, mid), right(tmp, mid));
				i++;
				goto next;
			}
		}
		if (tmp > boy)  printf("%d %d\n", girls[mid - 1], tmp);
		else 		printf("%d %d\n", tmp, girls[mid + 1]);
	}
	return 0;
}
