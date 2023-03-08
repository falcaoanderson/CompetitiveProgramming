// 28/10/20 // 7:02 PM //

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define pb push_back
#define mp make_pair
#define ll long long
//#define int long long

typedef pair<ll, int> pii;

const int INF  = 0x3f3f3f3f;
const int MAXN = (1e5) + 10;

int main(){
    fast_io;

    int n;
    ll x;
    cin >> n >> x;
    
    vector<pii> v(n+1);
    for(int i=1; i<=n; i++){
        cin >> v[i].first;
        v[i].second = i;
    }

    sort(v.begin()+1, v.end());

    for(int i=1; i<=n; i++)
        for(int j=i+1; j<=n; j++){
            int sum = x - v[i].first - v[j].first;
            if(sum<=0) continue;

            int ini = 1, fim=n, meio, ind=-1;

            while(ini<=fim){
                meio = (ini+fim)/2;

                if(v[meio].first==sum){

                    if(v[i].second!=v[meio].second && v[j].second!=v[meio].second) ind = meio;
                    ini = meio+1;
                }
                if(v[meio].first<sum)
                    ini = meio+1;
                if(v[meio].first>sum)
                    fim = meio-1;
            }

            if(ind!=-1){
                cout << v[i].second << " " << v[j].second << " " << v[ind].second << endl;
                return 0;
            }
        }

    cout << "IMPOSSIBLE" << endl;

    return 0;
}
