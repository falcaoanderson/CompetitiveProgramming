/*
09/08/25 

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
const int MAXN = 30;
const int MOD  = (1e9) + 7;

int indegree[MAXN], val[MAXN];
vector<int> adj[MAXN];

int main(){
    fast_io;
    
    int n;
    cin >> n;

    for(int i=0; i<n; i++){
        string s;
        cin >> s;

        for(int i=1; i<(int)s.size(); i++){
            int u = s[i-1]-'a', v=s[i]-'a';
            if(u==v) continue;

            adj[u].PB(v);
            indegree[v]++;
        }
    }

    queue<int> fila;

    for(int i=0; i<26; i++){
        if(indegree[i]==0){
            fila.push(i);
            val[i] = 1; 
            // cout << char(i+97);
        }
    }
    // cout << endl;

    bool resp = !fila.empty();

    while(resp && !fila.empty()){
        int u = fila.front(); 
        fila.pop();

        for(int v: adj[u]){
            indegree[v]--;

            if(indegree[v]==0){
                val[v] = val[u]+1;
                fila.push(v);
            }
        }
    }

    for(int i=0; i<26 && resp; i++){
        resp = (val[i]!=0);
    }

    if(!resp){
        cout << "NAO" << endl;
    }
    else{
        cout << "SIM" << endl;
        vector<vector<int>> vaux(27);

        for(int i=0; i<26; i++){
            // cout << val[i];
            vaux[val[i]].PB(i);
        }
        // cout << endl;

        for(int i=1; i<=26; i++){
            for(int x: vaux[i]){
                cout << char(97+x);
            }
        }
        cout << endl;
    }

    return 0;
}
