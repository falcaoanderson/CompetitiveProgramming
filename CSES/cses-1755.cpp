// 22/09/2020 // 09:25 PM// 

#include <bits/stdc++.h>

using namespace std;

#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl "\n"

const int MAXN = 100;

int v[MAXN];

int	main(){
	fast_io;
	
	string aa;
	cin >> aa;
	int n = aa.size();
	
	for(int i=0; i<n; i++) v[int(aa[i])]++;
	
	int cImpar=0;
	char impar;
	for(int i=65; i<=90; i++) 
		if(v[i]&1){
			cImpar++;
			impar = char(i);
			v[i]--;
		}
		
	if(cImpar>1 || (cImpar==1 && ~n&1)){
		cout << "NO SOLUTION" << endl;
		return 0;
	}
	
	for(int i=65; i<=90; i++)
		for(int k=0; k<v[i]/2; k++)
			cout << char(i);
	
	if(cImpar) cout << impar;
	
	for(int i=90; i>=65; i--)
		for(int k=0; k<v[i]/2; k++)
			cout << char(i);
	cout << endl;
	
	return 0;
}
