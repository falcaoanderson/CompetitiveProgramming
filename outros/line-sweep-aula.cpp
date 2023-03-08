// 24/08/2020 // 05:20 // 

#include <bits/stdc++.h>

using namespace std;

#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl "\n"
#define pb push_back
//#define int long long

const int MAXN = (1e5) + 10;
//const int MOD  = (1e9) + 7;
//const int INF  = 0x3f3f3f3f;

int n;
pair<int, bool> v[2*MAXN];

int	main(){
	fast_io;
	
	cin >> n;
	for(int i=1; i<=n; i++){
		cin >> v[i].first >> v[i+n].first;
		v[i].second  = 0;
		v[i+n].second  = 1;
	}
	sort(v+1, v+2*n+1);
	
	int cont = 0, maxcont = 0;
	v[2*n+1].first = -1;
	
	for(int i=1; i<=2*n; i++){
		if(v[i].second) cont--;
		else            cont++;
		
		if(v[i].first != v[i+1].first) maxcont = max(maxcont, cont);
	}
	
	cout << maxcont << endl;
	
	return 0;
}
