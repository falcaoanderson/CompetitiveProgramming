/*
05/03/26 

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

    string s;
    int m;
    cin >> s >> m;
    int n = SZ(s);
    
    int total = 1;
    vector<vector<int>> adj(1, vector<int>(26, 0));
    vector<int> word(1);

    for(int i=0; i<m; i++){
        string a;
        cin >> a;
        if(SZ(a) > n) continue;

        int crr = 0;
        for(int j=0; j<SZ(a); j++){
            int c = a[j] - 'a';

            if(adj[crr][c] == 0){
                adj.PB(vector<int>(26, 0));
                word.PB(0);
                adj[crr][c] = total++;
            }
            crr = adj[crr][c];
            if(j == SZ(a) - 1){
                word[crr] = 1;
            }
        }
    }    

    // const auto dfs = [&adj, &word](int u) -> void {
    //     auto dfs_aux = [&adj, &word](int u, auto& dfs_ref) mutable -> void {
    //         cout << u << " " << word[u] << endl;
    //         for(int i=0; i<26; i++){
          
    //             if(adj[u][i]!=0){
    //                 cout << u << " --" << char('a' + i) << "--> " << adj[u][i] << endl;
    //                 dfs_ref(adj[u][i], dfs_ref);            
    //             }
    //         }
    //     };
    //     dfs_aux(u, dfs_aux);
    // };
    // dfs(0);

    vector<int> memo(n+1);
    memo[n] = 1;
    for(int i = n-1; i >= 0; i--){
        int crr = 0;
        for(int j=i; j<n; j++){
            int c = s[j] - 'a';
            crr = adj[crr][c];
            if(crr == 0) break;
            if(word[crr]){
                memo[i] = (memo[i] + memo[j+1]) % MOD;
            }
        }
    }

    cout << memo[0] << endl;

    return 0;
}
