/*
04/03/26 

*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define PB push_back
#define EB emplace_back
#define FF first
#define SS second
#define SZ(x) (int)(x).size()

typedef pair<int, int> pii;
typedef tuple<int, int, int> tiii;

const int INF  = 0x3f3f3f3f;
const  ll LINF = 0x3f3f3f3f3f3f3f3f;
const int MAXN = (2e5) + 5;
const int MOD  = (1e9) + 7;

int main(){
    fast_io;

    int n, k;
    cin >> n >> k;

    vector<int> v(k);
    set<pii> inv_freq;    
    map<int, int> freq;
    for(int i=0; i<k; i++){
        cin >> v[i];
        v[i] = -v[i];
        auto it = freq.find(v[i]);
        if(it == freq.end()){
            freq[v[i]] = 1;
            inv_freq.insert({1, v[i]});
        }
        else{
            inv_freq.erase({it->second, v[i]});
            it->second++;
            inv_freq.insert({it->second, v[i]});
        }
    }
    cout << -(inv_freq.rbegin()->second) << " ";
    for(int i=k; i<n; i++){
        int xold = v[i % k];
        cin >> v[i % k];
        v[i % k] = -v[i % k];
        int xnew = v[i % k]; 
        
        auto it = freq.find(xold);
        inv_freq.erase({it->second, xold});
        it->second--;
        inv_freq.insert({it->second, xold});
        
        it = freq.find(xnew);
        if(it == freq.end()){
            freq[xnew] = 1;
            inv_freq.insert({1, xnew});
        }
        else{
            inv_freq.erase({it->second, xnew});
            it->second++;
            inv_freq.insert({it->second, xnew});
        }

        cout << -(inv_freq.rbegin()->second) << " ";
    }
    cout << endl;

    return 0;
}
