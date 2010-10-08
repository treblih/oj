/*
 * =====================================================================================
 *
 *       Filename:  429.c
 *
 *    Description:  
 *
 *        Created:  06.10.10
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
 
#define SIZE 200
 
typedef struct{
	int n,len;
}State; 
 
int T,N,s,e;
char dic[SIZE][11],con[SIZE][SIZE];
 
char Transform(char a[], char b[]) {
	int la=strlen(a),lb=strlen(b),i,cnt=0;
 
	if(la != lb)
		return 0;
	for(i=0; i<la; i++)
		if(a[i] != b[i])
			cnt++;
	return (cnt == 1);
}
 
int BFS() {
	int i,front,rear;
	State queue[SIZE],cur;
	char close[SIZE];
 
	memset(close, 0, sizeof(close));
	close[s] = 1;
	front = rear = 0;
	queue[rear].n = s;
	queue[rear++].len = 0; 
	while(front != rear) {
		cur = queue[front++];
		if(cur.n == e)
			return cur.len;
		for(i=0; i<N; i++) {
			if(con[cur.n][i] == 1 && close[i] == 0) {
				queue[rear].n = i;
				queue[rear++].len = cur.len + 1;
				close[i] = 1;
			}
		}
	}
}				
 
 
int main() {
	int i,j,dif;
	char tmp[22],*start,*end;
 
//	freopen("test.out", "w", stdout);
	scanf("%d", &T);
	getchar();
	getchar();
	while(T--) {
		N = 0;
		while(gets(tmp) != NULL) {
			if(!strcmp(tmp, "*"))
				break;
			strcpy(dic[N++], tmp);
		}
		memset(con, 0, sizeof(con));
		for(i=0; i<N; i++)
			for(j=0; j<N; j++)
				con[i][j] = Transform(dic[i], dic[j]);
		while(gets(tmp) != NULL){
			if(!strcmp(tmp, ""))
				break;
			start = strtok(tmp, " ");
			end = strtok(NULL, " ");
			for(i=0; i<N; i++) {
				if(!strcmp(start, dic[i]))
					s = i;
				if(!strcmp(end, dic[i]))
					e = i;
			}
			printf("%s %s %d\n", start, end, BFS());
		}		
		if(T != 0)
			printf("\n");		
	}
	return 0;
}
