#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

const int MAXN = 2e5+10;
const int SQRTN = 500;
const int INF = 0x3f3f3f3f;

int n, q, sqrtn;
int v[MAXN], bloco[SQRTN];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> q;
    
    sqrtn = sqrt(n);
    for(int i=0; i<=sqrtn+1; i++) bloco[i] = INF;

    for(int i=0; i<n; i++){
        cin >> v[i];
        bloco[i/sqrtn] = min(bloco[i/sqrtn], v[i]);
    }

    while(q--){
        int a, b;
        cin >> a >> b;
        a--; b--;
        int resp = INF;
        
        if(a/sqrtn == b/sqrtn){
            for(int i=a; i<=b; i++) resp = min(resp, v[i]);
        }
        else{
            for(int i=a/sqrtn+1; i<b/sqrtn; i++) resp = min(resp, bloco[i]);
            for(int i=a; i<(a/sqrtn+1)*sqrtn; i++) resp = min(resp, v[i]);
            for(int i= (b/sqrtn)*sqrtn; i<=b; i++) resp = min(resp, v[i]);
        }

        cout << resp << endl;
    }
    
    return 0;
}