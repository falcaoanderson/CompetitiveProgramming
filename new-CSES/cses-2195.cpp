// 23/09/23 //
// Problem: Convex Hull (CSES)

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
    bool operator<(const Point &p) const{
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

    int n;
    cin >> n;

    vector<Point> v(n);
    for(int i=0; i<n; i++){
        cin >> v[i].x >> v[i].y;
    }

    sort(v.begin(), v.end());

    int sz=0;
    vector<Point> upper, lower;

    for(Point p: v){
        if(sz<2){
            upper.PB(p);
            sz++;
        }
        else{
            while(sz>=2 && ((upper[sz-2]-upper[sz-1])^(p-upper[sz-1]))<0LL){
                upper.pop_back();
                sz--;
            }

            upper.PB(p);
            sz++;
        }
    }

    sz=0;
    for(Point p: v){
        if(sz<2){
            lower.PB(p);
            sz++;
        }
        else{
            while(sz>=2 && ((lower[sz-2]-lower[sz-1])^(p-lower[sz-1]))>0LL){
                lower.pop_back();
                sz--;
            }

            lower.PB(p);
            sz++;
        }
    }

    set<Point> convex_hull;

    for(Point p: upper) convex_hull.insert(p);
    for(Point p: lower) convex_hull.insert(p);

    cout << convex_hull.size() << endl;
    for(Point p: convex_hull){
        cout << p.x << " " << p.y << endl;
    }

    return 0;
}
