/*
12/01/24 
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

int max(int a, int b, int c){
    return max(a, max(b, c));
}

int main(){
    fast_io;

    int n;
    cin >> n;

    vector<int> v(n+2);
    v[0]=-INF; v[n+1]=INF;
    for(int i=1; i<=n; i++) cin >> v[i];

    int resp=0, crr=0, crr_rmv=0;
    for(int i=1; i<=n; i++){
        if(v[i]>v[i-1]){
            crr++;

            if(crr_rmv!=0) crr_rmv++;
        }
        else{
            crr_rmv = 0;

            if(v[i+1]>v[i-1] || v[i]>v[i-2]){
                crr_rmv = crr;
                crr=1;
            }
            else{
                crr = 1;
            }
        }

        resp = max(resp, crr, crr_rmv);
        //cout << resp << " ";
    }
    //cout << endl;

    cout << resp << endl;

    return 0;
}
