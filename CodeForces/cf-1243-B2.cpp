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
const int MAXN = 80;

int cont[MAXN];

void solve(){
    int n;
    string s, t;

    cin >> n >> s >> t;

    memset(cont, 0, sizeof(cont));
    for(int i=0; i<n; i++){
        cont[s[i]-'0']++;
        cont[t[i]-'0']++;
    }
    for(int i=49; i<=74; i++){
        if(cont[i]&1){
            cout << "No\n";
            return;
        }
    }

    int cresp=0;
    vector<pair<int, int>> resp;

    for(int i=0; i<n; i++){
        if(s[i]!=t[i]){

            int ops=-1, opt=-1;

            for(int j=i+1; j<n; j++){
                if(s[i]==s[j]){
                    ops = j;
                    break;
                }
                if(s[i]==t[j]){
                    opt = j;
                }
            }

            if(ops!=-1){
                swap(s[ops], t[i]);
                cresp++;
                resp.pb(mp(ops, i));
            }
            else{
                swap(s[i], t[i]);
                resp.pb(mp(i, i));

                swap(s[i], t[opt]);
                resp.pb(mp(i, opt));

                cresp+=2;
            }

        }
    }

    cout << "Yes\n" << cresp << endl;
    for(auto i : resp) cout << i.ff+1 << " " << i.ss+1 << endl;

}

int main(){
    fastio;

    int t;
    cin >> t;
    while(t--) solve();

    return 0;
}
