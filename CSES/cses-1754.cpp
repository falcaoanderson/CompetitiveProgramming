// 22/09/2020 // 09:15 PM// 

#include <bits/stdc++.h>

using namespace std;

#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl "\n"

int	main(){
	fast_io;
	
	int t;
	cin >> t;
	
	while(t--){
		int a, b;
		cin >> a >> b;
		
		if(2*a>=b && 2*b>=a && (2*a-b)%3==0 && (2*b-a)%3==0)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
			
	}
	
	return 0;
}
