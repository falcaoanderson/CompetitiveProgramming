// 15/06/20 // 4:46 PM //

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define pb push_back
#define int long long

const int MAXN = (3e3) + 10;
const int MOD  = (1e9) + 7;

int n, memo[2][MAXN], prefix[MAXN];
string cond;

int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n >> cond;	
		
	memo[1][1] = 1;
	for(int i=2; i<=n; i++){
		
		for(int k=1; k<=i; k++){
			prefix[k] = prefix[k-1] + memo[~i&1][k];
			prefix[k] %= MOD;
		}
		
		for(int j=1; j<=i; j++){
			if(cond[i-2]=='<')
				memo[i&1][j] = prefix[j-1];
			else
				memo[i&1][j] = (MOD + prefix[i] - prefix[j-1])%MOD;
		}
	}
	
	int resp = 0;
	for(int k=1; k<=n; k++){
		resp += memo[n&1][k];
		resp %= MOD;
	}
	
	cout << resp << endl;
	
	return 0;
}
