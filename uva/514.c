/*
 * =====================================================================================
 *
 *       Filename:  514.c
 *
 *    Description:  Rails
 *    		    stack
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
#define	SIZE	1024
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
static int list[SIZE];
static int stack[SIZE];
enum {USED = 1050};

void check(int n)
{
	int head;
	int stk;
	int i, j;
	FORIZ(i, i < n) {
		if ((head = list[i]) == USED) continue;
		stk = 0;
		FORI(j, i + 1, j < n) {
			if (head > list[j]) {
				if (stk && stack[stk-1] < list[j]) {puts("No"); return;}
				stack[stk++] = list[j];
				list[j] = USED;
			}
		}
		/* all left are decreasing */
		if ((stk + i + 1) == n) {
			puts("Yes"); 
			return;
		}
	}
}

int main(int argc, const char *argv[])
{
#ifdef DB
	fp = fopen("input", "r");
#endif
	int i, n;
	int tmp[SIZE];
	while (scanf("%d", &n), n) {
		while (scanf("%d", &list[0]), list[0]) {
			FORI(i, 1, i < n) scanf("%d", &list[i]);
			/* memcpy(tmp, list, n << 2); */
			check(n);
			/* memcpy(list, tmp, n << 2); */
		}
	}
	return 0;
}




#if 0
#include <iostream>
#include <stack>
#include <cstdio>
#ifdef DB
	#define getchar()		getc(fp)
	#define	scanf(...)		fscanf(fp, __VA_ARGS__)
	#undef	stdin
	#define stdin			fp
#endif
static FILE *fp;


using namespace std;
const int MAXN = 1001;
int n, per[MAXN];

bool Judge()
{
	int i, j, pre;
	stack <int> st;
	for(i = 1; i < per[0]; i ++) st.push(i); /* 小于第一个元素的肯定都入栈了 */
	pre = per[0];
	for(i = 1; i < n; i ++) {
		if(pre < per[i]) {
			for(j = pre + 1; j < per[i]; j ++) {
				st.push(j);
			}
			pre = per[i];
		}else if(st.top() == per[i]) {
			st.pop();
		}else {
			return false;
		}
	}
	return true;
}

int main()
{
#ifdef DB
	fp = fopen("input", "r");
#endif
	while(cin >> n && n) {
		while(cin >> per[0] && per[0]) {
			for(int i = 1; i < n; i ++)
				cin >> per[i];
			if(Judge()) cout << "Yes" << endl;
			else cout << "No" << endl;
		}
		cout << endl;
	}
	return(0);
}
#endif
