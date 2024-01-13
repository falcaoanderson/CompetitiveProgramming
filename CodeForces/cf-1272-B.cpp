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
        string moves;
        cin >> moves;

        int l=0, r=0, u=0, d=0;
        for(char c: moves){
            if(c=='U') u++;
            if(c=='D') d++;
            if(c=='R') r++;
            if(c=='L') l++;
        }

        u = min(u, d);
        r = min(r, l);
        
        if(u==0 && r>1) r=1;
        if(r==0 && u>1) u=1;

        cout << 2*u+2*r << endl;

        for(int i=0; i<u; i++) cout << "U";
        for(int i=0; i<r; i++) cout << "R";
        for(int i=0; i<u; i++) cout << "D";
        for(int i=0; i<r; i++) cout << "L";
        cout << endl;
    }

    return 0;
}
