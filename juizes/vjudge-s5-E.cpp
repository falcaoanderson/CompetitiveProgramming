// 03/07/23 //
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <tuple>
#include <cstring>
#include <stack>

using namespace std;

#define ll long long
#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define PB push_back
#define EB emplace_back
#define ff first
#define ss second

typedef pair<int, int> pii;
typedef tuple<int, int, int> tiii;

const int INF  = 0x3f3f3f3f;
const int MAXN = 30 + 5;
const int MOD  = (1e9) + 7;

string s, gab="welcome to code jam";
int memo[MAXN][MAXN];

int solve(int i, int j){
    if(memo[i][j]!=-1) return memo[i][j];
    
    if(j==19) return 1;
    if(i==(int)s.size()) return 0;

    memo[i][j] = solve(i+1, j);
    if(s[i]==gab[j]) memo[i][j] += solve(i+1, j+1);
    
    return memo[i][j] %= 1000;
}

int main(){
    //fast_io;
    
    int t;
    cin >> t;

    getchar();
    for(int i=1; i<=t; i++){
        getline(cin, s);
        
        memset(memo, -1, sizeof(memo));
        int resp = solve(0, 0);

        cout << "Case #" << i << ": ";
        if((resp/1000) != 0)   cout << resp << endl;
        else if((resp/100)!=0) cout << "0" << resp << endl;
        else if((resp/10)!=0)  cout << "00" << resp << endl;
        else                   cout << "000" << resp << endl;
    }

    return 0;
}
