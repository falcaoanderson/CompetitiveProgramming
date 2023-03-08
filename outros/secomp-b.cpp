#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define pb push_back
#define mp make_pair
//#define int long long

const int INF  = 0x3f3f3f3f;
const int MAXN = (1e5) + 10;

int main(){
    fast_io;

    int n;

    cin >> n;
    vector<int> v(n), escolhido(n);

    for(int i=0; i<n; i++)cin >> v[i];
    sort(v.begin(), v.end());

    int resp = 0, mresp;
    for(int i=0; i<n; i++){
        if(escolhido[i]) continue;
        escolhido[i] = 1;
        int pos = 0, melhor = INF;

        for(int j=0; j<n; j++){
            int valor = min(abs(v[i]-v[j]), 24-abs(v[i]-v[j]));
            if(!escolhido[j] && valor<melhor){
                melhor = valor;
                pos = j;
            }
        }

        escolhido[pos] = 1;
        resp += melhor;
    }

    cout << resp << endl;

    return 0;
}

