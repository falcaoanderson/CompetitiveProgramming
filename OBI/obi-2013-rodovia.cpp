// 13/06/20 // 08:02 PM //

#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define endl "\n"
//#define int long long

const int INF  = 0x3f3f3f3f;
const int MAXN = (1e4) + 10;

int n;
vector<int> grafo[MAXN];
bool visitado[MAXN];

bool dfs(int no){
    visitado[no] = true;

    for(int adj: grafo[no]){
        if(!visitado[adj])
            return dfs(adj);
        else if(adj == 1)
            return 1;
    }

    return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i=0; i<n; i++){
        int a, b;
        cin >> a >> b;

        grafo[a].pb(b);

        if(grafo[a].size()>1){
            cout << "N" << endl;
            return 0;
        }
    }

    bool c1 = dfs(1), c2=true;

    for(int i=1; i<=n; i++)
        if(!visitado[i]){
            c2 = false;
            break;
        }

    if(c1 && c2) cout << "S" << endl;
    else         cout << "N" << endl;

    return 0;
}

