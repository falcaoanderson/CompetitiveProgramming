// 30/05/23 //
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

const int INF  = 0x3f3f3f3f;
const int MAXN = (2e5) + 5;
const int MOD  = (1e9) + 7;

ll exp(ll a, ll b, ll m=MOD){
    if(b==0) return 1LL;

    if(b&1) return (a*exp(a, b-1, m))%m;
    return exp((a*a)%m, b/2, m)%m;
}

int main(){
    fast_io;

    int t;
    cin >> t;

    while(t--){
        string s;
        cin >> s;

        int start=0, end=0;
        for(int i=0; i<(int)s.size(); i++){
            if(s[i]=='1'){
                start=i;
                break;
            }
        }
        for(int i=(int)s.size()-1; i>=0; i--){
            if(s[i]=='1'){
                end=i;
                break;
            }
        }

        int resp=0;
        for(int i=start+1; i<=end-1; i++){
            resp += (s[i]=='0');
        }

        cout << resp << endl;
    }

    return 0;
}