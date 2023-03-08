// 00/00/20 // 00:00 XX //

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define pb push_back
#define mp make_pair
#define ff first
#define ss second

const int INF = 0x3f3f3f3f;
const int MAXN = 1e3 + 10;

int weight[MAXN];

void solve(){
    int n, m;

    cin >> n >> m;

    int m1=0, m2=0, sum_weight=0;
    weight[0] = INF;

    for(int i=1; i<=n; i++){
        cin >> weight[i];
        sum_weight += weight[i];

        if(weight[i]<weight[m1]){
            m2 = m1;
            m1 = i;
        }
        else if(weight[i]<weight[m2]){
            m2 = i;
        }
    }

    if(m<n || n==2){
        cout << "-1\n";
        return;
    }

    cout << sum_weight*2 + (m-n) * (weight[m1]+weight[m2]) << endl;

    for(int i=1; i<n; i++)
        cout << i << " " << i+1 << endl;
    cout << "1 " << n << endl;
    for(int i=0; i<m-n; i++)
        cout << m1 << " " << m2 << endl;

}

int main(){
    fastio;

    int t;
    cin >> t;
    while(t--) solve();

    return 0;
}
