// 16/06/23 //
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
#include <stack>

using namespace std;

#define ll long long
#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define PB push_back
#define EB emplace_back
#define ff first
#define ss second

typedef pair<int, int> pii;
typedef tuple<int, int, int> tiii;

const int INF  = 0x3f3f3f3f;
const int MAXN = (2e5) + 5;
const int MOD  = (1e9) + 7;

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

ll exp(ll a, ll b, ll m=MOD){
    if(b==0) return 1LL;

    if(b&1) return (a*exp(a, b-1, m))%m;
    return exp((a*a)%m, b/2, m)%m;
}

int main(){
    fast_io;

    return 0;
}
