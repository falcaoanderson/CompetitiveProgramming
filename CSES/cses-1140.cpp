// 03/11/20 // xx:xx PM //

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define pb push_back
#define mp make_pair
#define ll long long
//#define int long long
#define ini first.first
#define fim first.second
#define val second

typedef pair<pair<int, int>, ll> piii;

const int INF  = 0x3f3f3f3f;
const int MAXN = (2e5) + 10;

int n;
piii v[MAXN];
ll memo[MAXN];

int pos(int x){
    int l = 1, r = n, mid, resp = 0;

    while(l<=r){
        mid = (l+r)/2;

        if(v[mid].ini>x){
            resp = mid;
            r = mid-1;
        }
        else
            l = mid+1;
    }

    return resp;
}

int main(){
    fast_io;

    cin >> n;

    for(int i=1; i<=n; i++)
        cin >> v[i].ini >> v[i].fim >> v[i].val; 

    sort(v+1, v+n+1);

    for(int i=n; i>=1; i--)
        memo[i] = max(memo[i+1], memo[pos(v[i].fim)] + v[i].val);
    
    cout << memo[1] << endl;

    return 0;
}
