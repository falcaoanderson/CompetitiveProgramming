// 22/11/20 // xx:xx PM //

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define pb push_back
#define mp make_pair
#define ll long long

typedef pair<int, int> pii;

const int MAXN = (2e5) + 10;

int n, q, v[MAXN], last_pos[MAXN], resp[MAXN];
int bit[MAXN];
vector<pair<pii, int>> querys;

void update(int i, int sum){
    while(i<=n){
        bit[i] += sum;
        i += (i&-i);
    }
}
int query(int i){
    int sum = 0;
    while(i>0){
        sum += bit[i];
        i -= (i&-i);
    }
    return sum;
}

int main(){
    fast_io;

    cin >> n >> q;
    for(int i=1; i<=n; i++) cin >> v[i];

    for(int i=1; i<=q; i++){
        int a, b;
        cin >> a >> b;

        querys.pb({{b, a}, i});
    }   

    sort(querys.begin(), querys.end());
    
    map<int, int> compress;
    int ii=0;
    for(int i=1; i<=n; i++) compress[v[i]]=0;
    for(auto i: compress) compress[i.first] = ++ii;
    for(int i=1; i<=n; i++) v[i] = compress[v[i]];

    int last_b = 0;

    for(auto qq: querys){
        int a = qq.first.second, b = qq.first.first, id = qq.second;

        for(int i=last_b+1; i<=b; i++){
            update(i, 1);

            if(last_pos[v[i]]!=0) update(last_pos[v[i]], -1);
            
            last_pos[v[i]] = i;
        }

        resp[id] = query(b) - query(a-1);

        last_b = b;
    }

    for(int i=1; i<=q; i++) 
        cout << resp[i] << endl;

    return 0;
}
