// 06/05/23 //
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

typedef pair<int, int> pii;
typedef tuple<int, int, int> tiii;

const int MAXN = (2e5) + 5;

int bit[3*MAXN], cont=0;

void update(int i, int u){
    while(i<=cont){
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
    
    int n, q;
    cin >> n >> q;
    
    vector<int> salary(n+1);
    vector<int> aux;

    for(int i=1; i<=n; i++){
        cin >> salary[i];
        
        aux.PB(salary[i]);
    }
    
    vector< tuple<char, int, int> > queries;

    for(int i=0; i<q; i++){
        char op; int a, b;
        cin >> op >> a >> b;
        
        queries.emplace_back(op, a , b);

        aux.PB(b);
        if(op=='?') aux.PB(a);;
    }

    cont = 0;
    unordered_map<int, int> compress;
    compress.reserve(4096);
    compress.max_load_factor(0.25);

    sort(aux.begin(), aux.end());
    
    compress[aux[0]] = (++cont);
    for(int i=1; i<(int)aux.size(); i++){
        if(aux[i]!=aux[i-1]) compress[aux[i]] = (++cont);
    }

    for(int i=1; i<=n; i++){
        update(compress[salary[i]], +1);
    }

    for(auto crr_query: queries){
        char op; int a, b;
        tie(op, a, b) = crr_query;

        if(op=='!'){
            update(compress[salary[a]], -1);
            salary[a] = b;
            update(compress[salary[a]], +1);
        }
        else{
            cout << query(compress[b]) - query(compress[a]-1) << endl;
        }
    }

    return 0;
}
