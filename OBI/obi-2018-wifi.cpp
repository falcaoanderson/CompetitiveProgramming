// 21/08/2020 // 08:10 PM// 

#include <bits/stdc++.h>

using namespace std;

#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl "\n"

const int MAXN = (1e5) + 10;

struct retangulo{
	int x1, y1, x2, y2;
	
	retangulo(){}
	retangulo(int _x1, int _y1, int _x2, int _y2){
		x1 = _x1;
		y1 = _y1;
		x2 = _x2;
		y2 = _y2;
	}
};

int n;
retangulo v[MAXN];

int	main(){
	fast_io;
	
	cin >> n;
	
	for(int i=1; i<=n; i++)
		cin >> v[i].x1 >> v[i].y1 >> v[i].x2 >> v[i].y2;
	
	int cont = 0;
	
	for(int i=1; i<=n; i++){
		int temp = 1;
		for(int j=1; j<=n; j++){
			if(v[i].x1<v[j].x1 && v[i].y1>v[j].y1 && v[i].x2>v[j].x2 && v[i].y2<v[j].y2){
				temp = 0;
				break;
			}
		}
		
		cont += temp;
	}
	
	cout << cont << endl;
	
	return 0;
}
