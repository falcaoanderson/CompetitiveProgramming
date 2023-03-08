#include <iostream>

using namespace std;

#define MAXT 100010

int ta=0, tb=0;
int va[MAXT], vb[MAXT];

int main(){
	int ca, cb;
	cin >> ca >> cb;
	
	int temp;
	for(int i=0; i<ca; i++){
		cin>>temp;
		va[temp]++;
	}
	for(int i=0; i<cb; i++){
		cin>>temp;
		vb[temp]++;
	}
	
	for(int i=1; i<=MAXT-10; i++){
		if(va[i]>0 && vb[i]==0)
			ta++;
		if(vb[i]>0 && va[i]==0)
			tb++;
	}
	
	cout << min(ta, tb) << "\n"; 
	
	return 0;
}