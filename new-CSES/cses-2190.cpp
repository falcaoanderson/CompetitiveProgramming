// 13/05/23 //
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <tuple>
#include <cstring>
 
using namespace std;
 
#define ll long long 
#define endl "\n"
#define PB push_back
#define EB emplace_back
#define ff first
#define ss second
 
struct point{
    long long x, y;
    
    point(){}
    point(long long x_, long long y_){
        x = x_;
        y = y_;
    }

    ll qmod(){
        return x*x + y*y;
    }
    bool operator==(const point &p){
        return (x==p.x && y==p.y);
    }
    bool operator<(const point &p){
        return (x < p.x || (x==p.x && y<p.y));
    }
    point operator+(const point &p){
        return point(x + p.x, y+p.y);
    }
    point operator-(const point &p){
        return point(x - p.x, y - p.y);
    }
    long long operator*(const point &p){ //dot product
        return (x*p.x + y*p.y);
    }
    long long operator^(const point &p){ //cross product
        return (x*p.y - y*p.x);
    }
};

bool comp(pair<point, bool> a, pair<point, bool> b){
    return a.first<b.first;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int t;
    cin >> t;
 
    while(t--){
        point a1, a2, b1, b2;
        cin >> a1.x >> a1.y;
        cin >> a2.x >> a2.y;
        cin >> b1.x >> b1.y;
        cin >> b2.x >> b2.y;
        
        point u = a2-a1;
        point v = b2-b1;
        
        point m = b1-a1, n=b2-a1;
        ll cross1 = u ^ m, cross2 = u ^ n;
        bool flag1 = (cross1>0 && cross2<0) || (cross1<0 && cross2>0); 
        
        point p = a1-b1, q=a2-b1;
        ll cross3 = v ^ p, cross4 = v ^ q;
        bool flag2 = (cross3>0 && cross4<0) || (cross3<0 && cross4>0); 
        
        bool resp = 0;

        if( (flag1 && flag2) || 
            (flag1 && (cross3==0 || cross4==0)) || 
            (flag2 && (cross1==0 || cross2==0)) ||
            (a1==b1 || a1==b2 || a2==b1 || a2==b2)){
            
            resp = 1;
        }

        if(cross1==0 && cross2==0 && cross3==0 && cross4==0){
            vector< pair<point, bool> > v;
            
            v.EB(a1, 0);
            v.EB(a2, 0);
            v.EB(b1, 1);
            v.EB(b2, 1);

            sort(v.begin(), v.end(), comp);

            if(v[0].second^v[1].second) resp = 1;
        }
        
        cout << (resp?"YES":"NO") << endl;
    }
 
    return 0;
}