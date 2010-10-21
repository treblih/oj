/*
 * =====================================================================================
 *
 *       Filename:  729.c
 *
 *    Description:  The Hamming Distance Problem
 *    		    backtrack
 *
 *        Created:  21.10.10
 *       Revision:  
 *       Compiler:  GCC 4.4
 *
 *         Author:  Yang Zhang, treblih.divad@gmail.com
 *        Company:  
 *
 * =====================================================================================
 */

#include <stdio.h>

static int bit;

void backtrack(int dms)
{
	int i, ncandidate, n = 1;
	int candidates[2];
	candidates[0] = '0'; 
	if (h) {candidates[1] = '1'; n = 2;}

	/* h == 0 */
	if (dms == bit) puts(solutions);
	else if (dms + h = bit) candidates[0] = '1';
	else {
		construct_solutions(dms, candidates, &ncandidate);
		for (i = 0; i < n; ++i) {
			solutions[dms] = candidates[i];
			if (i) --h;
			backtrack(dms + 1);
			if (i) ++h;
		}
	}
}

int main(int argc, const char *argv[])
{
	int cases, zeroes;
	scanf("%d", &cases);
	while (cases--) {
		scanf("%d%d", &bit, &ones);
		zeroes = bit - ones;
		for (i = 0; i < bit; ++i) {
			solutions[i] = (i >= bit) ? '1' : '0';
		}
		backtrack(0);
	}
	return 0;
}

#include <stdio.h>
#include <string.h>
int T,N,H;
char s[20]={'\0'},ham[20]={'\0'};
void dfs(int cur)
{
	if(cur==N)
		printf("%s\n",ham);
	else for(int i=0;i<N;i++)
		if(!i||s[i]!=s[i-1])
		{
			int c1=0,c2=0;
			for(int j=0;j<cur;j++) if(ham[j]==s[i]) c1++;
			for(int j=0;j<N;j++) if(s[j]==s[i]) c2++;
			if(c1<c2)
			{
				ham[cur]=s[i];
				dfs(cur+1);
			}
		}
}
int main()
{
	scanf("%d",&T);
	for(int t=0;t<T;t++)
	{
		if(t) printf("\n");
		scanf("%d %d",&N,&H);
		for(int i=0;i<N;i++)
			if(i<N-H) s[i]='0';
			else    s[i]='1';
		ham[N]='\0';
		dfs(0);
	}
	return 0;
}
