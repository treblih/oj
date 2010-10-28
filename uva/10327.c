/*
 * =====================================================================================
 *
 *       Filename:  10327.c
 *
 *    Description:  Flip Sort 
 *    		    merge sort
 *
 *        Created:  28.10.10
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
#define	SIZE	1024
#define	FORI(i, val, cond)	for ((i) = (val); (cond); ++(i))	
#define	FORIZ(i, cond)		FORI((i), 0, (cond))
#define	FORD(i, val, cond)	for ((i) = (val); (cond); --(i))
#define	FORDZ(i, val)		FORD((i), (val), i >= 0)
#define	MAX(a, b) 	({__typeof__(a) ta=(a); __typeof__(b) tb=(b); ta>tb?ta:tb;})
#define	MIN(a, b)	({__typeof__(a) ta=(a); __typeof__(b) tb=(b); ta<tb?ta:tb;})
#define	SWAP(a, b)	({__typeof__(a) tmp; tmp=(a); (a)=(b); (b)=tmp;})
#define	ZERO(a)		memset((a), 0, sizeof(a))
#ifdef DB
	#define getchar()		getc(fp)
	#define	scanf(...)		fscanf(fp, __VA_ARGS__)
	#undef	stdin
	#define stdin			fp
#endif
static FILE *fp;
static int list[SIZE];
static int a[SIZE>>1];
static int b[SIZE>>1];

int merge(int fst, int mid, int last)
{
	int i, j, k, l, r, cnt = 0;
	/* copy to auxiliary array */
	l = mid - fst + 1;
	FORIZ(i, i < l) a[i] = list[i+fst];
	r = last - mid;
	FORIZ(i, i < r) b[i] = list[i+mid+1];
	/* merge a/b to origin */
	for (i = 0, j = 0, k = fst; i < l && j < r; ) {
		if (a[i] <= b[j]) list[k++] = a[i++];
		else {
			list[k++] = b[j++];
			cnt += l - i;
		}
	}
	while (i < l) list[k++] = a[i++];
	while (j < r) list[k++] = b[j++];
	return cnt;
}

int merge_sort(int fst, int last)
{
	if (fst >= last) return 0;
	int cnt = 0;
	int mid = (fst + last) >> 1;
	cnt += merge_sort(fst, mid) + merge_sort(mid + 1, last);
	return cnt + merge(fst, mid, last);
}

int main(int argc, const char *argv[])
{
#ifdef DB
	fp = fopen("input", "r");
#endif
	int i, n;
	while (scanf("%d", &n) != EOF) {
		FORIZ(i, i < n) scanf("%d", &list[i]);
		printf("Minimum exchange operations : %d\n", 
			merge_sort(0, n - 1));
	}
	return 0;
}
