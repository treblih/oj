/*
 * =====================================================================================
 *
 *       Filename:  11790.c
 *
 *    Description:  E-Murcia's Skyline
 *    		    linear dp & lis
 *
 *        Created:  24.10.10
 *       Revision:  
 *       Compiler:  GCC 4.4
 *
 *         Author:  Yang Zhang, treblih.divad@gmail.com
 *        Company:  
 *
 * =====================================================================================
 */

#include <stdio.h>
#include <stdint.h>
#define	SIZE	10000
#define	FORI(i, val, cond)	for ((i) = (val); (cond); ++(i))	
#define	FORIZ(i, cond)		FORI((i), 0, (cond))
#define	FORD(i, val, cond)	for ((i) = (val); (cond); --(i))
#define	FORDZ(i, cond)		FORD((i), 0, (cond))
#define	MAX(a, b)		({__typeof__ (a) ta = (a);\
			  	__typeof__ (b) tb = (b);\
			  	ta > tb ? ta : tb;})
#define	MIN(a, b)		({__typeof__ (a) ta = (a);\
			  	__typeof__ (b) tb = (b);\
			  	ta < tb ? ta : tb;})
#ifdef DB
	#define getchar()		getc(fp)
	#define	scanf(...)		fscanf(fp, __VA_ARGS__)
	#undef	stdin
	#define stdin			fp
#endif
static FILE *fp;
static int imax, dmax;
static int hght[SIZE];
static int len[SIZE];
static struct skyline {
	int hght, len;
} lis[SIZE], lds[SIZE];

int bsearch(int wanted, int high)
{
	int low = 0;
	int mid;
	while (low <= high) {
		mid = (low + high) >> 1;
		if (lis[mid].hght < wanted) low = mid + 1;
		else if (wanted < lis[mid].hght) high = mid - 1;
		else return mid;
	}
	return low;
}

int bsearch_d(int wanted, int high)
{
	int low = 0;
	int mid;
	while (low <= high) {
		mid = (low + high) >> 1;
		if (lis[mid].hght < wanted) high = mid - 1;
		else if (wanted < lis[mid].hght) low = mid + 1;
		else return mid;
	}
	return low;
}

void process(int n)
{
	int i, wanted, p;
	int iidx = 0, didx = 0;
	lis[0].hght = lds[0].hght = hght[0];
	lis[0].len = lds[0].len = len[0];
	FORI(i, 1, i < n) {
		wanted = hght[i];
		/* LIS */
		if (lis[iidx].hght < wanted) {
			lis[++iidx].hght = wanted;
			lis[iidx].len = lis[iidx-1].len + len[i];
			imax = MAX(imax, lis[iidx].len);
		} else {
			p = bsearch(wanted, iidx);
			lis[p].hght = wanted;
			imax = MAX(imax, lis[p].len = lis[p-1].len + len[i]);
		}
		/* LDS */
		if (lds[didx].hght > wanted) {
			lds[++didx].hght = wanted;
			lds[didx].len = lds[didx-1].len + len[i];
			dmax = MAX(dmax, lds[didx].len);
		} else {
			p = bsearch_d(wanted, didx);
			lds[p].hght = wanted;
			dmax = MAX(dmax, lds[p].len = lds[p-1].len + len[i]);
		}
	}
}

int main(int argc, const char *argv[])
{
#ifdef DB
	fp = fopen("input", "r");
#endif
	int i, cases, n, no = 0;
	scanf("%d", &cases);
	while (cases--) {
		scanf("%d", &n);
		FORIZ(i, i < n) scanf("%d", &hght[i]);
		FORIZ(i, i < n) scanf("%d", &len[i]);
		imax = dmax = -INT32_MAX;
		process(n);
		imax >= dmax ?
			printf("Case %d. Increasing (%d). Decreasing (%d).\n",
				++no, imax, dmax) :
			printf("Case %d. Decreasing (%d). Increasing (%d).\n",
				++no, dmax, imax) ;
	}
	return 0;
}
