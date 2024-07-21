/*
19/07/24 
Problem: 
Complexity:
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

int va[MAXN], vb[MAXN], sizeA[MAXN], sizeB[MAXN];
bool qresp[MAXN];

int main(){
    fast_io;
    
    int n;
    cin >> n;

    set<int> setAux;

    for(int i=1; i<=n; i++){
        cin >> va[i];

        sizeA[i] = sizeA[i-1];

        if(setAux.find(va[i])==setAux.end()){
            setAux.insert(va[i]);

            sizeA[i]++;
        } 
    }
    
    setAux.clear();

    for(int i=1; i<=n; i++){
        cin >> vb[i];

        sizeB[i] = sizeB[i-1];

        if(setAux.find(vb[i])==setAux.end()){
            setAux.insert(vb[i]);

            sizeB[i]++;
        } 
    }
    
    setAux.clear();

    int a=0, b=0;
    for(int t=1; t<=n; t++){
        while(sizeA[a]<t && a<n){
            a++;
        }
        if(a>n) break;
        while(sizeB[b]<t && b<n){
            b++;
        }
        if(b>n) break;

        
        if(setAux.find(va[a])==setAux.end()){
            setAux.insert(va[a]);
        }
        else{
            setAux.erase(va[a]);
        }

        if(setAux.find(vb[b])==setAux.end()){
            setAux.insert(vb[b]);
        }
        else{
            setAux.erase(vb[b]);
        }

        qresp[t] = setAux.empty();
    }

    int q;
    cin >> q;
    while(q--){
        cin >> a >> b;

        if(sizeA[a]!=sizeB[b]){
            cout << "No" << endl;
            continue;
        }

        cout << (qresp[sizeA[a]]? "Yes": "No") << endl;
    }


    return 0;
}
