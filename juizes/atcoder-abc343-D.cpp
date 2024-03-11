/*
09/03/24 
Problem: Atcoder ABC 343 - D
Complexity: O(t*logt)
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

    int n, t;
    cin >> n >> t;

    set< pair<ll, int> > freq;
    vector<ll> scores(n+1);
    freq.emplace(0, n);

    for(int i=0; i<t; i++){
        int a, b;
        cin >> a >> b;

        // update de older scores
        auto it = freq.upper_bound({scores[a], 0});
        int qnt = (it->second);
        freq.erase(it);
        if(qnt-1>0){
            freq.emplace(scores[a], qnt-1);
            // cout << "nao apagou" << endl;
        }
        //update the new score
        scores[a] += b;
        it = freq.upper_bound({scores[a], 0});
        if(it==freq.end() || (it->first)!=scores[a]){
            qnt = 1;
        }
        else{
            qnt = (it->second) + 1;
            freq.erase(it);
        }
        freq.emplace(scores[a], qnt);


        cout << freq.size() << endl;
        // for(auto it: freq) cout << (it.first) << " " << it.second << " | ";
        // cout << endl;
    }

    return 0;
}
