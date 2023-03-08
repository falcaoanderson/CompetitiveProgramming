// 10/11/20 // xx:xx PM //
 
#include <bits/stdc++.h>
 
using namespace std;
 
#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define pb push_back
#define mp make_pair
#define ll long long
//#define int long long
 
typedef pair<int, int> pii;
 
const int INF  = 0x3f3f3f3f;
const int MAXN = (1e5) + 10;
 
int n, m, pai[MAXN], peso[MAXN], tam[MAXN], maior=-1;
 
int find(int u){
    if(pai[u]==u) return u;
 
    return pai[u] = find(pai[u]);
}
 
void join(int a, int b){
    a = find(a);
    b = find(b);
 
    if(peso[a]==peso[b]){
        pai[b] = a;
        peso[a]++;
        tam[a] += tam[b];
    }
    else if(peso[a]<peso[b]){
        pai[a] = b;
        tam[b] += tam[a];
    }
    else{
        pai[b] = a;
        tam[a] += tam[b];
    }
 
    maior = max(maior, max(tam[a], tam[b]));
}
 
int main(){
    fast_io;
 
    cin >> n >> m;
    
    for(int i=1; i<=n; i++){
        pai[i] = i;
        tam[i] = 1;
    }
    int comp = n;
 
    for(int i=0; i<m; i++){
        int a, b;
        cin >> a >> b;
 
        if(find(a)!=find(b)){
            join(a, b);
            comp--;
        }
 
        cout << comp << " " << maior << endl;
    }
    
    return 0;
}