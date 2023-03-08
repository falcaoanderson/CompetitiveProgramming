// 09/04/21 // 1:20 PM //

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define ll long long

const int MAXN = 2e5+10;
const int SQRTN = 500;

int n, q, sqrtn;
ll v[MAXN], bloco[SQRTN];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> q;

    sqrtn = sqrt(n);

    for(int i=0; i<n; i++){
        cin >> v[i];
        bloco[i/sqrtn] += v[i];
    }

    while(q--){
        int a, b;
        cin >> a >> b;
        a--; b--;
        ll sum = 0;
        
        if(a/sqrtn == b/sqrtn){
            for(int i=a; i<=b; i++) sum += v[i];
        }
        else{
            for(int i=a/sqrtn+1; i<b/sqrtn; i++) sum += bloco[i];
            for(int i=a; i<(a/sqrtn+1)*sqrtn; i++) sum += v[i];
            for(int i= (b/sqrtn)*sqrtn; i<=b; i++) sum += v[i];
        }

        cout << sum << endl;
    }
    
    return 0;
}