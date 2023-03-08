// 17/12/19 // 8:82 PM //

#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define endl "\n"
#define int long long
#define mp make_pair

const int MAXN = 5e5+10;
const int INF = 0x3f3f3f3f3f3f3f3f;

int n, p, q;

int merge_sort(vector<int> &v){
    int sz = (int)v.size();

    if(sz==1) return 0;

    vector<int> u1,u2;

    for(int i=0;  i<sz/2; i++) u1.pb(v[i]);
    for(int i=sz/2; i<sz; i++) u2.pb(v[i]);

    int inv = merge_sort(u1) + merge_sort(u2);

    int ini1=0, ini2=0;
    if(q>0){
        u1.pb(-INF);  u2.pb(-INF);

        for(int i=0; i<sz; i++){
            if(u1[ini1] > u2[ini2]){
                v[i] = u1[ini1];
                ini1++;
            }
            else{
                v[i] = u2[ini2];
                ini2++;

                inv += (int)u1.size() - ini1 -1;
            }
        }
    }
    else{
        u1.pb(INF);  u2.pb(INF);

        for(int i=0; i<sz; i++){
            if(u1[ini1] < u2[ini2]){
                v[i] = u1[ini1];
                ini1++;
            }
            else{
                v[i] = u2[ini2];
                ini2++;

                inv += (int)u1.size() - ini1 -1;
            }
        }
    }

    return inv;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    pair<int, int> tv[MAXN];
    vector<int> v;

    cin >> n >> p >> q;

    for(int i=0; i<n; i++){
        int x, y;
        cin >> x >> y;
        tv[i] = mp(x, y);
    }
    sort(tv, tv+n);

    for(int i=0; i<n; i++)v.pb(q*tv[i].second - p*tv[i].first);

    cout << merge_sort(v) << endl;

    return 0;
}
