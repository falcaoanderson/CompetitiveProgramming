// 27/08/2020 // 08:28 // 

#include <bits/stdc++.h>

using namespace std;

#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl "\n"

const int MAXN = (1e5) + 10;
const int INF  = 0x3f3f3f3f;

int n, l, h, v[MAXN];
int memo[MAXN][25];
bool ma[MAXN];

int	main(){
	fast_io;
	
	cin >> n >> l >> h;
	
	for(int i=1; i<=n; i++) cin >>  v[i];
	for(int i=1; i<=n; i++) cin >> ma[i];
	
	for(int i=0; i<=n+1; i++)
		for(int j=0; j<=20; j++)
			memo[i][j] = -INF;
	
	if(ma[1]){
		memo[1][1] = v[1];
		memo[1][0] =    0; 
	}
	else{
		memo[1][0] = max(0, v[1]);
	}
	
	for(int i=2; i<=n; i++){
		for(int j=0; j<=20; j++){
			if(ma[i]){
				if(j==0) memo[i][j] = 0;
				else     memo[i][j] = v[i] + memo[i-1][j-1];
			}
			else{
				if(j==0) memo[i][j] = max(0, v[i] + memo[i-1][j]);
				else     memo[i][j] = v[i] + memo[i-1][j];
			}
		}
	}
	
	int resp = -INF;
	for(int i=1; i<=n; i++)
		for(int j=l; j<=h; j++)
			resp = max(resp, memo[i][j]);
	
	cout << resp << endl;
	
	return 0;
}
