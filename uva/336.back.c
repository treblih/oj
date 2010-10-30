/*
 * =====================================================================================
 *
 *       Filename:  336.c
 *
 *    Description:  A Node Too Far
 *    		    bin search tree & dfs
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
#include <stdlib.h>
#include <string.h>
#define	SIZE	32
#define	FORI(i, val, cond)	for ((i) = (val); (cond); ++(i))	
#define	FORIZ(i, cond)		FORI((i), 0, (cond))
#define	FORD(i, val, cond)	for ((i) = (val); (cond); --(i))
#define	FORDZ(i, val)		FORD((i), (val), i >= 0)
#define	MAX(a, b) 	({__typeof__(a) ta=(a); __typeof__(b) tb=(b); ta>tb?ta:tb;})
#define	MIN(a, b)	({__typeof__(a) ta=(a); __typeof__(b) tb=(b); ta<tb?ta:tb;})
#define	SWAP(a, b)	({__typeof__(a) tmp; tmp=(a); (a)=(b); (b)=tmp;})
#define	ZERO(a)		memset((a), 0, sizeof(a))
enum {REACH = -1, NO, YES};
#ifdef DB
	#define getchar()		getc(fp)
	#define	scanf(...)		fscanf(fp, __VA_ARGS__)
	#undef	stdin
	#define stdin			fp
#endif
static FILE *fp;
static int total;
static int mat[SIZE][SIZE];
static struct bst {
	int val, idx, nadj;
	struct bst *left, *right;
} bst[SIZE];

#define	node_nadj(idx)	bst[(idx)].nadj
int bst_find(int wanted, int insert)
{
	int val;
	struct bst *child = bst, *parant;
	while (child) {
		parant = child;
		val = child->val;
		if (val == wanted) return child->idx;
		else if (wanted < val) child = child->left;
		else child = child->right;
	}
	if (!insert) return 0;
	bst[++total].val = wanted;
	bst[total].idx = total;
	bst[total].nadj = 0;
	bst[total].left = NULL;
	bst[total].right = NULL;
#if 0
	bst[++total] = {wanted, total, 1, NULL, NULL};
#endif
	if (wanted < parant->val) parant->left = &bst[total]; 
	else parant->right = &bst[total];
	return total;
}

void dfs(int idx, int dms)
{
	int i, reach;
	int nadj = bst[idx].nadj;
	bst[idx].idx = REACH;
	if (!dms) return;
	FORI(i, 1, i <= nadj) {
		reach = bst_find(mat[idx][i], NO);
		/* if (reach != REACH) { */
			dfs(reach, dms - 1);
		/* } */
	}
}

int main(int argc, const char *argv[])
{
#ifdef DB
	fp = fopen("input", "r");
#endif
	int i, n, rlt, idx, a, b, wanted, ttl, cases = 0;
	while (scanf("%d", &rlt), rlt) {
		FORI(i, 1, i <= rlt) {
			scanf("%d%d", &a, &b);
			idx = bst_find(a, YES);
			mat[idx][0] = a;
			mat[idx][++node_nadj(idx)] = b;
			idx = bst_find(b, YES);
			mat[idx][0] = b;
			mat[idx][++node_nadj(idx)] = a;
		}
		/* load done */
		while (scanf("%d%d", &wanted, &ttl), wanted || ttl) {
			n = total;
			if ((idx = bst_find(wanted, NO))) {
				dfs(idx, ttl);
				FORI(i, 1, i <= total) {
					if (bst[i].idx == REACH) {
						--n;
						bst[i].idx = i;
					}
				}
			}
			printf("Case %d: %d nodes not reachable from "
			       "node %d with TTL = %d.\n",
				++cases, n, wanted, ttl);
		}
		total = 0;
		/* memset(bst + 1, 0, sizeof(struct bst) * total); */
		ZERO(bst);
	}
	return 0;
}




#if 0
int bst_find(int wanted, int insert)
{
	int val;
	struct bst *child = bst, *parant;
	while (child) {
		parant = child;
		val = child->val;
		if (val == wanted) return child->idx;
		else if (wanted < val) child = child->left;
		else child = child->right;
	}
	if (!insert) return 0;
	bst[++total].val = wanted;
	bst[total].idx = total;
	bst[total].nadj = 0;
	bst[total].left = NULL;
	bst[total].right = NULL;
#if 0
	bst[++total] = {wanted, total, 1, NULL, NULL};
#endif
	if (wanted < parant->val) parant->left = &bst[total]; 
	else parant->right = &bst[total];
	return total;
}

void dfs(int idx, int dms)
{
	int i, reach;
	int nadj = bst[idx].nadj;
	mat[idx][0] = REACH;
	if (!dms) return;
	FORI(i, 1, i <= nadj) {
		reach = bst_find(mat[idx][i], NO);
		if (mat[reach][0] != REACH) {
			dfs(reach, dms - 1);
		}
	}
}

int main(int argc, const char *argv[])
{
#ifdef DB
	fp = fopen("input", "r");
#endif
	int i, n, rlt, idx, a, b, wanted, ttl, cases = 0;
	while (scanf("%d", &rlt), rlt) {
		FORI(i, 1, i <= rlt) {
			scanf("%d%d", &a, &b);
			idx = bst_find(a, YES);
			mat[idx][0] = a;
			mat[idx][++node_nadj(idx)] = b;
			idx = bst_find(b, YES);
			mat[idx][0] = b;
			mat[idx][++node_nadj(idx)] = a;
		}
		/* load done */
		while (scanf("%d%d", &wanted, &ttl), wanted && ttl) {
			if ((idx = bst_find(wanted, NO))) {
				dfs(idx, ttl);
				n = total;
				FORI(i, 1, i <= n) {
					if (mat[i][0] == REACH) --total;
				}
			}
			printf("Case %d: %d nodes not reachable from "
			       "node %d with TTL = %d.\n",
				++cases, total, wanted, ttl);
		}
		total = 0;
		/* memset(bst + 1, 0, sizeof(struct bst) * total); */
		ZERO(bst);
	}
	return 0;
}
#endif
