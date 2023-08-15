#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)

typedef pair<int, int> pii;

const int MAXN = 1e6;
const int INF = 0x3f3f3f3f;

int group[MAXN];

int main(){
    fast_io;

    int e, m, d;
    cin >> e >> m >> d;

    vector<pii> like, deslike;

    for(int i=0; i<m; i++){
        int a, b;   
        cin >> a >> b;

        like.emplace_back(a, b);
    }

    for(int i=0; i<d; i++){
        int a, b;   
        cin >> a >> b;

        deslike.emplace_back(a, b);
    }

    for(int i=1; i<=e/3; i++){
        int a, b, c;
        cin >> a >> b >> c;

        group[a] = group[b] = group[c] = i;
    }

    int resp = 0;

    for(pii rel: like){
        resp += (int)(group[rel.first]!=group[rel.second]);
    }
    for(pii rel: deslike){
        resp += (int)(group[rel.first]==group[rel.second]);
    }

    cout << resp << endl;

    return 0;
}   