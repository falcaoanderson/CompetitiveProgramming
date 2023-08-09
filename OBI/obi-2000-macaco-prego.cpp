// 09/08/23 //
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

void solve(int n){
    vector<pii> ps, pi;

    int xs=-INF, ys=INF, xi=INF, yi=-INF;

    for(int i=0; i<n; i++){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        xs = max(xs, x1);
        ys = min(ys, y1);
        xi = min(xi, x2);
        yi = max(yi, y2);
    
        ps.EB(x1, y1);
        pi.EB(x2, y2);
    }

    bool flag=(xs<=xi && ys>=yi);

    for(int i=0; i<n && flag; i++){
        int x1=ps[i].ff, y1=ps[i].ss, x2=pi[i].ff, y2=pi[i].ss;

        if(!(x1<=xs && xi<=x2 && y1>=ys && yi>=y2)) flag = 0;
    }

    if(flag){
        cout << xs << " " << ys << " " << xi << " " << yi << endl;
    }
    else{
        cout << "nenhum" << endl;
    }
}

int main(){
    fast_io;

    int n, t=0;
    while(true){
        cin >> n;

        if(n==0) break;

        cout << "Teste " << (++t) << endl;
        solve(n);
        cout << endl;
    }


    return 0;
}
