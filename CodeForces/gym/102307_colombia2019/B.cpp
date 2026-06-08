/*
26/01/26

*/

#include <bits/stdc++.h>

using namespace std;

#define fast_io ios_base::sync_with_stdio(false);cin.tie(nullptr)
#define endl "\n"
#define FF first
#define SS second
#define PB push_back
#define EB emplace_back

using ll = long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;

// const int MAXVAL = 1e6 + 5;
const int MAXN = 1e5 + 5;

int main(){
    fast_io;

    string s;
    cin >> s;

    int n = s.size();
    int pos = -1;

    for(int st=0; st<n; st++){
        bool flag = 1;
        for(int i=st; i<n+st-i-1 && flag; i++){
            flag = (s[i] == s[n+st-i-1]);
        }

        if(flag){
            pos = st;
            break;
        }
    }

    cout << s;
    for(int i=pos-1; i>=0; i--) cout << s[i];
    cout << endl;


    return 0;
}