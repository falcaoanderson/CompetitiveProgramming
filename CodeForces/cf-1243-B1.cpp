    // 00/00/20 // 00:00 XX //

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define pb push_back
#define mp make_pair
#define ff first
#define ss second

const int INF = 0x3f3f3f3f;
const int MAXN = (int)(1e5) + 10;

void solve(){
    int n;
    string s, t;

    cin >> n >> s >> t;

    int p1, p2, cont=0;

    for(int i=0; i<n; i++){
        if(s[i]!=t[i]){
            cont++;

            if(cont==1)
                p1 = i;
            else if(cont==2)
                p2 = i;
        }
    }

    if(cont!=2 || s[p1]!=s[p2] || t[p1]!=t[p2]){
        cout << "No\n";
    }
    else{
        cout << "Yes\n";
    }
}

int main(){
    fastio;

    int t;
    cin >> t;
    while(t--) solve();

    return 0;
}
