// 23/06/2020 // 12:29 AM // 

#include <bits/stdc++.h>

using namespace std;

#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl "\n"
#define pb push_back
//#define int long long

const int MAXN = (2e5) + 10;
const int MOD  = (1e9) + 7;
const int INF  = 0x3f3f3f3f;

int	main(){
	fast_io;
	
	int n;
	cin >> n;
	
	if(n==2 || n==3) cout << "NO SOLUTION" << endl;
	else if(n==4) cout << "2 4 1 3" << endl;
	else{
		for(int i=1; i<=n; i+=2) cout << i << " ";
		for(int i=2; i<=n; i+=2) cout << i << " ";
		cout << endl;
	}
	
	return 0;
}

