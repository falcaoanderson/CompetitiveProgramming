/*
16/07/25 

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

    int n;
    cin >> n;

    vector<int> v(n+1);
    int count=0;
    for(int i=1; i<=n; i++){
        cin >> v[i];
        count += (v[i]==0);
    }

    if((n==1 && v[1]==0) || count>=2){
        cout << "cslnb" << endl;
        return 0;
    }

    sort(v.begin(), v.end());

    count = 0;
    for(int i=2; i<=n; i++){
        count += (v[i]==v[i-1]);
    }
    if(count>=2){
        cout << "cslnb" << endl;
        return 0;
    }

    bool resp = 0, flag=0;
    
    for(int i=n-1; i>=1; i--){
        if(v[i]==v[i+1]){
            
            if(v[i]==0 || (i>1 && v[i-1]==v[i]-1)){
                flag = 1;
                resp ^= 1;
                break;
            }

            v[i]--;
            resp ^= 1;
        }
    }

    if(flag){
        cout << ((resp==0)? "sjfnb": "cslnb") << endl;
        return 0;
    }

    for(int i=1; i<=n; i++){
        int b = v[i]-v[i-1];

        if(i==1)
            resp ^= (b%2==1 && (n-i+1)%2==1);
        else if(b >= 2)
            resp ^= ((b-1)%2==1 && (n-i+1)%2==1);
    }

    cout << (resp==1? "sjfnb": "cslnb") << endl;

    return 0;
}
