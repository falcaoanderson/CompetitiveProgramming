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
    string code;
    cin >> s >> code;
    
    vector<bool> flag(3);

    for(int i=0; i<(int)s.size(); i++){
        char c = s[i];

        if(!flag[0] && c-'a'==code[0]-'A'){
            flag[0]=1;
        }
        else if(flag[0] && !flag[1] && c-'a'==code[1]-'A'){
            flag[1]=1;
        }
        else if(flag[1] && c-'a'==code[2]-'A'){
            flag[2]=1;
        }
        
        if(flag[1] && code[2]=='X'){
            flag[2]=1;
        }
    }

    cout << (flag[2]?"Yes":"No") << endl;

    return 0;
}
