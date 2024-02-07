// 26/01/24 //
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

bool comp(pii &a, pii &b){
    return a.SS<b.SS;
}

int main(){
    fast_io;

    ll n;
    while(cin>>n){
        if(n==0) break;

        vector<pii> v(n);
        for(int i=0; i<n; i++){
            int x, y;
            cin >> x >> y;

            v[i].FF = x-y;
            v[i].SS = x+y;
        }


        ll p=0, aux=0;

        sort(v.begin(), v.end());
        for(int i=1; i<n; i++){ 
            if(v[i].FF==v[i-1].FF){
                aux++;
            }

            if(v[i].FF!=v[i-1].FF || i==n-1){
                p += aux*(aux+1LL);

                aux=0LL;
            }
        }

        sort(v.begin(), v.end(), comp);
        for(int i=1; i<n; i++){ 
            if(v[i].SS==v[i-1].SS){
                aux++;
            }

            if(v[i].SS!=v[i-1].SS || i==n-1){
                p += aux*(aux+1LL);

                aux=0LL;
            }
        }
        
        cout.precision(6);
        cout.setf(ios::fixed);

        double resp = (double)(p) / (double)(n*n);
        cout << resp << endl;
    }

    return 0;
}
