/*
19/01/26

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

const int MAXVAL = 1e6 + 5;
const int MAXN = 3e4 + 5;

int n;
int last[MAXVAL], bit[MAXN];

int query(int i){
    int sum = 0;
    while(i>0){
        sum += bit[i];
        i -= (i & (-i));
    }
    return sum;
}
void update(int i, int delta){
    while(i<=n){
        bit[i] += delta;
        i += (i & (-i));
    }
}

int main(){
    fast_io;

    cin >> n;

    vector<int> v(n+1);
    for(int i=1; i<=n; i++){
        cin >> v[i];
    }

    vector< pair<pii, int> > queries;
    int q;
    cin >> q;

    for(int i=0; i<q; i++){
        int a, b;
        cin >> a >> b;
        queries.push_back({{b, a}, i});
    }

    sort(queries.begin(), queries.end());

    vector<int> resp(q);
    int r = 0;

    for(int i=0; i<q; i++){
        int id = queries[i].SS;
        int a = queries[i].FF.SS, b = queries[i].FF.FF;

        for(int j=r+1; j<=b; j++){
            if(last[v[j]]!=0){
                update(last[v[j]], -1);
            }
            last[v[j]] = j;
            update(j, 1);
        }
        r = b;

        resp[id] = query(b) - query(a-1);
    }

    for(int i=0; i<q; i++) cout << resp[i] << endl;
    
    return 0;
}