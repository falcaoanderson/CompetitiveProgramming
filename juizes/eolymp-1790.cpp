/*
08/03/24 
Problem: EOlymp - 1790
Complexity: O(n^2)
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

    vector<int> v(n), resp(n);
    int aux = n;

    for(int i=0; i<n; i++){
        cin >> v[i];
    }

    while(aux){
        for(int i=n-1; i>=0; i--){
            if(v[i]==0){
                resp[i] = aux;

                for(int j=i; j<n; j++) v[j]--;

                break;
            }
        }

        aux--;
    }

    for(int i: resp) cout << i << " ";
    cout << endl;

    return 0;
}
