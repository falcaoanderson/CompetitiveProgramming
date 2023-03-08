// 26/10/20 // 10:23 PM //

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

int main(){
    fast_io;

    int n;
    cin >> n;

    vector<ll> v(n);
    for(int i=0; i<n; i++)cin >> v[i];

    if(n==1){
        cout << v[0] << endl;
        return 0;
    }

    sort(v.begin(), v.end());

    int op1 = n/2, op2=(n+1)/2;
    ll sum1=0, sum2=0;

    for(int i=0; i<n; i++){
        sum1 += abs(v[i]-v[op1]);
        sum2 += abs(v[i]-v[op2]);
    }

    cout << min(sum1, sum2) << endl;

    return 0;
}

