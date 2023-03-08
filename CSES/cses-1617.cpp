// 21/09/2020 // 10:10 // 

#include <bits/stdc++.h>

using namespace std;

#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl "\n"
#define int long long

const int MOD  = (1e9) + 7;

int32_t	main(){
	fast_io;
	
	int n, x=2, resp=1;
	cin >> n;
	
	while(n>0){
		
		if(n&1) resp = (resp*x)%MOD;
		
		x = (x * x)%MOD;
		n /= 2;
	}
	
	cout << resp << endl;
	
	return 0;
}
