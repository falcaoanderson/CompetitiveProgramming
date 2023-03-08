// 21/08/2020 // 07:44 // 

#include <bits/stdc++.h>

using namespace std;

#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl "\n"
#define pb push_back
#define int long long

const int MAXN = (2e5) + 10;
const int MOD  = (1e9) + 7;
const int INF  = 0x3f3f3f3f;

int32_t	main(){
	fast_io;
	
	int n, num=2;
	cin >> n;
	
	for(int i=1; i<=n; i++) num += (num-1);
	
	num = num*num;
	
	cout << num << endl;
	
	return 0;
}
