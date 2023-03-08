// 26/10/20 // 8:59 PM //

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

bool comp(pii a, pii b){
    return a.first>=b.first;
}

int main(){
    fast_io;

    int n, x;
    cin >> n >> x;

    vector<pii> pos(n);
    vector<int> v(n);

    for(int i=0; i<n; i++){
        cin >> v[i];
        pos[i].first = v[i];
        pos[i].second = i+1;
    }
    sort(v.begin(), v.end());
    sort(pos.begin(), pos.end());

    int a=-1, b;

    for(int i=0; i<n; i++){
        auto it = lower_bound(v.begin(), v.end(), x-v[i]);

        if(it==v.end()) continue;
        if(it-v.begin()!=i && v[i]+(*it)==x){
            a = pos[i].second;
            b = pos[it-v.begin()].second;
            break;
        }
    }

    if(a==-1)
        cout << "IMPOSSIBLE" << endl;
    else
        cout << a << " " << b << endl;


    return 0;
}
