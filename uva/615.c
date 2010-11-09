/*
 * =====================================================================================
 *
 *       Filename:  615.c
 *
 *    Description:  Is It A Tree?
 *    		    directional graph & dfs
 *
 *        Created:  15.10.10
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

#define	SIZE	1024
#ifdef DB
	#define getchar()		getc(fp)
	#define	scanf(...)		fscanf(fp, __VA_ARGS__)
	#define	ungetc(c, stdin)	ungetc(c, fp)
#endif
static FILE *fp;

static int max = -1, cnt;
static char roots[SIZE];
static char graph[SIZE][SIZE];
static char visit[SIZE];

int dfs(int start)
{
	int i;
	if (visit[start]) return 1;
	else visit[start] = 1;
	++cnt;
	for (i = 0; i <= max; ++i) {
		if (graph[start][i] > 1) return 1;
		else if (graph[start][i] == 1) {
				if (dfs(i)) return 1;
		}
	}
	return 0;
}

int main(int argc, const char *argv[])
{
#ifdef DB
	fp = fopen("input", "r");
#endif
	int a, b, i, root;
	int cases = 0;
	int not = 0;
	int edges = 0;
	int vertices = 0;
	while (scanf("%d%d", &a, &b) != EOF) {
		/* if (a < 0) { */
		if (a < 0 && b < 0) break;
		else if (!a && !b) goto load_done;
		else {
			if (max < a) max = a;
			if (max < b) max = b;
			if (!roots[a]) roots[a] = 1;
			if (roots[b] == -1) not = 1;
			else roots[b] = -1;
			if (!visit[a]) {
				visit[a] = 1;
				++vertices;
			}
			if (!visit[b]) {
				visit[b] = 1;
				++vertices;
			}
			++graph[a][b];
			++edges;
			continue;
		}
load_done:
		++cases;
		if (!vertices && !edges) goto is;
		if (vertices != edges + 1) goto not;
		for (i = 0, root = -1; i <= max; ++i) {
			if (roots[i] == 1) {
				if (root > -1) {
					goto not;
				} else root = i;
			}
		}
		/* assembly style */
		/* max >= 0   -> at least 1 node 
		 * root == -1 -> cycle */
		if (root == -1 && max >= 0) goto not;
		memset(visit, 0, max + 1);
		if (dfs(root)) goto not;
		if (vertices != cnt) goto not;
is:
		printf("Case %d is a tree.\n", cases);
		goto reset;
not:
		printf("Case %d is not a tree.\n", cases);
reset:
		memset(roots, 0, max + 1);
		memset(visit, 0, max + 1);
		memset(graph, 0, sizeof(graph));
		max = -1;
		vertices = edges = not = cnt = 0;
	}
	
	return 0;
}

#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

bool f[1001],flag;
int p[1001];
int cnt[1001];


//初值化
void init()
{
    flag = false;
    for(int i=1;i<=1001;i++)
    {
        p[i] = i;
        f[i] = false;
        cnt[i] = 0;
    }
}

//查找父亲结点
int find_set(int x)
{
    if( p[x] != x)
        p[x] = find_set(p[x]);
    return p[x];
}


//判断是否连通
bool Judge()
{
    for(int i=1;i<=1001;i++)
    {
        if( f[i] )  cnt[find_set(i)]++;//如果是一棵树的话，就只会有一个根，就只会出现一个比1大的值
    }
    int t=0;
    for(int i=1;i<=1001;i++)
    {
        if( cnt[i] > 1) t++;//同上
    }
    if(t > 1) return false;
    else      return true;
}

int main()
{
    int a ,b,num=0;
    init();
    while( scanf("%d%d",&a,&b))
    {
        if( a < 0 ) break;
        if( a == 0 && b == 0)
        {
            num++;
            if( flag ) printf("Case %d is not a tree.\n",num);
            if( !flag )
            {
                if(Judge()) printf("Case %d is a tree.\n",num);
                else        printf("Case %d is not a tree.\n",num);
            }
            init();
            continue;
        }

        f[a] =  f[b] = true;
        if( find_set(a) == find_set(b) || find_set(b) != b ) flag = true; //判断是否有环和一个节点是否有两个父亲
        else
        {
            p[b] = a;//合并
        }
    }
}


// 题目没说最大的数是多少 ，我开1000能过，开100也能过。但是在hdu上 TLE，因为这题我是昨天刚学习用度来判断树的
// 所以想不出高深的算法

#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

int chu[101];
int ru[101];
bool G[101][101];
bool f[101];
int sum ,minn ,maxn;

//判断连通性
void dfs(int cur)
{
    f[cur]=true;
    sum ++;
    for(int i=minn ;i <= maxn ;i++)
    {
        if( !f[i] && G[cur][i])
        {
            dfs(i);
        }
    }
}

int main()
{
    int num = 0;
    while(1)
    {
        int a ,b , s=0;
        maxn = 0 ,minn=200000;
        memset( G , false , sizeof(G));
        memset( f, false , sizeof(f));
        memset(chu , 0 , sizeof(chu));
        memset(ru , 0 , sizeof(ru));

        while( scanf("%d%d",&a,&b) )
        {
            if( a == 0 && b == 0) break;
            if( a == -1 && b == -1) break;
            G[a][b] = true;
            chu[a]++;
            ru[b]++;
            if( a > b ) swap(a,b);
            if( maxn < b ) maxn = b;
            if( minn > a )  minn = a;
            s++;
        }
        if( a == -1 && b == -1) break;
        num++;
        if( a == 0 && b == 0 && s == 0 ) cout <<"Case " << num << " is a tree." <<endl; //单个 0 0 为空树
        else
        {
            bool flag = false;
            int root=0 ,cnt=0;
            for(int i=minn;i<=maxn;i++)
            {
                if(ru[i]==0 && chu[i] && !root)
                {
                    root = i; // 找根
                }
                if(ru[i] || chu[i]) cnt++;//找结点数
            }
            //因为题目说了最小数大于0 ，如果也现root == 0 ，说明没有根，就有环了
            if( root == 0) cout <<"Case "<< num << " " << "is not a tree."<<endl;
            else
            {
                sum = 0;
                dfs(root);//判断连通
                if( sum != cnt ) cout <<"Case "<< num << " " << "is not a tree."<<endl;// 不连通则不是一棵树
                else
                {
                    int n1 = 0 , n2 = 0 ,n3=0;
                    for(int i=minn;i<=maxn;i++)
                    {
                        if( ru[i]==0 && chu[i] ) n1 ++; // 根
                        else if( ru[i]==1 && chu[i]==0 ) n2 ++; // 叶子结点
                        else if( i != root && ru[i] && chu[i] ) n3++; // 中间结点
                    }
                    if( n1 + n2 + n3 == cnt) cout <<"Case "<<num << " " << "is a tree."<<endl; // 当他们相等时为树
                    else                     cout <<"Case "<<num << " " << "is not a tree."<<endl;// 否则不是
                }
            }
        }
    }
    return 0;
}
