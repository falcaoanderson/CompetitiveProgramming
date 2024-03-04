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

int main(){
    fast_io;

    int n;
    cin >> n;

    bool finded = 0;
    int resp = 0;
    vector<bool> possible(26, 1);

    while(n--){
        char op;
        string s;
        cin >> op >> s;

        if(n==0) continue;

        if(finded){
            resp += (op!='.');
            continue;
        }

        vector<bool> crr(26, 0);
        for(char c: s) crr[(int)(c-'a')] = 1;

        if(op=='!'){
            for(int i=0; i<26; i++){
                if(possible[i] && !crr[i]) possible[i] = 0;
            }
        }
        if(op=='.' || op=='?'){
            for(int i=0; i<26; i++){
                if(possible[i] && crr[i]) possible[i] = 0;
            }
        }

        int q=0;
        for(int i=0; i<26; i++) q+=possible[i];
        if(q==1) finded = 1;
    }

    cout << resp << endl;
    
    return 0;
}
