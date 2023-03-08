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

const int INF = 0x3f3f3f3f;
const int MAXN = (int)(1e5) + 10;

void solve(){
    int n;
    string seq;

    cin >> n >> seq;

    int um = 0,zero = 0;

    for(int i=0; i<n; i++){
        if(seq[i]=='z') zero++;
        if(seq[i]=='n') um++;
    }

    for(int i=0; i<um; i++)
        cout << 1 << " ";
    for(int i=0; i<zero; i++)
        cout << 0 << " ";
    cout << endl;
}

int main(){
    fastio;

    solve();

    return 0;
}
