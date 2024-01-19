/*
18/01/24 
Problem: 
Complexity:
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
#define FF first
#define SS second

typedef pair<int, int> pii;
typedef tuple<int, int, int> tiii;

const int INF  = 0x3f3f3f3f;
const  ll LINF = 0x3f3f3f3f3f3f3f3f;
const int MAXN = (2e5) + 5;
const int MOD  = (1e9) + 7;

ll exp(ll a, ll b, ll m=MOD){ // 0^0 = 1
    ll r = 1LL;

    while(b>0LL){
        if(b&1){
            r = (r*a)%m;
            b--;
        }
        else{
            a = (a*a)%m;
            b /= 2LL;
        }
    } 

    return r;
}

int main(){
    fast_io;

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        string inicial, desired;

        cin >> inicial >> desired;

        int count=0;
        int right=0, wrong=0;

        for(int i=0; i<n; i++){
            count += (int)(desired[i]=='1');

            if(inicial[i]=='1' && desired[i]=='1'){
                right++;
            }
            else if(inicial[i]=='1' && desired[i]=='0'){
                wrong++;
            }
        }

        count -= right;

        if(count>=wrong){
            cout << count << endl;
        }
        else{
            cout << wrong << endl;
        }

    }

    return 0;
}
