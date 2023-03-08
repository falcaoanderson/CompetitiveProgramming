// 05/03/20 // 09:54 AM //

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define pb push_back

const int MAXN = (int)1e5 + 10;

int n, m;
vector<int> rel[MAXN];
bool fora[MAXN];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    for(int i=0; i<m; i++){
        int a, b;
        cin >> a >> b;

        rel[a].pb(b);
        rel[b].pb(a);
    }

    vector<int> resp;
    for(int i=n; i>=1; i--){
        if(!fora[i]){
            resp.pb(i);
            for(int j : rel[i]) fora[j] = 1;
        }
    }

    cout << (int)(resp.size()) << endl;
    for(int i : resp) cout << i << " ";
    cout << endl;


    return 0;
}

