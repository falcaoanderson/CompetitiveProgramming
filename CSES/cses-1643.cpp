// 26/10/20 // 9:56 PM //

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define pb push_back
#define mp make_pair
#define ll long long
//#define int long long

typedef pair<int, int> pii;

const ll INF  = 0x3f3f3f3f;

int main(){
    fast_io;

    int n;
    cin >> n;

    ll atual = 0LL, melhor = -INF;

    for(int i=0; i<n; i++){
        ll val;
        cin >> val;

        atual = max(val, atual+val);
        melhor = max(melhor, atual);
    }

    cout << melhor << endl;

    return 0;
}

