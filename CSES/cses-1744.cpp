// 01/11/20 // xx:xx PM //

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define pb push_back
#define mp make_pair
#define ll long long
//#define int long long

typedef pair<int, int> pii;

const int INF  = 0x3f3f3f3f;
const int MAXN = (5e2) + 10;

int memo[MAXN][MAXN];

int main(){
    fast_io;

    int a, b;
    cin >> a >> b;

    for(int i=1; i<=a; i++){
        for(int j=1; j<=b; j++){
            if(i==j) 
                memo[i][j] = 0;
            else{
                memo[i][j] = INF;
                for(int k=1; k<i; k++) memo[i][j] = min(memo[i][j], memo[k][j]+memo[i-k][j]+1);
                for(int k=1; k<j; k++) memo[i][j] = min(memo[i][j], memo[i][k]+memo[i][j-k]+1);
            }
        }
    }

    cout << memo[a][b] << endl;

    return 0;
}
