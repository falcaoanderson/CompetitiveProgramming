// 14/07/23 //
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <tuple>
#include <cstring>
#include <stack>

using namespace std;

#define ll long long
#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define PB push_back
#define EB emplace_back
#define ff first
#define ss second

typedef pair<int, int> pii;
typedef tuple<int, int, int> tiii;

const int MAXN = (2e5) + 5;

int prox[MAXN], status[MAXN], last[MAXN], sz[MAXN], cycle[MAXN];

int dfs(int u){
    status[u] = 1;
 
    int flag=0;
    int v = prox[u];
        
    if(status[v]==0){
        last[v] = u;
        flag = dfs(v);
    }
    else if(status[v]==1){
        last[v] = u;
        flag=u; // achei um ciclo
    }
    
    status[u] = 2;
    return flag;
}

int memo[MAXN];

int solve(int u){
    if(memo[u]!=0) return memo[u];

    if(cycle[u]!=0) return memo[u] = sz[cycle[u]];

    return memo[u] = solve(prox[u]) + 1;
}

int main(){
    fast_io;

    int n;
    cin >> n;

    for(int i=1; i<=n; i++) cin >> prox[i];

    int qnt_cycle=0;

    for(int i=1; i<=n; i++){
        if(status[i]==0){
            int u = dfs(i);

            if(u!=0){
                qnt_cycle++;
                int t_sz=0;

                while(cycle[u]==0){
                    cycle[u]=qnt_cycle;
                    t_sz++;
                    u = last[u];
                }

                sz[qnt_cycle] = t_sz;
            }
        }   
    }

    for(int i=1; i<=n; i++)
        cout << solve(i) << " "; 
    cout << endl;

    return 0;
}
