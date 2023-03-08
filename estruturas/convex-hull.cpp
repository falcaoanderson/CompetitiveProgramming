// 29/08/2020 // 05:56  PM// 

#include <bits/stdc++.h>

using namespace std;

#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl "\n"
#define pb push_back
//#define int long long

const int MAXN = (2e5) + 10;
const int MOD  = (1e9) + 7;
const int INF  = 0x3f3f3f3f;

struct point{
	double x, y;
	
	point(){}
	point(double _x, double _y){
		x = _x;
		y = _y;
	}
	
	point operator+(const point &tmp){
		return point(x+tmp.x, y+tmp.y);
	}
	point operator-(const point &tmp){
		return point(x-tmp.x, y-tmp.y);
	}
	bool operator==(const point &tmp){
		return (x==tmp.x && y==tmp.y);
	}
};

double cross(point a, point b, point c){
	a = a - b;
	b = c - b;
	
	return (a.x*b.y - a.y*b.x);
}
double dot(point a, point b, point c){
	a = a - b;
	b = c - b;
	
	return (a.x*b.x + a.y*b.y);
}
double abs(point a){
	return sqrt(a.x*a.x + a.y*a.y);
}
bool cw(point a, point b, point c){
	return cross(a, b, c)<0; 
}
bool cww(point a, point b, point c){
	return cross(a, b, c)>0; 
}

bool cmp(point a, point b){
	return (a.x < b.x || (a.x == b.x && a.y < b.y));
}

vector<point> convex_hull(vector<point> v){
	
	sort(v.begin(), v.end(), cmp);
	
	point a = v[0], b=v[v.size()-1];
	
	vector<point> up, down;
	up.pb(a);
	down.pb(a);
	
	for(int i=1; i<(int)v.size(); i++){
		if(cww(a, v[i], b) || i==v.size()-1){
			while(up.size()>=2 && !cww(up[up.size()-2], up[up.size()-1], v[i]))
				up.pop_back();
				
			up.pb(v[i]);
		}
		if(cw(a, v[i], b) || i==v.size()-1){
			while(down.size()>=2 && !cw(down[down.size()-2], down[down.size()-1], v[i]))
				down.pop_back();
	
			down.pb(v[i]);
		}
	}
	
	v.clear();
	
	for(int i=0; i<(int)down.size(); i++)
		v.pb(down[i]);
	for(int i=(int)up.size()-2; i>0; i--)
		v.pb(up[i]);
		
	
	if(v.size()==2 && v[0]==v[1]) v.pop_back();
	
	return v;
}

int	main(){
	fast_io;
	
	int n;
	while(true){
		cin >> n;
		
		if(n==0) break;
		
		vector<point> v(n, point(0,0));
		
		for(int i=0; i<n; i++)
			cin >> v[i].x >> v[i].y;
		
		vector<point> ch = convex_hull(v);
		
		cout << ch.size() << endl;
		
		for(point p: ch)
			cout << p.x << " " << p.y << endl;
	}
	
	return 0;
}
