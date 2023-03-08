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

set<int> v;

void solve(){
    v.clear();

    int n;
    cin >> n;

    for(int i=0; i<n; i++){
        int temp;
        cin >> temp;
        v.insert(temp);
    }

    int resp = 0;

    while(!v.empty()){
        int atual = *v.rbegin();
        v.erase(atual);

        if(~atual&1){
            v.insert(atual >> 1);
            resp++;
        }
    }

    cout << resp << endl;
}

int main(){
    fastio;

    int t;
    cin >> t;

    while(t--) solve();

    return 0;
}
