/*
26/07/24 
Problem: 
Complexity:
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
const int MAXN = (1e3) + 5;
const int MOD  = (1e9) + 7;

int n, c, t1, t2;
int v[2*MAXN];
int memo[2*MAXN], last;

int solve(int i){
    if(memo[i] != -1) return memo[i];

    if(i>last) return 0;

    int l, r, mid, s1, s2;

    l=i, r=last, s1=i;
    while(l<=r){
        mid = (l+r)/2;

        if(v[i]+t1>=v[mid]){
            s1 = mid;
            l  = mid+1;
        }
        else{
            r = mid-1;
        }
    }

    l=i, r=last, s2=i;
    while(l<=r){
        mid = (l+r)/2;

        if(v[i]+t2>=v[mid]){
            s2 = mid;
            l  = mid+1;
        }
        else{
            r = mid-1;
        }
    }

    return memo[i] = min(t1 + solve(s1+1), t2+solve(s2+1));
}


int main(){
    fast_io;

    while(cin >> n){
        if(n==0) break;
        cin >> c >> t1 >> t2;

        for(int i=0; i<n; i++){
            cin >> v[i];
        }

        for(int i=n; i<2*n-1; i++){
            v[i] = v[i-n] + c;
        }

        int resp = INF;
        for(int i=0; i<n; i++){ 
            last = i + (n-1);
            memset(memo, -1, sizeof(memo));

            resp = min(resp, solve(i));
        }

        cout << resp << endl;
    }

    return 0;
}
