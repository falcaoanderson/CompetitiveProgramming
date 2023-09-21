// 21/09/23 //
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
const int MAXN = (2e5) + 5;
const int MOD  = (1e9) + 7;
 
struct Point{
    long long x, y;
    
    Point(){}
    Point(long long x_, long long y_){
        x = x_;
        y = y_;
    }
 
    ll qmod() const{
        return x*x + y*y;
    }
    bool operator==(const Point &p) const{
        return (x==p.x && y==p.y);
    }
    bool operator<(const Point &p) const{
        return (x < p.x || (x==p.x && y<p.y));
    }
    Point operator+(const Point &p) const{
        return Point(x + p.x, y+p.y);
    }
    Point operator-(const Point &p) const{
        return Point(x - p.x, y - p.y);
    }
    long long operator*(const Point &p) const{ //dot product
        return (x*p.x + y*p.y);
    }
    long long operator^(const Point &p) const{ //cross product
        return (x*p.y - y*p.x);
    }
};
 
int main(){
    fast_io;
 
    int n;
    cin >> n;
 
    vector<Point> point(n);
 
    for(int i=0; i<n; i++){
        cin >> point[i].x >> point[i].y;
    }
 
    sort(point.begin(), point.end());
 
    set<Point> window;
    ll qdist = (point[0]-point[1]).qmod();
 
    for(int i=0; i<n; i++){
        ll dist = ceil(sqrt((double)qdist));

        auto start_it = window.upper_bound(Point(point[i].y - dist, 0));
        auto end_it   = window.lower_bound(Point(point[i].y + dist, 0));
        
        Point rev_point = Point(point[i].y, point[i].x);
        vector<set<Point>::iterator> rmv;
    
        for(auto it = start_it; it!=end_it; it++){
            ll crr_dist = (rev_point - (*it)).qmod();
 
            qdist = min(qdist, crr_dist);
            dist = ceil(sqrt((double)qdist));

            if(i<n-1 && point[i+1].x-(*it).y >= dist){ // remover it
                rmv.PB(it);    
            }
        }
 
        for(auto it: rmv){
            window.erase(it);
        }
 
        if(i<n-1 && point[i+1].x-point[i].x<dist){
            window.insert(rev_point);
        }
        else{
            window.clear();
        }
    }
 
    cout << qdist << endl;
 
    return 0;
}