/*
19/07/25 

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

    int n;
    cin >> n;

    vector<int> v(n);
    int pos_high = -1;
    
    for(int i=0; i<n; i++){
        cin >> v[i];

        if(v[i]<0){
            v[i] = (-v[i]-1);
        }

        if(v[i]>0 && (pos_high==-1 || v[pos_high]<v[i])){
            pos_high = i;
        }
    }
  
    if(n&1){
        for(int i=0; i<n; i++){ 
            if(i==pos_high || pos_high==-1)
                cout << v[i] << " ";
            else
                cout << (-v[i]-1) << " ";
        }
    }
    else{
        for(int i=0; i<n; i++){ 
            cout << (-v[i]-1) << " ";
        }
    }
    cout << endl;

    return 0;
}
