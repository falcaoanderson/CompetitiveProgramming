// 26/01/24 //
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
#include <functional>
#include <cmath>

using namespace std;

#define ll long long
#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define PB push_back
#define EB emplace_back
#define FF first
#define SS second

typedef pair<int, int> pii;
typedef tuple<int, int, int> tiii;

const int INF  = 0x3f3f3f3f;
const  ll LINF = 0x3f3f3f3f3f3f3f3f;
const int MAXN = (1e3) + 5;
const int MOD  = (1e9) + 7;

int gab[MAXN];
bool possible[MAXN][10];

int main(){
    fast_io;

    int t;
    cin >> t;

    while(t--){
        int q, m;
        cin >> q >> m;

        memset(gab, 0, sizeof(gab));
        for(int i=1; i<=q; i++)
            for(int j=0; j<4; j++)
                possible[i][j] = 1;

        while(m--){
            for(int i=1; i<=q; i++){
                char a, b;
                cin >> a >> b;

                if(b=='T') 
                    gab[i] = int(a) - int('A') + 1;
                else 
                    possible[i][int(a) - int('A')] = 0;
            }
        }

        for(int i=1; i<=q; i++){
            if(gab[i]!=0) 
                cout << char(int('A') + gab[i] -1);
            else{
                int s=0;
                for(int j=0; j<4; j++) s += (int)(possible[i][j]);

                if(s==1){
                    for(int j=0; j<4; j++){
                        if(possible[i][j])
                            cout << char(int('A') + j);
                    }
                }
                else{
                    cout << '?';
                }
            }

            if(i==q) cout << endl;
            else     cout << " ";
        }
    }

    return 0;
}
