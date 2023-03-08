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

void solve(){
    int n;
    cin >> n;
    vector<int> v(n);
    for(int& i : v) cin >> i;

    int dias=1, qnt_op=0;
    set<int> dentro, entrou;
    vector<int> resp;

    for(int atual : v){

        if(dentro.empty() && qnt_op>0){
            resp.pb(qnt_op);
            dias++;
            qnt_op=0;
            entrou.clear();
        }

        if(atual>0){
            if(entrou.find(atual)!=entrou.end()){ // novo dia
                if(!dentro.empty()){
                    dias = -1;
                    break;
                }

                resp.pb(qnt_op);
                dias++;
                qnt_op=0;
                entrou.clear();
            }

            entrou.insert(atual);
            dentro.insert(atual);
            qnt_op++;
        }
        else{
            atual *= -1;

            if(dentro.find(atual)==dentro.end()){
                dias = -1;
                break;
            }

            dentro.erase(atual);
            qnt_op++;
        }
    }

    if(dentro.empty() && dias!=-1)
        resp.pb(qnt_op);
    else{
        dias = -1;
        resp.clear();
    }

    cout << dias << endl;
    if(dias>-1){
        for(int i : resp) cout << i << " ";
        cout << endl;
    }
}

int main(){
    fastio;

    solve();

    return 0;
}
