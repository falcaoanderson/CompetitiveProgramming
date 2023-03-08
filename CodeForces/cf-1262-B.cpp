// 00/00/20 // 00:00 XX //

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define pb push_back
#define mp make_pair
#define ff first
#define ss second

const int INF = 0x3f3f3f3f;
const int MAXN = 1e5 + 10;

bool added[MAXN];

void solve(){
    memset(added, 0, sizeof(added));
    int n, atual, anterior=-1, menor=1;
    vector<int> resp;

    cin >> n;

    for(int i=1; i<=n; i++){
        cin >> atual;


        if(added[0]) continue;

        if(atual > anterior){
            resp.pb(atual);
            added[atual] = 1;
        }
        else{
            while(added[menor]) menor++;

            if(menor > atual){
                resp = {-1};
                added[0]=1;
                continue;
            }

            resp.pb(menor);
            added[menor] = 1;
        }

        anterior = atual;
    }

    for(int i : resp) cout << i << " ";
    cout << endl;
}

int main(){
    fastio;

    int t;
    cin >> t;

    while(t--) solve();

    return 0;
}
