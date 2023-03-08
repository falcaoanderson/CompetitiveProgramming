
// 24/01/20 // 9:53 PM //

#include <bits/stdc++.h>

using namespace std;

const int MAXN = (int)(3e2) + 10;

int n;
double memo[MAXN][MAXN][2];

void solve(int x, int y, int z){
    for(int c=0; c<=z; c++)
        for(int b=0; b<=y+z; b++)
            for(int a=0; a<=x+y+z; a++){
                if(a+b+c>n || (a==0 && b==0 && c==0)) continue;

                double& estado = memo[a][b][c&1];
                double dn=n, da = a, db = b, dc = c;

                estado = dn;
                if(a>0) estado += da * memo[a-1][b][c&1];
                if(b>0) estado += db * memo[a+1][b-1][c&1];
                if(c>0) estado += dc * memo[a][b+1][~c&1];

                estado /= (da+db+dc);
            }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    int a=0, b=0, c=0;
    for(int i=0; i<n; i++){
        int temp;
        cin >> temp;

        a += (temp==1);
        b += (temp==2);
        c += (temp==3);
    }

    solve(a, b, c);

    cout.precision(10);
    cout.setf(ios::fixed);
    cout << memo[a][b][c&1] << endl;

    return 0;
}
