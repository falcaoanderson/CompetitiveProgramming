// 00/01/20 // 00:00 XM //

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define pii pair<int,int>
//#define int long long

const int INF = 0x3f3f3f3f;
const int MAXN = (int)(1e5) + 10;

void solve(){
    int n;
    cin >> n;
    vector<int> v(n);
    for(int& i : v) cin >> i;

    sort(v.begin(), v.end());

    int cont = 0;
    for(int i=0; i<n; i++){
        if(v[i]==-1) continue;
        for(int j=i+1; j<n; j++){
            if(v[j]%v[i]==0){
                cont++;
                v[j]=-1;
            }
        }
    }

    cout << n - cont << endl;
}

int main(){
    fastio;


    solve();

    return 0;
}
