/*
20/01/26

*/
#include <bits/stdc++.h>

using namespace std;

#define fast_io ios_base::sync_with_stdio(false);cin.tie(nullptr)
#define endl "\n"
#define FF first
#define SS second
#define PB push_back
#define EB emplace_back

using ll = long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;

// const int MAXVAL = 1e3 + 5;
const int MAXN = 1e3 + 5;

int main(){
    fast_io;

    int n;
    cin >> n;

    vector<int> v(n+1);
    for(int i=1; i<=n; i++){
        cin >> v[i];
    }

    bool resp = 0;
    for(int i=1; i<=n && !resp; i++){
        if(v[v[v[i]]] == i) resp = 1;
    }

    cout << (resp? "YES": "NO") << endl;

    return 0;
}