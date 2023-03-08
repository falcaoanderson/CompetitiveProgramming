// 03/09/2020 // 04:02 PM// 

#include <bits/stdc++.h>

using namespace std;

#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl "\n"
#define pb push_back

int	main(){
	fast_io;
	
	vector<int> v(3, 0);
	cin >> v[0] >> v[1] >> v[2];
	sort(v.begin(), v.end());
	
	int resp = 0;
	if(v[0]>0) resp += v[0];
	if(v[0]+200<v[1]) resp+= v[1] - v[0] - 200;
	if(v[1]+200<v[2]) resp+= v[2] - v[1] - 200;
	if(v[2]+200<600)  resp+= 600 - v[2] - 200;
	
	cout << resp*100 << endl;
	
	return 0;
}
