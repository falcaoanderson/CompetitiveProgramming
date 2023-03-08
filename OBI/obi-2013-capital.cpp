// 14/06/20 // 1:58 PM //

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define pb push_back

const int MAXN = (1e5)+10;

int main(){
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	
	if(a*b==c*d || a*c == b*d || a*d == b*c)
		cout << "S" << endl;
	else
		cout << "N" << endl;
	
	return 0;
}
