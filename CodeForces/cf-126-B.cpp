/*
06/03/24 and 07/03/24 
Problem: Codeforces 126B - Password
Complexity: O(n)
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
const int MAXN = (1e6) + 5;

void build_z_array(string &s, vector<int> &z){
    int n = sz(s);

    z.assign(n, 0);
    int l=0, r=0;

    for(int i=1; i<n; i++){
        z[i] = min(z[i-l], r-i+1);
        z[i] = max(z[i], 0);

        while(i+z[i]<n && s[i+z[i]]==s[z[i]]){
            l = i;
            z[i]++;
            r = i + z[i] - 1;
        }
    }
}

int main(){
    fast_io;

    string s;
    cin >> s;   

    int n = sz(s);
    vector<int> z;
    build_z_array(s, z);

    int resp_sz=0, max_pref=0;

    for(int i=1; i<n; i++){
        if(i+z[i]==n && z[i]<=max_pref){
            resp_sz = z[i];
            break;
        }

        max_pref = max(max_pref, z[i]);
    }

    cout << (resp_sz==0 ? "Just a legend" : s.substr(0, resp_sz)) << endl;

    return 0;
}
