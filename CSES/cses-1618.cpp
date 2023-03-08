// 22/09/2020 // 09:00 PM// 

#include <bits/stdc++.h>

using namespace std;

#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl "\n"
#define pb push_back
//#define int long long

int	main(){
	fast_io;
	
	int n, resp=0;
	cin >> n;
	
	for(int i=5; i<=n; i*=5) resp += n/i;
	
	cout << resp << endl;
	
	return 0;
}
