// 00/01/20 // 00:00 XM //

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define pii pair<int,int>
//#define int long long

const int INF = 0x3f3f3f3f;
const int MAXN = (int)(1e5) + 10;

void solve(){
    int n, k;
    cin >> n >> k;
    vector<int> v(n);

    int max_v = -1;
    for(int i=0; i<n; i++){
        cin >> v[i];
        max_v = max(max_v, v[i]);
    }

    sort(v.begin(), v.end());
    vector<int> cont(max_v+1,0);
    vector<int> sum(max_v+1,0);

    for(int& i : v){
        int temp=0;
        cont[i]++;
        while(i){
            i >>= 1;
            if(cont[i]<k){
                sum[i] += (++temp);
                cont[i]++;
            }
        }
    }

    int best = INF;
    for(int i=0; i<=max_v; i++)
        if(cont[i]>=k)
            best = min(best, sum[i]);


    cout << best << endl;
}

int main(){
    fastio;

    solve();

    return 0;
}
