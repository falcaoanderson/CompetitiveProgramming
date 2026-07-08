/*
20/04/26 

My idea
Number of queries <= 2 * log2(2*n+1) + 1
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

int cnt_query = 0;
map<set<int>, int> memo_query;
int n;

int len(pii a){
    return a.SS - a.FF + 1;
}
int len(vector<pii>& vp){
    int s = 0;
    for(pii p: vp) s += p.SS - p.FF + 1;
    return s;
}

int query(set<int> &qset){
    if(qset.empty() || SZ(qset)==n) return 0;
    if(SZ(qset)==1) return 1;
    if(memo_query.find(qset) != memo_query.end()) return memo_query[qset];

    cout << "? " << qset.size() << " ";
    for(int x: qset) cout << x << " ";
    cout << endl;
    cnt_query++;

    int ans_q;
    cin >> ans_q;
    if(ans_q == -1) exit(0);
    return memo_query[qset] = ans_q;
}

int query(pii itv1, pii itv2 = {0, -1}){
    set<int> aux;
    for(int i=itv1.FF; i<=itv1.SS; i++) aux.insert(i);
    for(int i=itv2.FF; i<=itv2.SS; i++) aux.insert(i);
    return query(aux);
}

int query(pii itv1, pii itv2, vector<pii> &vz){
    set<int> aux;
    for(int i=itv1.FF; i<=itv1.SS; i++) aux.insert(i);
    for(int i=itv2.FF; i<=itv2.SS; i++) aux.insert(i);
    for(pii p: vz)
        for(int i=p.FF; i<=p.SS; i++)
            aux.insert(i);
    return query(aux);
}

int query(pii itv, vector<pii> &vz){
    set<int> aux;
    for(int i=itv.FF; i<=itv.SS; i++) aux.insert(i);
    for(pii p: vz)
        for(int i=p.FF; i<=p.SS; i++)
            aux.insert(i);
    return query(aux);
}

int query(vector<pii> &vz){
    if(vz.empty() || SZ(vz) == n) return 0;
    if(SZ(vz) == 1) return 1;
    
    set<int> aux;
    for(pii p: vz)
        for(int i=p.FF; i<=p.SS; i++)
            aux.insert(i);
    return query(aux);
}

void find_one_two(pii& itv_one, vector<pii>& itv_two, vector<pii>& vz){
    while(len(itv_one) > 1){
        int l = itv_one.FF, r = itv_one.SS, mid = (l+r) / 2;
        
        pii itv_l = {l, mid}, itv_r = {mid+1, r}, itv_z = {0, 0};

        if(((len(itv_l) + len(itv_two)) - query(itv_l, itv_two)) & 1){
            itv_one = itv_l;
            itv_z = itv_r;
        }
        else{
            itv_one = itv_r;
            itv_z = itv_l;
        }
        vz.PB(itv_z);
    }
}

void solve(){
    cin >> n;
    n = 2*n + 1;

    cnt_query = 0;
    memo_query.clear();
    vector<pii> pos = {{1, n}, {1, n}, {1, n}}, vz;
    
    // Parte 1: (3) --> (1), (2), (0)
    while(pos[0] == pos[1]){
        int l = pos[0].FF, r = pos[0].SS, mid = (l+r) / 2;

        pii itv_l = {l, mid}, itv_r = {mid+1, r};
    
        int a_lr = query(pos[0]);
        int a_l = query(itv_l), a_r = query(itv_r);
        
        if((a_l + a_r + a_lr) & 1){
            int a_lz = query(itv_l, vz);
            
            if(a_r < a_lz){ // (1L, 2R)
                pos[0] = itv_l;
                pos[1] = pos[2] = itv_r;
            }
            else{ // (2L, 1R)
                pos[0] = itv_r;
                pos[1] = pos[2] = itv_l;
            }
            break;
        }
        else{
            pii itv_z;

            if((len(itv_l) - a_l) & 1){ // (3L, 0R)
                pos[0] = pos[1] = pos[2] = itv_l;
                itv_z  = itv_r;
                a_lr = a_l;
            }
            else{ // (0L, 3R)
                pos[0] = pos[1] = pos[2] = itv_r;
                itv_z  = itv_l;
                a_lr = a_r;
            }
            
            vz.PB(itv_z);
        }
    }

    // parte 2: (1), (2), (0) ---> (1)*, (2), (0)
    vector<pii> itv_two = {pos[1]};
    find_one_two(pos[0], itv_two, vz);

    // parte 3: (1)*, (2), (0) --> (1)*, (1), (1), (0)
    while(pos[1] == pos[2]){
        int l = pos[1].FF, r = pos[1].SS, mid = (l+r) / 2;
        pii itv_l = {l, mid}, itv_r = {mid+1, r}, itv_z = {0, 0};

        int a_l = query(pos[0], itv_l), a_r = query(itv_r, vz);
        
        if(a_l == a_r){ // (3L, 0R) ==> (2L, 0R)
            pos[1] = pos[2] = itv_l;
            itv_z  = itv_r;    
        }
        else if(a_l < a_r){ // (2L, 1R) ==> (1L, 1R)
            pos[1] = itv_l;
            pos[2] = itv_r;
        }
        else{ // (1L, 2R) ==> (0L, 2R)
            pos[1] = pos[2] = itv_r;
            itv_z = itv_l;
        }

        vz.PB(itv_z);
    }

    // parte 4: (1)*, (1), (1), (0) ---> (1)*, (1)*, (1)*, (0)
    // 4.1
    itv_two.clear();
    itv_two.PB(pos[0]);
    itv_two.PB(pos[2]);
    find_one_two(pos[1], itv_two, vz);
    // 4.2
    itv_two.clear();
    itv_two.PB(pos[0]);
    itv_two.PB(pos[1]);
    find_one_two(pos[2], itv_two, vz);

    // resposta
    cout << "! ";
    for(int i=0; i<3; i++) cout << pos[i].FF << " ";
    cout << endl; 

    // cout << "cnt_query: " << cnt_query << endl;
}

int main(){
    // fast_io;

    int t=1;
    cin >> t;
    while(t--){
        solve();
    }

    return 0;
}
