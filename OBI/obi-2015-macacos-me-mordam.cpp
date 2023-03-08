// 29/08/2020 // 07:45 // 

#include <bits/stdc++.h>

using namespace std;

#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl "\n"
#define pb push_back

struct point{
	double x, y;
	
	point(){}
	point(double _x, double _y){
		x = _x;
		y = _y;
	}
	
	point operator-(const point &tmp){
		return point(x-tmp.x, y-tmp.y);
	}
};

double cross(point a, point b, point c){
	a = a - b; 
	b = c - b;
	return a.x*b.y - a.y*b.x; 
}

bool cww(point a, point b, point c){
	return cross(a, b, c)>0;
}

bool cmp(point a, point b){
	return a.x < b.x;
}

int	main(){
	fast_io;
	
	int n;
	cin >> n;
	
	vector<point> v(n, point(0, 0));
	for(int i=0; i<n; i++) cin >> v[i].x >> v[i].y;
	
	sort(v.begin(), v.end(), cmp);
	
	vector<point> up;
	up.pb(v[0]);
	
	for(int i=1; i<n; i++){
		while(up.size()>=2 && !cww(up[up.size()-2], up[up.size()-1], v[i]))
			up.pop_back();
		
		up.pb(v[i]);
	}
	
	cout << up.size()-1 << endl;
	
	return 0;
}
