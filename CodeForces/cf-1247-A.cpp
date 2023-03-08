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
    int a, b;
    cin >> a >> b;
    if(b==1 && a==9){
        cout << "9 10\n";
        return;
    }
    if(b-a!=0 && b-a!=1){
        cout << "-1\n";
        return;
    }

    if(b-a==0){
        cout << a*10 << " " << b*10+1 << endl;
    }
    else{
        cout << a*10+9 << " " << b*10 << endl;
    }
}

int main(){
    fastio;

    solve();

    return 0;
}
