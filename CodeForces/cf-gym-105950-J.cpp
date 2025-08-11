/*
09/08/25 

*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define PB push_back
#define EB emplace_back
#define FF first
#define SS second
#define sz(x) (int)(x).size()

typedef pair<int, int> pii;
typedef tuple<int, int, int> tiii;

const int INF  = 0x3f3f3f3f;
const  ll LINF = 0x3f3f3f3f3f3f3f3f;
const int MAXN = (2e5) + 5;
const int MOD  = (1e9) + 7;

int main(){
    fast_io;
    
    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    int cntP=0, cntO=0;
    for(int i=0; i<n; i++){
        if(s[i]=='.'){
            cntP++;
        }
        else if(s[i]=='o'){
            cntO++;
        }
    }

    if(k>=cntP){
        while(cntP--) cout << ".";
        cout << "#";
        while(cntO--) cout << "o";
        cout << "#" << endl;
    }
    else{
        int pos=0;
        cntP=0;
        cntO=0;
        for(int i=0; i<n; i++){
            if(s[i]=='.') cntP++;
            if(s[i]=='o') cntO++;
            if(cntP==k){
                pos = i;
                break;
            }
        }
        
        int aux = k;
        while(aux--) cout << '.';
        cout << "#";

        aux = pos - k;
        while(aux--){
            cout << "o";
        }
        for(int i=pos+1; i<n; i++){
            cout << s[i];
        }
        cout << endl;
    }


    return 0;
}
