// 01/09/2020 // 06:48 // 
 
#include <bits/stdc++.h>
 
using namespace std;
 
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl "\n"
 
int	main(){
	fast_io;
	
	int n;
	cin >> n;
	
	if(n&1 && (n-3)%4 == 0){
		cout << "YES\n";
		cout << n/2 + 1 << endl;
		cout << "1 2 ";
		for(int i=4; i<=n; i+=4) cout << i << " " << i+3 << " ";
		
		cout << endl << n/2 << endl;
		cout << 3 << " ";
		for(int i=5; i<=n; i+=4) cout << i << " " << i+1 << " ";
		cout << endl;
	}
	else if(n%4==0){
		cout << "YES\n";
		cout << n/2 << endl;
		for(int i=1; i<=n; i+=4) cout << i << " " << i+3 << " ";
		cout << endl << n/2 << endl;
		for(int i=2; i<=n; i+=4) cout << i << " " << i+1 << " ";
		cout << endl;
	}	
	else
		cout << "NO" << endl;
		
	return 0;
}
