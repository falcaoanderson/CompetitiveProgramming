// 03/11/20 // xx:xx PM //

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define pb push_back
#define mp make_pair
#define ll long long
//#define int long long

typedef pair<int, int> pii;

const ll MOD   = (1e9) + 7;
const int MAXV = 125250 + 10;

ll memo[MAXV];

int main(){
    fast_io;

    int n;
    cin >> n;

    int sum = (n*(n+1))/2;

    if(sum&1){
        cout << 0 << endl;
        return 0;
    }

    memo[0] = 1LL;
    sum = 0;
    for(int i=1; i<=n; i++){
        sum += i;
        for(int j=sum; j>=i; j--)
            memo[j] = (memo[j] + memo[j-i])%MOD;
    }

    ll resp = (memo[sum/2] * 500000004LL )%MOD; // 500000004 = 2^-1 mod.(MOD)

    cout << resp << endl;

    return 0;
}
