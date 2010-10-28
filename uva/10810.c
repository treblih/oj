/*
 * =====================================================================================
 *
 *       Filename:  10810.c
 *
 *    Description:  Ultra-Quicksort
 *    		    min-heap sort
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
#define	SIZE	500010
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
static long long list[SIZE];
static long long a[SIZE>>1];
static long long b[SIZE>>1];

long long merge(int fst, int mid, int last)
{
	int i, j, k, l, r;
	long long cnt = 0;
	/* copy to auxiliary array */
	l = mid - fst + 1;
	FORIZ(i, i < l) a[i] = list[i+fst];
	r = last - mid;
	FORIZ(i, i < r) b[i] = list[i+mid+1];
	/* merge a/b to origin */
	for (i = 0, j = 0, k = fst; i < l && j < r; ) {
		/* regard a[] as reference 
		 * it seems that insert b[] into a[] */
		if (a[i] <= b[j]) list[k++] = a[i++];
		else {
			list[k++] = b[j++];
			/* how many elems left ==
			 * how many inversions we need */
			cnt += l - i;
		}
	}
	while (i < l) list[k++] = a[i++];
	while (j < r) list[k++] = b[j++];
	return cnt;
}

long long merge_sort(int fst, int last)
{
	if (fst >= last) return 0;
	int mid = (fst + last) >> 1;
	long long cnt = 0;
	cnt += merge_sort(fst, mid) + merge_sort(mid + 1, last);
	return cnt + merge(fst, mid, last);
}

int main(int argc, const char *argv[])
{
#ifdef DB
	fp = fopen("input", "r");
#endif
	int i, n;
	while (scanf("%d", &n), n) {
		FORIZ(i, i < n) scanf("%lld", &list[i]);
		printf("%lld\n", merge_sort(0, n - 1));
	}
	return 0;
}


#if 0
int heapfy_down(int list[], int fst, int last)
{
	int i, cnt = 0;
	for (i = fst << 1; i <= last; fst = i, i = fst << 1) {
		/* j is the larger child 
		 * 'j<last' does make sure if it has only 1 child */
		if (i < last && list[i] < list[i+1]) ++i;
		if (list[fst] >= list[i]) break;
		SWAP(list[fst], list[i]);
		++cnt;
	}
	return cnt;
}

int heap_sort(int list[], int n)
{
	int i, cnt = 0;
	/* heapfying from the level whose height is 1 */
	FORD(i, n >> 1, i >= 1) cnt += heapfy_down(list, i, n);
	while (n > 1) {
		SWAP(list[1], list[n]);
		++cnt;
		cnt += heapfy_down(list, 0, --n);
	}
	return cnt;
}
#endif
