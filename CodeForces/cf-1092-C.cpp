/*
04/03/24 
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

bool cmp(pair<string, int> &a, pair<string, int> &b){
    return sz(a.FF)<sz(b.FF);
}

int main(){
    fast_io;

    int n;
    cin >> n;

    vector< pair<string, int> > v(2*n-2);
    string b1, b2;

    for(int i=0; i<2*n-2; i++){
        cin >> v[i].FF;
        v[i].SS = i;
    }   
    sort(v.begin(), v.end(), cmp);

    string s1 = v[2*n-3].FF + v[2*n-4].FF.back();
    string s2 = v[2*n-4].FF + v[2*n-3].FF.back();

    bool possible1=1;
    for(int i=0; i<=n-2 && possible1; i++){
        int a = 2*i;
        int b = 2*i+1;
        
        string prefix = s1.substr(0, i+1);
        string sufix  = s1.substr(n-1-i, i+1);

        possible1 = ((prefix==v[a].FF && sufix==v[b].FF) || (prefix==v[b].FF && sufix==v[a].FF));  
    }

    string s;
    if(possible1) s = s1;
    else          s = s2;

    string resp(2*n-2, ' ');
    for(int i=0; i<=n-2; i++){
        int a = 2*i;
        int b = 2*i+1;
        string prefix = s.substr(0, i+1);
        string sufix  = s.substr(n-1-i, i+1);

        if(prefix==v[a].FF && sufix==v[b].FF){
            resp[v[a].SS] = 'P';
            resp[v[b].SS] = 'S';
        }  
        else{
            resp[v[a].SS] = 'S';
            resp[v[b].SS] = 'P';
        }
    } 

    cout << resp << endl;

    return 0;
}
