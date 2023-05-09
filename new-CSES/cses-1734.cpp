// 09/05/23 //
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

using namespace std;

#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define PB push_back
#define ll long long
#define ff first
#define ss second

typedef pair<int, int> pii;
typedef tuple<int, int, int> tiii;

const int MAXN = (2e5) + 5;

int n;
int bit[MAXN];

void update(int i, int u){
    while(i<=n){
        bit[i] += u;
        i += (i&-i);
    }
}
int query(int i){
    int sum=0;
    while(i>=1){
        sum += bit[i];
        i -= (i&-i);
    }
    return sum;
}

int main(){
    fast_io;

    int q;
    cin >> n >> q;

    vector<int> v(n+1), aux(n);
    for(int i=1; i<=n; i++){
        cin >> v[i];    
        aux[i-1] = v[i]; 
    }

    // compressao de valores
    sort(aux.begin(), aux.end());
    unordered_map<int, int> compress;
    int cont=0;
    for(int i=0; i<n; i++){
        if(i==0 || aux[i]!=aux[i-1]){
            compress[aux[i]] = (++cont);
        }
    }
    for(int i=1; i<=n; i++) v[i] = compress[v[i]];
    // ----------------------

    vector<int> prox(n+1);
    aux.clear(); aux.resize(n+1);

    for(int i=1; i<=n; i++){
        if(aux[v[i]]!=0){
            prox[ aux[v[i]] ] = i;
        }
        aux[v[i]] = i;
    }
    
    vector<int> distinct(n+1);
    aux.clear(); aux.resize(n+1);

    for(int i=1; i<=n; i++){
        if(aux[v[i]]==0) distinct[i] = 1;
        aux[v[i]] = 1;

        update(i, distinct[i]);   
    }

    vector<tiii> queries(q);
    for(int i=0; i<q; i++){
        int a, b;
        cin >> a >> b;
        queries[i] = tie(a, b, i);
    }
    sort(queries.begin(), queries.end());

    int left=1;
    vector<int> resp(q);
    for(tiii qq: queries){
        int a, b, ind;
        tie(a, b, ind) = qq;

        while(left<a){
            update(left, -1);
            if(prox[left]!=0) update(prox[left], +1);
            left++;
        }

        resp[ind] = query(b); 
    }

    for(int i: resp) cout << i << endl;

    return 0;   
}
