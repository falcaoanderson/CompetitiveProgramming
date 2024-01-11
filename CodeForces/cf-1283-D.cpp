/*
10/01/24 
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

typedef pair<ll, int> pii;
typedef tuple<int, int, int> tiii;

const int INF  = 0x3f3f3f3f;
const  ll LINF = 0x3f3f3f3f3f3f3f3f;
const int MAXN = (2e5) + 5;
const int MOD  = (1e9) + 7;

int main(){
    fast_io;

    int n, m;
    cin >> n >> m;

    queue<int> fila;
    map<int, int> dist;

    for(int i=1; i<=n; i++){
        int x;
        cin >> x;

        fila.push(x);
        dist[x] = 0;
    }

    ll total=0LL;
    vector<int> resp;

    while(m){
        int u = fila.front(); fila.pop();

        if(dist[u]!=0){
            total += (ll)dist[u];
            resp.PB(u);
            m--;
        }

        if(dist.find(u-1)==dist.end()){
            dist[u-1] = dist[u] + 1;
            fila.push(u-1);
        }
        if(dist.find(u+1)==dist.end()){
            dist[u+1] = dist[u] + 1;
            fila.push(u+1);
        }
    }

    cout << total << endl;
    for(int i: resp) cout << i << " ";
    cout << endl;

    return 0;
}
