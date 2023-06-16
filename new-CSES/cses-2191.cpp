// 16/05/23 //
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
 
struct Point{
    long long x, y;
    
    Point(){}
    Point(long long x_, long long y_){
        x = x_;
        y = y_;
    }
 
    ll qmod(){
        return x*x + y*y;
    }
    bool operator==(const Point &p){
        return (x==p.x && y==p.y);
    }
    bool operator<(const Point &p){
        return (x < p.x || (x==p.x && y<p.y));
    }
    Point operator+(const Point &p){
        return Point(x + p.x, y+p.y);
    }
    Point operator-(const Point &p){
        return Point(x - p.x, y - p.y);
    }
    long long operator*(const Point &p){ //dot product
        return (x*p.x + y*p.y);
    }
    long long operator^(const Point &p){ //cross product
        return (x*p.y - y*p.x);
    }
};
 
bool comp(pair<Point, bool> a, pair<Point, bool> b){
    return a.first<b.first;
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int n;
    cin >> n;

    vector<Point> p(n);
    for(int i=0; i<n; i++){
        cin >> p[i].x >> p[i].y;
    }
    p.EB(p[0].x, p[0].y);

    ll a=0LL;
    for(int i=0; i<n; i++){
        a += p[i] ^ p[i+1];
    }

    cout << abs(a) << endl;

    return 0;
}