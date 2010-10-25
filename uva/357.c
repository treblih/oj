/*
 * =====================================================================================
 *
 *       Filename:  357.c
 *
 *    Description:  Let Me Count the Ways
 *    		    dp & coin change
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

#include<stdio.h>  
int coin[5]={1,5,10,25,50};  
long long ans;  
long long f[32001];  
long long complete(int bound)  
{  
	f[0]=1;     
	for(int k=0;k<5;k++)  
		for(int i=coin[k];i<=bound;i++)  
			f[i]+=f[i-coin[k]];  
	return f[bound];  
}  
int main()  
{     
	int n;  
	complete(30000);  
	while(scanf("%d",&n)!=EOF)  
	{  
		ans=f[n];  
		if(ans==1)printf("There is only 1 way to produce %d cents change.\n",n);  
		else printf("There are %lld ways to produce %d cents change.\n",ans,n);  
	}  
}  
