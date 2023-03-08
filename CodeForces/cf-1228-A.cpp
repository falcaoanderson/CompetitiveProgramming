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
    int l, r;
    cin >> l >> r;

    string num;
    bool ok;

    for(int i=l; i<=r; i++){
        num = to_string(i);
        ok = true;

        for(int m=0; m<(int)num.size(); m++)
            for(int n=m+1; n<(int)num.size(); n++)
                if(num[m]==num[n]) ok = false;

        if(ok) break;
    }

    if(ok){
        cout << num << endl;
    }
    else{
        cout << "-1\n";
    }
}

int main(){
    fastio;

    solve();

    return 0;
}
