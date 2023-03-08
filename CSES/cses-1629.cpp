// 26/10/20 // 8:48 PM //

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define pb push_back
#define mp make_pair
//#define int long long

typedef pair<int, int> pii;

const int INF  = 0x3f3f3f3f;
const int MAXN = (1e5) + 10;

int main(){
    fast_io;

    int n;
    cin >> n;

    vector<pii> v(n);

    for(int i=0; i<n; i++)
        cin >> v[i].second >> v[i].first;

    sort(v.begin(), v.end());

    int resp = 0, ant = -1;
    for(int i=0; i<n; i++){
        if(v[i].second>=ant){
            resp++;
            ant = v[i].first;
        }
    }

    cout << resp << endl;

    return 0;
}
