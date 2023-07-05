// 23/06/23 (tentativa 1) // 05/07/23 (tentativa 2) //
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
const int MAXN = (5e4) + 5;
const int LIMIT = 1e9;

int year[MAXN], rain[MAXN];
int seg[3*MAXN];

void build(int node, int i, int j){
    if(i==j){
        seg[node] = rain[i];
        return;
    }
    int l=2*node, r=2*node+1, mid=(i+j)/2;

    build(l,     i, mid);
    build(r, mid+1,   j);

    seg[node] = max(seg[l], seg[r]);
}
int query(int node, int i, int j, int a, int b){
    if(a>b) return -1;

    if(j < a || b < i){
        return -INF;
    }
    if(a<=i && j<=b){
        return seg[node];
    }

    int l=2*node, r=2*node+1, mid=(i+j)/2;

    return max(query(l, i, mid, a, b), query(r, mid+1, j, a, b));
}

void solve(int n){
    map<int, int> id;

    for(int i=1; i<=n; i++){
        cin >> year[i] >> rain[i];

        id[year[i]] = i; 
    }

    build(1, 1, n);

    int m;
    cin >> m;

    while(m--){
        int x, y;
        cin >> y >> x;

        auto it_x = id.upper_bound(x); 
        if(it_x==id.begin()){
            cout << "maybe" << endl;
            continue;
        }
        it_x--;  //maior cara <= y
        auto it_y = id.lower_bound(y); //menor cara >= x
        if(it_y==id.end()){
            cout << "maybe" << endl;
            continue;
        }


        if(x-y == (it_x->second)-(it_y->second)){ //possui todos os dados // true or false
            x = (it_x -> second);
            y = (it_y -> second);

            if(rain[y]>=rain[x] && query(1, 1, n, y+1, x-1)<rain[x]){
                cout << "true" << endl;
            }
            else{
                cout << "false" << endl;
            }
        }
        else{ // nao possui todos os dados // maybe or false
            if((it_x->first)!=x && (it_y->first)!=y){ // o x e y nao estao no map
                cout << "maybe" << endl;
            }
            else if((it_y->first)!=y){ // o x esta no map e o y nao
                x = (it_x -> second);
                y = (it_y -> second);

                if(query(1, 1, n, y, x-1)<rain[x]){
                    cout << "maybe" << endl;
                }
                else{
                    cout << "false" << endl;
                }
            }
            else if((it_x->first)!=x){ // o y esta no map e o x nao 
                x = (it_x -> second);
                y = (it_y -> second);

                if(query(1, 1, n, y+1, x)<rain[y]){
                    cout << "maybe" << endl;
                }
                else{
                    cout << "false" << endl;
                }
            }
            else{
                x = (it_x -> second);
                y = (it_y -> second);

                if(rain[y]>=rain[x] && query(1, 1, n, y+1, x-1)<rain[x]){
                    cout << "maybe" << endl;
                }
                else{
                    cout << "false" << endl;
                }
            }
        }
     }
}
int main(){
    fast_io;

    while(true){
        int n;
        cin >> n;

        if(n==0){
            cin >> n;
            break;
        }

        solve(n);
        cout << endl;
    }

    return 0;
}