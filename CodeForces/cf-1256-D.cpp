/*
17/01/24 
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

    int q;
    cin >> q;

    while(q--){
        int n;
        ll moves;
        cin >> n >> moves;

        string s;
        cin >> s;

        vector<int> v;
        v.PB(0);

        for(int i=0; i<n; i++){
            if(s[i]=='0') v.PB(i+1);
        }
        
        int sz = v.size();

        for(int i=1; i<sz && moves>0LL; i++){
            int aux = (int)min(moves, (ll)(v[i]-v[i-1]-1));
            v[i] -= aux;
            moves -= (ll)aux;
        }

        for(int i=1; i<sz; i++){
            for(int j=0; j<v[i]-v[i-1]-1; j++) cout << 1;
            cout << 0;
        }
        for(int j=0; j<n-v[sz-1]; j++) cout << 1;
        cout << endl;
    }

    return 0;
}
