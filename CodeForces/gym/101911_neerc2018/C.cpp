/*
30/01/26

*/

#include <bits/stdc++.h>

using namespace std;

#define fast_io ios_base::sync_with_stdio(false);cin.tie(nullptr)
#define endl "\n"
#define FF first
#define SS second
#define PB push_back
#define EB emplace_back

using ll = long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;

// const int MAXVAL = 1e6 + 5;
const int MAXN = 1e5 + 5;

int ilog2(int x){
    int ans = 0;
    while(x>0){
        x /= 2;
        ans++;
    }
    return ans;
}

int main(){
    fast_io;

    int n;
    cin >> n;
    vector<int> v(n);
    for(int i=0; i<n; i++) cin >> v[i];

    sort(v.begin(), v.end());
    int x = v[0];
    bool flag = 1;

    for(int i=0; i<n && flag; i++){
        flag = flag && ((v[i]%x)==0);
        v[i] /= x;
        flag = flag && (v[i] - (v[i] & -v[i]) == 0);    
    }

    if(!flag){
        cout << -1 << endl;
        return 0;
    }

    vector<int> pot(65);
    for(int i=0; i<n; i++){
        pot[ilog2(v[i])]++;
    }

    int ans = 0;
    for(int i=1; i<=64; i++){
        if(pot[i]==1){
            flag = 0;
            for(int j=i+1; j<=64 && !flag; j++){
                flag = (pot[j]!=0);
            }
            if(!flag){
                break;
            }
        }

        if(pot[i]&1){
            ans++;
        }

        pot[i+1] += (pot[i]+1) / 2;
    }

    cout << ans << endl;

    return 0;
}