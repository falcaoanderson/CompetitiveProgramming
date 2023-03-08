// 05/11/20 // xx:xx PM //

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define pb push_back
#define mp make_pair
#define ll long long
//#define int long long

typedef pair<int, int> pii;

const int INF  = 0x3f3f3f3f;
const int MAXN = (1e5) + 10;

int mdc(int a, int b){
    if(a==0) return b;

    return mdc(b%a, a);
}

int main(){
    fast_io;

    int c, d, q;
    cin >> c >> d >> q;

    int m = mdc(d, q);
    d /= m;
    q /= m;

    if(d>c || q>c) cout << "IMPOSSIVEL" << endl;
    else cout << d << " " << q << endl;

    return 0;
}
