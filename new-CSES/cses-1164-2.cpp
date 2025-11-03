/*
15/09/25 

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

int main(){
    fast_io;

    int n;
    cin >> n;
    
    vector< pair<pii, int> > v(n);
    for(int i=0; i<n; i++){
        cin >> v[i].FF.FF >> v[i].FF.SS;
        v[i].SS = i;
    }

    sort(v.begin(), v.end());

    int rooms = 0;
    vector<int> resp(n);
    priority_queue<pii, vector<pii>, greater<pii>> fila;

    for(auto e: v){
        if(fila.empty() || fila.top().FF>=e.FF.FF){
            fila.push({e.FF.SS, ++rooms});
            resp[e.SS] = rooms;
        }
        else{
            pii aux = fila.top(); fila.pop();
            aux.FF = e.FF.SS;
            fila.push(aux);
            resp[e.SS] = aux.SS;
        }
    }

    cout << rooms << endl;
    for(int x: resp){
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
