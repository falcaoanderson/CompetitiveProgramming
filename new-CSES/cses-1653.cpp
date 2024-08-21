/*
20 and 21 /08/24 
Problem: Elevator Rides - CSES
Complexity: O(n * 2^n)
*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define PB push_back
#define EB emplace_back
#define FF first
#define SS second
#define sz(x) (int)(x).size()

typedef pair<int, int> pii;
typedef tuple<int, int, int> tiii;

const int INF  = 0x3f3f3f3f;
const  ll LINF = 0x3f3f3f3f3f3f3f3f;
const int MAXN = 20 + 5;
const int MAXMASK = (1<<20) + 5;
const int MOD  = (1e9) + 7;

int n, maxw, w[MAXN];
int memo_rides[MAXMASK], memo_last[MAXMASK];

void solve(int mask){
    if(memo_rides[mask]!=-1){
        return;
    }

    if(mask==(1<<n)-1){
        memo_rides[mask] = 0;
        memo_last[mask]  = maxw;
        return;
    }

    memo_rides[mask] = memo_last[mask] = INF;

    for(int i=0; i<n; i++){
        if((mask & (1<<i))==0){
            solve(mask | (1<<i));
            int rides, last;

            if(w[i] + memo_last[mask | (1<<i)] <= maxw){
                rides = memo_rides[mask | (1<<i)];
                last  = w[i] + memo_last[mask | (1<<i)];
            }
            else{
                rides = memo_rides[mask | (1<<i)] + 1;
                last  = w[i];
            }

            if(memo_rides[mask]>rides || (memo_rides[mask]==rides && memo_last[mask]>last)){
                memo_rides[mask] = rides;
                memo_last[mask]  = last;
            }
        }
    }
}

int main(){
    fast_io;

    cin >> n >> maxw;
    for(int i=0; i<n; i++){
        cin >> w[i];
    }

    memset(memo_rides, -1, sizeof(memo_rides));

    solve(0);
    cout << memo_rides[0] << endl;

    return 0;
}