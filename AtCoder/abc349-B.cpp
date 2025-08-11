/*
11/08/25 

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

    string s;
    cin >> s;

    vector<int> v(26), freq(101);
    for(char c: s){
        v[c-'a']++;
    }

    bool resp = 1;
    for(int x: v){
        freq[x]++;
    }

    for(int i=1; i<=100 && resp; i++){
        resp = (freq[i]==0 || freq[i]==2);
    }

    cout << (resp?"Yes":"No") << endl;

    return 0;
}
