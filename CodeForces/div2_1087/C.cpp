/*
24/10/25 

*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define PB push_back
#define EB emplace_back
#define FF first
#define SS second
#define SZ(x) (int)(x).size()

typedef pair<int, int> pii;
typedef tuple<int, int, int> tiii;

const int INF  = 0x3f3f3f3f;
const  ll LINF = 0x3f3f3f3f3f3f3f3f;
const int MAXN = (2e5) + 5;
const int MOD  = (1e9) + 7;

bool cmpy(pii a, pii b){
    return a.SS < b.SS;
}

int main(){
    fast_io;

    vector<pii> p(3);
    for(int i=0; i<3; i++){
        cin >> p[i].FF >> p[i].SS;
    }
    sort(p.begin(), p.end(), cmpy);
    
    vector<pii> resp(p);
    
    while(p[0].SS < p[1].SS){
        p[0].SS++;
        if(p[0]!=p[1] && p[0]!=p[2]) resp.PB(p[0]);
    }
    while(p[2].SS > p[1].SS){
        p[2].SS--;
        if(p[2]!=p[1] && p[2]!=p[0]) resp.PB(p[2]);
    }

    sort(p.begin(), p.end());

    while(p[0].FF < p[2].FF){
        p[0].FF++;
        if(p[0]!=p[1] && p[0]!=p[2]) resp.PB(p[0]);
    }

    cout << resp.size() << endl;
    for(pii x: resp){
        cout << x.FF << " " << x.SS << endl;
    }

    return 0;
}
