/*
04/01/25 
Problem: CF 580 Div. 2
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
const int MAXN = (2e5) + 5;
const int MOD  = (1e9) + 7;

int main(){
    fast_io;

    ll resp = 0;
    int cnt_neg = 0, cnt_zero = 0;

    int n;
    cin >> n;

    for(int i=0; i<n; i++){
        int x;
        cin >> x;
        
        if(x==0){
            cnt_zero++;
            resp++;
        }
        else if(x>0){
            resp += x-1;
        }
        else{
            cnt_neg++;
            resp += -1 - x;
        }
    }

    if(cnt_neg&1 && cnt_zero==0){
        resp+=2;
    }

    cout << resp << endl;

    return 0;
}
