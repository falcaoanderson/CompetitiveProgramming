// 30/04/23 //
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
 
typedef pair<int, int> pii;
typedef tuple<int, int, int> tiii;
 
const ll MOD = 1e9+7;
const int MAXN = 1e6+5;
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int t;
    cin >> t;
    /*
    double cross(point a, point b){
        return a.x*b.y - a.y*b.x;
    }
    */
    while(t--){
        ll x1, x2, x3;
        ll y1, y2, y3;
        cin >> x1 >> y1;
        cin >> x2 >> y2;
        cin >> x3 >> y3;
        
        ll v_x = x2-x1;
        ll v_y = y2-y1;
        
        ll u_x = x3-x1;
        ll u_y = y3-y1;
        
        ll cross = v_x*u_y - v_y*u_x;
        
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
