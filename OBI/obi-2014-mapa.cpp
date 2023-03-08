// 22/09/2020 // 09:47 PM// 

#include <bits/stdc++.h>

using namespace std;

#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl "\n"
#define pb push_back
#define int long long

const int MAXN = (1e5) + 10;

int n;
vector< pair<int, bool> > grafo[MAXN];
int memo[MAXN][2], pai[MAXN], pai_flag[MAXN], qnt_filhos[MAXN];
int ca[MAXN];

int pre_dfs(int no, bool flag){
	
	if(memo[no][flag]!=-1) return memo[no][flag];
	
	memo[no][flag] = 0;
	for(auto v: grafo[no]){
		if(pai[no] == v.first) continue;
		
		
		pai[v.first] = no;
		pai_flag[v.first] = v.second;
		 
		memo[no][flag] += pre_dfs(v.first, flag||v.second) + (flag||v.second);
		if(flag || v.second) pre_dfs(v.first, 0);
		
		if(!flag) qnt_filhos[no] += 1 + qnt_filhos[v.first];
	}
	
	return memo[no][flag];
}

int solve(int no){
	
	if(ca[no]!=-1) return ca[no];
	
	if(no==1) 
		return memo[1][0];
	if(!pai_flag[no])
		return ca[no] = solve(pai[no]);
	else  
		return ca[no] = memo[no][0] + n - qnt_filhos[no] - 1;
}


int32_t	main(){
	fast_io;

	cin >> n;
	
	for(int i=1; i<n; i++){
		int a, b, c;
		cin >> a >> b >> c;
		
		grafo[a].pb({b, c});
		grafo[b].pb({a, c});
	}
	
	memset(memo, -1, sizeof(memo));
	memset(ca, -1, sizeof(ca));
	pai[1] = 1;
	pre_dfs(1, 0);
	
	int resp = 0;
	for(int i=1; i<=n; i++) resp += solve(i);
	resp /= 2;
	
	cout << resp << endl;
	
	return 0;
}
