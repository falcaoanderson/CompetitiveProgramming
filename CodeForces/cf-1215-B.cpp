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
#define int long long

const int INF = 0x3f3f3f3f;
const int MAXN = (int)(2e5) + 10;

void solve(){
    int n;
    cin >> n;

    int total_pos=0, total_neg=0, neg=0, cpar=0, cimp=0;

    for(int i=0; i<n; i++){
        int temp;
        cin >> temp;


        cpar += (int)(~neg&1);
        cimp += (int)(neg&1);
        neg  += (int)(temp<0);
        if(neg&1){
            total_pos += cimp;
            total_neg += cpar;
        }
        else{
            total_pos += cpar;
            total_neg += cimp;
        }
    }

    cout << total_neg << " " << total_pos << endl;
}

int32_t main(){
    fastio;

    solve();

    return 0;
}
