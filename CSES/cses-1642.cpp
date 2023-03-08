// 28/10/20 // xx:xx PM //
// 29/10/20 // 11:00 AM //

#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define pb push_back
#define mp make_pair
#define ll long long

typedef pair<ll, int> pii;
typedef pair<ll, pair<int, int> > plii;

bool algum_igual(pair<int, int> a, pair<int, int> b){
    if(a.first==b.first || a.first==b.second || a.second==b.first || a.second==b.second)
        return 1;
    return 0;
}

int main(){
    fast_io;

    int n;
    ll x;
    cin >> n >> x;

    vector<pii> v(n);

    for(int i=0; i<n; i++){
        cin >> v[i].first;
        v[i].second = i+1;
    }
    
    vector<plii> par;

    for(int i=0; i<n; i++)
        for(int j=i+1; j<n; j++)
            par.pb( mp(v[i].first+v[j].first, mp(v[i].second, v[j].second)) );

    sort(par.begin(), par.end());

    for(int i=0; i<(int)par.size(); i++){
        ll sum = x - par[i].first;
        if(sum<=0) continue;

        int ini = 0, fim = par.size()-1, meio;
        
        while(ini<=fim){
            meio = (ini+fim)/2;

            if(par[meio].first==sum){
                if(algum_igual(par[i].second, par[meio].second)) ini = meio+1;
                else{
                    cout << par[i].second.first << " " << par[i].second.second << " " 
                         << par[meio].second.first << " " << par[meio].second.second << endl;
                    return 0;
                }
            }
            if(par[meio].first>sum) fim = meio-1;
            if(par[meio].first<sum) ini = meio+1;
        }
    }

    cout << "IMPOSSIBLE" << endl;

    return 0;
}
