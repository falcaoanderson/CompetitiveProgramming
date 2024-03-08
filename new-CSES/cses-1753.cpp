/*
08/03/24 
Problem: CSES 1753 - String Matching
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
const int MAXN = (2e5) + 5;
const int MOD  = (1e9) + 7;

vector<int> build_z_array(string &s){
    int n = sz(s);
    vector<int> z(n);
    int l=0, r=0;

    for(int i=1; i<n; i++){
        z[i] = min(z[i-l], r-i+1);
        z[i] = max(0, z[i]);

        while(i+z[i]<n && s[i+z[i]]==s[z[i]]){
            l = i;
            z[i]++;
            r = i+z[i]-1;
        }
    }

    return z;
}

int main(){
    fast_io;

    string s1, s2;
    cin >> s1 >> s2;

    s1 = s2 + " " + s1;

    vector<int> z = build_z_array(s1);

    int sz2 = sz(s2), resp = 0;
    for(int i: z) resp += (i==sz2);

    cout << resp << endl;

    return 0;
}
