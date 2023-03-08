#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)

const int INF  = 0x3f3f3f3f;
const int MAXN = (5e2) + 5;

int n, m1, m2;
int primeira[MAXN], segunda[MAXN];
int memo[2][MAXN][MAXN];

int max(int a, int b, int c, int d){
    return max(max(a,b), max(c, d));
}

int main(){
    fast_io;

    cin >> n;

    cin >> m1;
    for(int i=1; i<=m1; i++)cin >> primeira[i];
    cin >> m2;
    for(int i=1; i<=m2; i++)cin >> segunda[i];

    for(int i=n+1; i>=1; i--)
        for(int ind1=m1+1; ind1>=1; ind1--)
            for(int ind2=m2+1; ind2>=1; ind2--){
                int& ans = memo[i&1][ind1][ind2];

                if(ind1>m1 && ind2>m2) ans = 0;
                else if(n-i<m1-ind1 || n-i<m2-ind2) ans = -INF;
                else
                    ans = max(memo[~i&1][ind1+1][ind2+1]+primeira[ind1]*segunda[ind2],
                          memo[~i&1][ind1+1][ind2], memo[~i&1][ind1][ind2+1], memo[~i&1][ind1][ind2]);
            }

            

    cout << memo[1][1][1] << endl;

    return 0;
}

