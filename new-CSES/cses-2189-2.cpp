// 01/05/23 //
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

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int t;
    cin >> t;

    while(t--){
        point p1, p2, p3;
        cin >> p1.x >> p1.y;
        cin >> p2.x >> p2.y;
        cin >> p3.x >> p3.y;
        
        point v = p2-p1;
        point u = p3-p1;
        
        ll cross = v^u;
        
        if(cross==0){
            cout << "TOUCH" << endl;
        }
        else if(cross<0){
            cout << "RIGHT" << endl;
        }
        else{
            cout << "LEFT" << endl;
        }
    }
 
    return 0;
}
