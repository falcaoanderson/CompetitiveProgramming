// 02/11/20 // xx:xx PM //

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)

const int MAXN = (5e3) + 10;

string sa, sb;
int ta, tb, memo[MAXN][MAXN];

int min(int a, int b, int c){return min(a, min(b, c));}

int main(){
    fast_io;
    
    cin >> sa >> sb;
    ta = sa.size();
    tb = sb.size();
    sa = " " + sa;
    sb = " " + sb;

    for(int i=1; i<=ta; i++) memo[i][0] = i;
    for(int i=1; i<=tb; i++) memo[0][i] = i;
    
    for(int i=1; i<=ta; i++){
        for(int j=1; j<=tb; j++){
            if(sa[i]==sb[j]) memo[i][j] = memo[i-1][j-1];
            else memo[i][j] = min(memo[i][j-1], memo[i-1][j], memo[i-1][j-1]) + 1;
        }
    }

    cout << memo[ta][tb] << endl;

    return 0;
}
