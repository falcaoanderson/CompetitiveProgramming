/*
26/03/24 
Problem: 
Complexity:
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

pii get_input(string &s, int i){
    int n = sz(s);

    while(i<n && s[i]==' ') i++;

    if(i>=n) return {0, n};
    if(s[i]=='(') return {-1, i+1};
    if(s[i]==')') return {-2, i+1};

    string aux="";
    for(; i<n && isdigit(s[i]); i++){
        aux += s[i];
    }

    return {stoi(aux), i};
}

int main(){
    fast_io;

    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);
    
    stack<int> dfs_stack;
    dfs_stack.push(0);
    
    map<int, vector<int> > adj1, adj2;
    
    int idx = 0;
    while(idx < sz(s1)){
        pii aux = get_input(s1, idx);
        idx = aux.SS;

        if(aux.FF>0){
            // cout << aux.FF << endl;
            adj1[dfs_stack.top()].PB(aux.FF);
            dfs_stack.push(aux.FF);
        }
        else if(aux.FF==-1){
            // cout << '(' << endl;
            continue;
        }
        else if(aux.FF==-2){
            // cout << ')' << endl;
            dfs_stack.pop();
        }
    }

    idx = 0;
    while(!dfs_stack.empty()) dfs_stack.pop();
    dfs_stack.push(0);

    while(idx < sz(s2)){
        pii aux = get_input(s2, idx);
        idx = aux.SS;

        if(aux.FF>0){
            // cout << aux.FF << endl;
            adj2[dfs_stack.top()].PB(aux.FF);
            dfs_stack.push(aux.FF);
        }
        else if(aux.FF==-1){
            // cout << '(' << endl;
            continue;
        }
        else if(aux.FF==-2){
            // cout << ')' << endl;
            dfs_stack.pop();
        }
    }

    for(map<int, vector<int> >::iterator it=adj1.begin(); it!=adj1.end(); it++){
        // cout << (it->first) << ": ";
        sort((it->second).begin(), (it->second).end());

        // for(int v: (it->second)){
        //     cout << v << " ";
        // }
        // cout << endl;
    }

    for(map<int, vector<int> >::iterator it=adj2.begin(); it!=adj2.end(); it++){
        // cout << (it->first) << ": ";
        sort((it->second).begin(), (it->second).end());
        
        // for(int v: (it->second)){
        //     cout << v << " ";
        // }
        // cout << endl;
    }

    cout << (adj1==adj2?"Yes":"No") << endl;

    return 0;
}
