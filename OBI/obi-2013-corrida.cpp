// 14/06/20 // 9:23 PM //

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define pb push_back

const int MAXN = (1e5)+10;

int main(){
	int n1, n2, d1, d2, v1, v2;
	
	cin >> n1 >> d1 >> v1 >> n2 >> d2 >> v2;
	
	if(d1*v2 < d2*v1)
		cout << n1 << endl;
	else 
		cout << n2 << endl;
	
	return 0;
}
