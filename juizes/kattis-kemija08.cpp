/*
05/03/24 
Problem: Kattis - Kemija08
Complexity: O(N)
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
    while(cin>>s){
        int pass = 0;
        for(char c: s){
            if(pass){
                pass--;
                continue;
            }

            cout << c;
            if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u') pass=2;
        }
        cout << " ";
    }
    cout << endl;

    return 0;
}
