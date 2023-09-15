// 15/09/23 //
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
typedef tuple<int, int, int, int> tiiii;

const int MAXN = (2e5);

int bit[MAXN + 5];

void update(int pos, int val){
    while(pos<=MAXN){
        bit[pos] += val;
        pos += (pos&-pos);
    }
}

int query(int pos){
    int sum = 0;

    while(pos>0){
        sum += bit[pos];
        pos -= (pos&-pos);
    }

    return sum;
}

int main(){
    fast_io;

    int n;
    cin >> n;

    vector<tiiii> event;
    vector<int> y_comp;

    for(int i=0; i<n; i++){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        if(x1==x2){ // vertical
            if(y1>y2) swap(y1, y2);

            event.EB(x1, y1, y2, 0);
        
            y_comp.PB(y1);
            y_comp.PB(y2);
        }
        else{ // horizontal
            if(x1>x2) swap(x1, x2);

            event.EB(x1, y1, y1, 1);
            event.EB(x2, y1, y1, 2);

            y_comp.PB(y1);
        }
    }
    
    sort(y_comp.begin(), y_comp.end());
    int aux=0;
    unordered_map<int, int> y_map;

    for(int i=0; i<(int)y_comp.size(); i++){
        if(i==0 || y_comp[i]!=y_comp[i-1]){
            y_map[y_comp[i]] = ++aux;
        }
    }

    sort(event.begin(), event.end());

    ll resp = 0;

    for(tiiii e: event){
        int y1, y2, op;
        tie(ignore, y1, y2, op) = e;

        y1 = y_map[y1];
        y2 = y_map[y2];

        if(op==0){
            resp += (ll)(query(y2)-query(y1));
        }
        else if(op==1){
            update(y1, 1);
        }
        else{
            update(y2, -1);
        }
    }

    cout << resp << endl;

    return 0;
}
