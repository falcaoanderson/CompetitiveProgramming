/*
17/10/23 
Problem: ICPC Latam 2020 Regional - K. Keylogger
Complexity: O(n*k*log(k))
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <tuple>
#include <cstring>
#include <stack>
#include <functional>
#include <cmath>

using namespace std;

#define ll long long
#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define PB push_back
#define EB emplace_back
#define ff first
#define ss second

typedef pair<int, int> pii;
typedef tuple<int, int, int> tiii;

const int MAXN = (1e4) + 5;
const int MAXK = (750) + 5;
const  ll MOD  = (1e9) + 7;

int n, k;
ll l, t[MAXK][MAXK], p[MAXN];
ll memo[MAXN][MAXK];

int lower_bound(int line, ll val){
    int l=1, r=k, mid;
    int pos = -1;

    while(l<=r){
        mid = (l+r)/2;

        if(t[line][mid]>=val){
            r=mid-1;
            pos = mid;
        }
        else{
            l = mid+1;
        }
    }

    return pos;
}
int upper_bound(int line, ll val){
    int l=1, r=k, mid;
    int pos = -1;

    while(l<=r){
        mid = (l+r)/2;

        if(t[line][mid]<=val){
            l = mid+1;
            pos = mid;
        }
        else{
            r = mid-1;
        }
    }

    return pos;
}

int main(){
    fast_io;

    cin >> k >> l;

    for(int i=1; i<=k; i++){
        for(int j=1; j<=k; j++){
            cin >> t[i][j];
        }
    }

    cin >> n;
    for(int i=2; i<=n; i++) cin >> p[i];

    //memo[i][j] = quantidade de sufixos de senhas validas no qual o i-esimo digito eh <=j

    for(int j=1; j<=k; j++) memo[n][j] = j;

    for(int i=n-1; i>=1; i--){
        for(int j=1; j<=k; j++){
            
            memo[i][j] = memo[i][j-1];

            int after_min = lower_bound(j, p[i+1]-l);
            int after_max = upper_bound(j, p[i+1]+l);

            if(after_min>0 && after_max>0 && after_min<=after_max){
                memo[i][j] += (memo[i+1][after_max] - memo[i+1][after_min-1] + MOD)%MOD;
                memo[i][j] %= MOD;
            }
        }
    }

    cout << memo[1][k] << endl;

    return 0;
}
