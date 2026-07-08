/*
30/03/26 

*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define PB push_back
#define EB emplace_back
#define FF first
#define SS second
#define SZ(x) (int)(x).size()

typedef pair<int, int> pii;
typedef tuple<int, int, int> tiii;

const int INF  = 0x3f3f3f3f;
const  ll LINF = 0x3f3f3f3f3f3f3f3f;
const int MAXN = (2e5) + 5;
const int MOD  = (1e9) + 7;

void solve(){
    int n, k;
    cin >> n >> k;

    vector<int> a(n), b(n);
    for(int i=0; i<n; i++) cin >> a[i];
    for(int i=0; i<n; i++) cin >> b[i];

    bool ans = 1;
    int count = 0;
    for(int i=0; i<k; i++){
        bool op1 = 1, op2 = 1, op3 = 1;
        int val = -1;

        for(int j=i; j<n && val == -1; j+=k){
            val = b[j];
        }
    
        if(val == -1) op2 = 0;
        else op3 = 0;

        for(int j=i; j<n; j+=k){
            if(op1 && !(a[j] == b[j] || b[j] == -1)) op1 = 0;
            
            if(op2 && !(a[i]==a[j] && (b[j] == -1 || b[j] == val)))  op2 = 0;

            if(op3 && !(a[i]==a[j])) op3 = 0;
        }

        if(!op1 && !op2 && !op3){
            ans = 0;
            break;
        }
        
        if(b[i] == -1){
            if(op3){
                // cout << i << " op3" << endl;
                count++;
            }
            else if(op1){
                // cout << i << " op1" << endl;
                b[i] = a[i];
            }
            else if(op2){
                // cout << i << " op2" << endl;
                b[i] = val;
            }
        }
    }

    // cout << "prev_ans: " << ans << endl;

    sort(a.begin(), a.begin()+k);
    sort(b.begin(), b.begin()+k);

    int l = 0, miss=0;
    for(int i=0; i<k; i++){
        while(l < k && b[l] < a[i]){
            l++;
        }
        if(l < k && b[l] == a[i]){
            l++;
        }
        else{
            miss++;
        }
    }

    if(miss > count) ans = 0;

    // cout << "ans: ";
    cout << (ans? "YES": "NO") << endl;
}

int main(){
    fast_io;

    int t=1;
    cin >> t;
    while(t--){
        solve();
    }

    return 0;
}
