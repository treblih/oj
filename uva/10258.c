/*
 * =====================================================================================
 *
 *       Filename:  10258.c
 *
 *    Description:  Contest Scoreboard
 *    		    multi-fields qsort
 *
 *        Created:  29.10.10
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
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#define	SIZE	32
#define	TEAM	128
#define	PROB	16
#define	FORI(i, val, cond)	for ((i) = (val); (cond); ++(i))	
#define	FORIZ(i, cond)		FORI((i), 0, (cond))
#define	FORD(i, val, cond)	for ((i) = (val); (cond); --(i))
#define	FORDZ(i, val)		FORD((i), (val), i >= 0)
#define	MAX(a, b) 	({__typeof__(a) _a=(a), _b=(b); _a>_b?_a:_b;})
#define	MIN(a, b)	({__typeof__(a) _a=(a), _b=(b); _a<_b?_a:_b;})
#define	SWAP(a, b)	({__typeof__(a) tmp=(a); (a)=(b); (b)=tmp;})
#define	ZERO(a)		memset((a), 0, sizeof(a));
#ifdef DB
	#define getchar()		getc(fp)
	#define	scanf(...)		fscanf(fp, __VA_ARGS__)
	#undef	stdin
	#define stdin			fp
#endif
static FILE *fp;
static struct team {
	bool prob[PROB];
	int penalty[PROB];
	int solved, time, idx;
} team[TEAM];

int cmpr(const void *a, const void *b)
{
	const struct team *_a = a;
	const struct team *_b = b;
	/* by solved problems */
	if (_a->solved != _b->solved) return _b->solved - _a->solved;
	/* same problems, sort by time cost */
	if (_a->time != _b->time) return _a->time - _b->time;
	/* all the same, no exchange, because 've been sorted by team NO. */
	return 0;
}

int main(int argc, const char *argv[])
{
#ifdef DB
	fp = fopen("input", "r");
#endif
	bool blank;
	char str[SIZE];
	int i, cases, t, prob, time, max, cnt, ch;
	char *p;
	scanf("%d\n", &cases); /* essential '\n' */
	while (cases--) {
		max = 0;
		while (fgets(str, SIZE, stdin) != NULL) {
			blank = true;
			FORI(p, str, (ch = *p)) if (isdigit(ch)) {blank = false; break;}
			if (blank) break;	/* go out to process */
			sscanf(str, "%d%d%d %c", &t, &prob, &time, &ch); /* trick */
			max = MAX(max, t);
			if (!team[t].prob[prob]) {
				team[t].idx = t;
				switch (ch) {
				case 'I':
					team[t].penalty[prob] += 20;
					break;
				case 'C':
					++team[t].solved;
					team[t].prob[prob] = true;
					team[t].time += (team[t].penalty[prob] += time);
					break;
				default:
					break;
				}
			}
		}
		/* load done */
		cnt = 0;
		/* not all teams submit,
		 * group all submitted teams to the front of team[], for QSORT */
		FORI(i, 1, i <= max) 
			if (team[i].idx && i != cnt) 
				memcpy(&team[cnt++], &team[i], sizeof(struct team));
		qsort(team, cnt, sizeof(struct team), cmpr);
		FORIZ(i, i < cnt) printf("%d %d %d\n", 
				         team[i].idx, 
					 team[i].solved,
					 team[i].time);
		if (cases) putchar('\n');
		/* ZERO(team); */
		memset(team, 0, (max + 1) * sizeof(struct team));
	}
	return 0;
}
