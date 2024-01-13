/*
12/01/24 
Problem: 
Complexity:
*/

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
#define FF first
#define SS second

typedef pair<int, int> pii;
typedef tuple<int, int, int> tiii;

const int INF  = 0x3f3f3f3f;
const  ll LINF = 0x3f3f3f3f3f3f3f3f;
const int MAXN = (2e5) + 5;
const int MOD  = (1e9) + 7;

int main(){
    fast_io;

    int t;
    cin >> t;

    while(t--){
        vector<int> v(3);
        cin >> v[0] >> v[1] >> v[2];

        sort(v.begin(), v.end());

        if(v[0]==v[1] && v[1]==v[2]){
            cout << 0 << endl;
        }
        else if(v[0]==v[1]){
            if(v[2]==v[1]+1){
                cout << 0 << endl;
            }
            else{
                cout << (v[2]-v[1]-2)*2 << endl;
            }
        }
        else if(v[1]==v[2]){
            if(v[0]+1==v[1]){
                cout << 0 << endl;
            }
            else{
                cout << (v[1]-v[0]-2)*2 << endl;
            }
        }
        else{
            v[0]++; v[2]--;
            cout << v[2]-v[1] + v[2]-v[0] + v[1]-v[0] << endl;
        }
    }

    return 0;
}
