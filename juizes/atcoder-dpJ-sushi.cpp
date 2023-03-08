// 24/01/20 // 9:53 PM //

#include <bits/stdc++.h>

using namespace std;

const int MAXN = (int)(3e2) + 10;

int n;
double memo[MAXN][MAXN][MAXN];

double solve(int a, int b, int c){
    if(memo[a][b][c]!=-1) return memo[a][b][c];

    if(a==0 && b==0 && c==0) return 0.0;

    double dn=n, da = a, db = b, dc = c;

    memo[a][b][c] = dn/(da+db+dc);
    if(a>0) memo[a][b][c] += da/(da+db+dc) * solve(a-1, b, c);
    if(b>0) memo[a][b][c] += db/(da+db+dc) * solve(a+1, b-1, c);
    if(c>0) memo[a][b][c] += dc/(da+db+dc) * solve(a, b+1, c-1);

    return memo[a][b][c];
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

    for(int x=0; x<=a+b+c; x++)
        for(int y=0; y<=b+c; y++)
            for(int z=0; z<=c; z++)
                memo[x][y][z] = -1;

    cout.precision(10);
    cout.setf(ios::fixed);
    cout << solve(a, b, c) << endl;

    return 0;
}
