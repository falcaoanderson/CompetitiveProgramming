// 27/08/2020 // 07:45 // 

#include <bits/stdc++.h>

using namespace std;

#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl "\n"

int	main(){
	fast_io;
	
	int n;
	cin >> n;
	
	matrix v(2, vector<int>(n));
	
	for(int i=0; i<n; i++) cin >> v[0][i];
	
	for(int i=0; i<n-1; i++){
		for(int j=0; j<n-i-1; j++){
			if(v[i&1][j]==v[i&1][j+1]) v[~i&1][j] = 1;
			else 					   v[~i&1][j] = -1;	
		}
	}
	
	cout << (v[~n&1][0]==1? "preta":"branca") << endl;
	
	return 0;
}
