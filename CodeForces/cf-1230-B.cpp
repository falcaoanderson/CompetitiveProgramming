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
    int n, k;
    string num;

    cin >> n >> k >> num;
    if(n==1 && k==1){
        cout << 0 << endl;
        return;
    }

    int alt = 0;

    for(int i=0; i<n; i++){
        if(alt<k){
            if(i==0){
                cout << 1;
                alt += num[i]!='1';
            }
            else{
                cout << 0;
                alt += num[i]!='0';
            }
        }
        else
            cout << num[i];
    }
}

int main(){
    fastio;

    solve();

    return 0;
}
