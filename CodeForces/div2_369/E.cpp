/*
14/02/26 

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
const int MAXN = (9e5) + 5, MAXX = 1e6;
const int MOD  = (1e9) + 7;

int st[MAXN], ed[MAXN];
int seg[MAXN], sz_seg, qnt[MAXN];
int bit[MAXX+5];

void update(int x, int delta = 1){
    while(x <= MAXX){
        bit[x] += delta;
        x += (x & (-x));
    }
}
int query(int x){
    int sum = 0;
    while(x > 0){
        sum += bit[x];
        x -= (x & (-x));
    }
    return sum;
}

int main(){
    fast_io;

    int n, m;
    cin >> n >> m;
    for(int i=0; i<n; i++){
        cin >> st[i] >> ed[i];
        seg[i] = i;
    }
    sz_seg = n;

    vector<vector<int>> queries(m);

    for(int i=0; i<m; i++){
        int cnt;
        cin >> cnt;
        
        int prev = 1;
        for(int j=0; j<cnt; j++){
            int x;
            cin >> x;
            
            if(prev <= x-1){
                st[sz_seg] = prev;
                ed[sz_seg] = x-1;
                seg[sz_seg] = sz_seg;
                queries[i].PB(sz_seg);
                sz_seg++;
            }

            prev = x + 1;
        }

        if(prev <= MAXX){
            st[sz_seg] = prev;
            ed[sz_seg] = MAXX;
            seg[sz_seg] = sz_seg;
            queries[i].PB(sz_seg);
            sz_seg++;
        }
    }

    sort(seg, seg+sz_seg, 
        [](int a, int b){
            return st[a] > st[b] || (st[a] == st[b] &&  ed[a] < ed[b]) || (st[a] == st[b] &&  ed[a] == ed[b] && a < b);
        }
    );

    for(int i=0; i<sz_seg; i++){
        int id = seg[i], b = ed[id];
        
        if(id >= n){
            qnt[id] = query(b);
        }
        else{
            update(b);
        }
    }

    for(int i=0; i<m; i++){
        int ans = n;
        for(int id: queries[i]) ans -= qnt[id];
        
        cout << ans << endl;
    }

    return 0;
}
