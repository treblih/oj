/*
 * =====================================================================================
 *
 *       Filename:  1459.c
 *
 *    Description:  The Tree Root
 *    		    dfs & recursion
 *
 *        Created:  20.10.10
 *       Revision:  
 *       Compiler:  GCC 4.4
 *
 *         Author:  Yang Zhang, treblih.divad@gmail.com
 *        Company:  
 *
 * =====================================================================================
 */
#include<iostream>
#include<vector>
using namespace std;
#define REP(i,b,n) for(int i=b;i<n;i++)
#define rep(i,n)   REP(i,0,n)
#define ALL(C)     (C).begin(),(C).end()

const int N = 5000;
class state{
	public:
		int n,d;
		bool operator<(const state & a)const{
			if (d != a.d)return d < a.d;
			return n < a.n;
		}
};

int cost[N];

state ans[N];
vector<int> edge[N];
vector<int> leng[N];


int dfs(int n,int now,int prev,int d){
	int maxi=0;
	rep(i,edge[now].size()){
		if (edge[now][i] == prev){
			leng[now].push_back(-1);
			continue;
		}
		int tmp = dfs(n,edge[now][i],now,d+1);
		maxi=max(tmp,maxi);
		leng[now].push_back(tmp);
	}
	return maxi+1;
}

void solve(int n,int now,int prev,int nowmax){
	int maxi[2]={nowmax,0};
	ans[now].n=now;
	ans[now].d=nowmax;

	rep(i,leng[now].size()){
		int tmp = leng[now][i];
		if (edge[now][i] == prev){
			tmp=nowmax;
		}

		if (tmp > maxi[0]){
			maxi[1]=maxi[0];
			maxi[0]=tmp;
		}else if (tmp <= maxi[0] && maxi[1] <= tmp){
			maxi[1]=tmp;
		}
	}

	ans[now].d=max(maxi[0],max(nowmax,ans[now].d));
	//  cout <<now <<" " << ans[now].d << endl;

	if (maxi[0] == 0)return;
	rep(i,edge[now].size()){
		int next=edge[now][i];
		if(next == prev)continue;
		if (leng[now][i] == maxi[0] ){
			solve(n,next,now,maxi[1]+1);
		}else {
			solve(n,next,now,maxi[0]+1);
		}
	}
}

main(){
	int n;
	int tc=0;
	while(cin>>n){
		rep(i,n)leng[i].clear();
		rep(i,n){
			int m;
			cin>>m;
			edge[i].clear();
			rep(j,m){
				int t;
				cin>>t;
				edge[i].push_back(t-1);
			}
		}


		dfs(n,0,-1,0);
		solve(n,0,-1,0);


		sort(ans,ans+n);
		cout << "Best Roots  :";
		rep(i,n){
			if (ans[i].d != ans[0].d)break;
			cout << ' ' << ans[i].n+1;
		}
		cout << endl;

		cout << "Worst Roots :";
		int index =0;
		for(int i=n-1;i>=0;i--){
			if (ans[i].d != ans[n-1].d)break;
			index=i;
		}

		for(int i=index;i<n;i++){
			cout << ' ' << ans[i].n+1;
		}
		cout << endl;
	}
}
