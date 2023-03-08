// 23/01/20 // 11:34 AM //

#include <bits/stdc++.h>

using namespace std;

const int MAXN = (int)(3e3)+2;

int n;
double p, memo[2][MAXN];

int main(){

    cin >> n;

    for(int i=0; i<=n; i++){
        if(i>0)
            cin >> p;
        for(int j=0; j<=n; j++){
            if(i==0){
                if(2*(n-j)<n) memo[0][j] = 0;
                else memo[0][j] = 1;
            }
            else
                memo[i&1][j] = p*memo[~i&1][j-1] + (1-p)*memo[~i&1][j];
        }
    }


    cout.precision(10);
    cout.setf(ios::fixed);
    cout << memo[n&1][n]<< endl;

    return 0;
}
