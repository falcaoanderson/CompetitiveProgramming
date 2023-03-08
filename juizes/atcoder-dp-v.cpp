// 21/06/2020 // 04:36 PM // 

#include <bits/stdc++.h>

using namespace std;

#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl "\n"
#define pb push_back
#define int long long

const int MAXN = (1e5) + 10;
const int MOD  = (1e9) + 7;
const int INF  = 0x3f3f3f3f;

int n, m;
bool visitado[MAXN];
vector< vector<int> > grafo;
vector<int> qnt, pai, memo;

int pre_dfs(int no){
	qnt[no] = 1;
	
	for(int adj: grafo[no]){
		if(qnt[adj] != -1) continue;
		
		pai[adj] = no;
		qnt[no] *= (pre_dfs(adj) + 1);
		qnt[no] %= m;
	}
	
	return qnt[no];
}

int dfs(int no){
	if(memo[no]!=-1) return memo[no];
	
	if(no==1) return qnt[1];
	
	return memo[no] = (qnt[no] * (dfs(pai[no])/(qnt[no]+1)) + qnt[no])%m; // nao funciona
}

int32_t	main(){
	fast_io;
	
	cin >> n >> m;
	
	grafo.resize(n+1, vector<int>());
	qnt.resize(n+1, -1);
	pai.resize(n+1);
	memo.resize(n+1, -1);
	
	for(int i=1; i<n; i++){
		int a, b;
		cin >> a >> b;
		
		grafo[a].pb(b);
		grafo[b].pb(a);
	}
	
	pai[1] = 1;
	pre_dfs(1);
	
	for(int i=1; i<=n; i++) 
		cout << dfs(i) << endl;
	
	return 0;
}
