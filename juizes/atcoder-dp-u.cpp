// 16/06/2020 // 7:15 PM // 

#include <bits/stdc++.h>

using namespace std;

#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);
#define endl "\n"
#define pb push_back
#define ll long long

const int MAXN  = 20;
const ll INF   = 0x3f3f3f3f3f3f3f3f;
const int MAXNN = 65536 + 5; // 2^16 + 5 

int n, max_mask; 
ll a[MAXN][MAXN], pts[MAXNN];
vector<ll> memo;

void pre_calc(){
	for(int mask=1; mask<=max_mask; mask++){   // O(2^n * n^2)
		for(int i=0; i<=n; i++){
			if(((1<<i)&mask) == 0) continue;
			
			for(int j=i+1; j<=n; j++)
				if(((1<<j)&mask)!=0)
					pts[mask] += a[i][j];
		}
	}
}

void solve(){
	
	memo[max_mask] = 0;
	for(int mask_total=max_mask-1; mask_total>=0; mask_total--){
		vector<int> disp;
		for(int k=0; k<n; k++){
			if(((1<<k)&mask_total)==0) disp.pb(k);
		}
		int max_temp = (1<<((int)disp.size()))-1; 
		for(int tmask=1; tmask<=max_temp; tmask++){
			int gp_mask = 0;
			for(int k=0; k<(int)disp.size(); k++){
				if(((1<<k)&tmask)!=0) gp_mask += (1<<disp[k]);
			}
			
			memo[mask_total] = max(memo[mask_total], pts[gp_mask] + memo[mask_total|gp_mask]);
		}
	}
	
}

int	main(){
	fast_io;
	
	cin >> n; 
	
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			cin >> a[i][j];
	
	max_mask = (1<<n)-1;
	
	memo.resize(max_mask+1, -INF);
		
	pre_calc();
	solve();
	
	cout << memo[0] << endl;
	
	return 0;
}
