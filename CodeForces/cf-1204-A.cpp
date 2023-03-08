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
    string num;
    cin >> num;

    int flag = 0, cont=0;
    for(int i=1; i<(int)num.size(); i++) if(num[i] == '1')flag = 1;

    cout << ( flag? (num.size()/2 + num.size()%2) :
             (num.size()-1)/2 + (num.size()-1)%2 )<< endl;

}

int main(){
    fastio;

    solve();

    return 0;
}
