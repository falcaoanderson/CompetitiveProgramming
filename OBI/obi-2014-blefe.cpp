// 27/08/2020 // 05:51 // 

#include <bits/stdc++.h>

using namespace std;

#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl "\n"
#define int long long

int32_t	main(){
	fast_io;
	
	
	int ta, tb;
	cin >> ta >> tb;
	vector<int> vb(tb);
	set<int> numbs;
	
	for(int i=0; i<ta; i++){
		int temp;
		cin >> temp;
		numbs.insert(temp);
	}
	
	for(int i=0; i<tb; i++) cin >> vb[i];
	
	
	set<int> aux;
	for(int i=0; i<tb; i++){
		bool blefe = (numbs.find(vb[i]) == numbs.end());
		
		int ini=0, fim=i-1;
		set<int>::iterator it_ini = aux.begin();
		set<int>::reverse_iterator it_fim=aux.rbegin();
		
		while(ini<=fim){
			if( (*it_ini + *it_fim) == vb[i]){
				blefe = 0;
				break;
			}
			
			if( (*it_ini + *it_fim) < vb[i]){
				it_ini++;
				ini++;
			}
			else{
				it_fim++;
				fim--;
			}
		}
		
		if(blefe){
			cout << vb[i] << endl;
			return 0;
		}
		
		aux.insert(vb[i]);
	}
	cout << "sim" << endl;

	return 0;
}
