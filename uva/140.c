/*
 * =====================================================================================
 *
 *       Filename:  140.c
 *
 *    Description:  Bandwidth
 *    		    backtrack
 *
 *        Created:  09.10.10
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
#include <ctype.h>
#include <stdbool.h>
#define MAXN 1048576
#define Msize 30
int cmp_int(const void *_a,const void *_b)
{
	int* a=(int*)_a;
	int* b=(int*)_b;
	return *a-*b;
}
int N,g[Msize][Msize]={0},b[Msize]={0};
bool vis[Msize]={false};
char s[MAXN]={'\0'};
void Solve(int len)
{
	int u[Msize]={0},v[Msize]={0},lu=0,lv=0,cnt=1;
	N=0;
	memset(g,0,sizeof(g));
	memset(vis,false,sizeof(vis));
	for(int i=0;i<=len;i++)
	{
		if(isalpha(s[i]))
		{
			if(cnt)
			{
				u[lu++]=s[i]-'A';
				if(!vis[u[lu-1]]) b[N++]=u[lu-1];
				vis[u[lu-1]]=true;
			} else {
				v[lv++]=s[i]-'A';
				if(!vis[v[lv-1]]) b[N++]=v[lv-1];
				vis[v[lv-1]]=true;
			}
		}else if(s[i]==':')
			cnt=0;
		else if(s[i]==';'||i==len)
		{
			for(int j=0;j<lu;j++)
				for(int k=0;k<lv;k++)
					g[u[j]][v[k]]=g[v[k]][u[j]]=1;
			lv=lu=0;
			cnt=1;
		}
	}
	qsort(b,N,sizeof(int),cmp_int);
}
int a[Msize]={0},mink,minc,k,w[Msize]={0};
void dfs(int cur)
{
	int u,v;
	for(int i=0;i<N;i++)
		if(!vis[i])
		{
			a[cur]=i;
			vis[i]=true;
			if(cur==N-1)
			{
				k=1;
				for(int j=0;j<N-1;j++)
				{
					for(int l=j+1;l<N;l++)
					{
						u=b[a[j]];
						v=b[a[l]];
						if(g[u][v]&&k<l-j)
							k=l-j;
					}
					if(mink<=k) break;
				}
				if(mink>k)
				{
					mink=k;
					for(int j=0;j<N;j++) w[j]=b[a[j]];
				}
			}
			else dfs(cur+1);
			vis[i]=false;
		}
}
int main()
{
	while(scanf("%s",s)==1)
	{
		if(s[0]=='#') break;
		Solve(strlen(s));
		memset(vis,false,sizeof(vis));
		mink=MAXN;
		dfs(0);
		for(int i=0;i<N;i++)
			printf("%c ",w[i]+'A');
		printf("-> %d\n",mink);
	}
	return 0;
}
