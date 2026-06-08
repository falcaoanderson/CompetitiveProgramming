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

    int pos = -1;
    while(pos+1 < s.size() && s[pos+1]<='9' && s[pos+1]>='0'){
        pos++;
    }

    if(pos==-1){
        cout << -1 << endl;
    }
    else{
        for(int i=0; i<=pos; i++){
            cout << s[i];
        }
        cout << endl;
    }

    return 0;
}