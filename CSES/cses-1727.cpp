// 18/11/20 // xx:xx PM //

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
const int MOD  = (1e9) + 7;

int n, k;

int main(){
    fast_io;

    cin >> n >> k;

    double resp = 0, ant_pot=0;

    for(int i=1; i<=k; i++){
        double pot = pow(i, n);

        resp += i*(pot - ant_pot);

        ant_pot = pot;
    }

    resp = resp/ant_pot;

    cout.precision(6); cout.setf(ios::fixed);
    
    cout << resp << endl;

    return 0;
}
