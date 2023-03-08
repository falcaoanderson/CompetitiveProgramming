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

    vector<string> v(n);
    map<string, int> dic;

    for(int i=0; i<n; i++){
        cin >> v[i];
        dic[v[i]]++;
    }

    int cont = 0;

    for(string &pin : v){
        if(dic[pin]>1){
            for(char i='0'; i<='9'; i++){
                string tpin = pin;
                tpin[0] = i;

                if(dic[tpin]==0){
                    dic[tpin]++;
                    dic[pin]--;
                    pin[0]=i;
                    cont++;
                    break;
                }
            }
        }
    }

    cout << cont << endl;
    for(string pin : v)
        cout << pin << endl;
}

int main(){
    fastio;

    int t;
    cin >> t;

    while(t--) solve();

    return 0;
}
