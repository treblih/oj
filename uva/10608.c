/*
 * =====================================================================================
 *
 *       Filename:  10608.c
 *
 *    Description:  Friends
 *    		    union-find set
 *
 *        Created:  26.10.10
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
#define	SIZE	30010
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
static int max;
static int people[SIZE];
static int cnt[SIZE];

void set_union(int g1, int g2, int n)
{
	int cnt1, cnt2, i;
	/* same cnt */
	if (g1 == g2) return;
	cnt1 = cnt[g1];
	cnt2 = cnt[g2];
	/* make sure g1 is the smaller */
	cnt1 >= cnt2 ? 1 : SWAP(g1, g2);
	FORI(i, 1, i <= n) if (people[i] == g2) people[i] = g1;
	max = MAX(max, cnt[g1] += cnt[g2]);
	cnt[g2] = 0;
}

int main(int argc, const char *argv[])
{
#ifdef DB
	fp = fopen("input", "r");
#endif
	int i, cases, a, b, n, rlt, no, g1, g2;
	scanf("%d", &cases);
	while (cases--) {
		no = 0;
		scanf("%d%d", &n, &rlt);
		if (!n) {puts("0"); continue;}
		max = 1;
		FORIZ(i, i < rlt) {
			scanf("%d%d", &a, &b);
			g1 = people[a], g2 = people[b];
			if (g1 && g2) set_union(g1, g2, n);
			else if (!g1 && !g2){
				people[a] = people[b] = ++no;
				if (a == b) cnt[no] = 1;
				else cnt[no] = 2;
				max = MAX(max, cnt[no]);
			/* one empty one filled */
			} else {
				g1 = g1 ? g1 : g2;
				people[a] = people[b] = g1;
				max = MAX(max, cnt[g1] += 1);
			}
		}
		printf("%d\n", max);
		memset(people, 0, (n + 10) << 2);
		memset(cnt, 0, (no + 10) << 2);
	}
	return 0;
}
