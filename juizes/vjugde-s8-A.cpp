// 20/07/23 //
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <tuple>
#include <cstring>
#include <stack>

using namespace std;

#define ll long long
#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define PB push_back
#define EB emplace_back
#define ff first
#define ss second

typedef pair<int, int> pii;
typedef tuple<int, int, int> tiii;

void solve(){
    ll n, a, b;
    cin >> n >> a >> b;

    string s;
    cin >> s;

    vector<int> v;
    int crr=1;

    for(int i=1; i<n; i++){
        if(s[i]==s[i-1]) crr++;
        else{
            v.PB(crr);
            crr = 1;
        }
    }
    v.PB(crr);

    bool cima=0;
    ll resp = a*n + b*(n+1LL);

    for(int i=1; i<(int)v.size(); i++){
        if(i==(int)v.size()-1){
            resp += a;
        }
        else if(i&1){
            if(!cima){
                resp += a;
                cima = 1;
            }

            resp += (v[i]+1LL)*b;
        }
        else{
            if((v[i]-1LL)*b<=2LL*a){ // fico em cima
                resp += (v[i]-1LL)*b;
            }
            else{ //embaixo
                cima = 0;
                resp += a;  
            }    
        }
    }

    cout << resp << endl;
}

int main(){
    fast_io;
    
    int t;
    cin >> t;

    while(t--){
        solve();
    }

    return 0;
}
