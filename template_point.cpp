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
#include <functional>
#include <cmath>

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
const  ll LINF = 0x3f3f3f3f3f3f3f3f;
const int MAXN = (2e5) + 5;
const int MOD  = (1e9) + 7;

ll exp(ll a, ll b, ll m=MOD){ // 0^0 = 1
    ll r = 1LL;

    while(b>0LL){
        if(b&1){
            r = (r*a)%m;
            b--;
        }
        else{
            a = (a*a)%m;
            b /= 2LL;
        }
    } 

    return r;
}

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

int main(){
    fast_io;

    return 0;
}
