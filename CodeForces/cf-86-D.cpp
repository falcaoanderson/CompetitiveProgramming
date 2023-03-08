// 12/04/21 // 13:01 PM //

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define ll long long

int block;
struct Query{
    int l=0, r=0, id=0;
    
    inline pair<int, int>  toPair() const{
        return make_pair(l/block, ((l/block)&1 ? -r : +r) );
    }
};

inline bool operator<(const Query &a, const Query &b){
    return a.toPair() < b.toPair();
}

const int MAXN = 2e5+10;

int n, t;
ll v[MAXN];
Query querys[MAXN];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> t;
    for(int i=0; i<n; i++) cin >> v[i];

    for(int i=0; i<t; i++){
        cin >> querys[i].l >> querys[i].r;

        querys[i].l--;
        querys[i].r--;
        querys[i].id = i;
    }

    block = sqrt(n);
    sort(querys, querys+t);

    vector<ll> resp(t, 0LL);
    //vector<int> freq(1e6+1, 0);
    unordered_map<int,int> freq; freq.reserve(1<<20);
    
    int cl=querys[0].l, cr=querys[0].l;
    ll cresp = v[ querys[0].l ];
    freq[ v[ querys[0].l ] ] = 1;

    for(int i=0; i<t; i++){
        while(cl < querys[i].l){ 
            freq[v[cl]]--;
            cresp += v[cl] * (-2LL * (ll)freq[v[cl]] - 1LL);

            cl++; 
        }
        while(cl > querys[i].l){
            cl--;

            freq[v[cl]]++;
            cresp += v[cl] * (2LL * (ll)freq[v[cl]] - 1LL);
        }
        while(cr > querys[i].r){
            freq[v[cr]]--;
            cresp += v[cr] * (-2LL * (ll)freq[v[cr]] - 1LL);

            cr--;
        }
        while(cr < querys[i].r){
            cr++;
            
            freq[v[cr]]++;
            cresp += v[cr] * (2LL * (ll)freq[v[cr]] - 1LL);
        }

        resp[querys[i].id] = cresp;
    }

    for(int i=0; i<t; i++) cout << resp[i] << endl;

    return 0;
}