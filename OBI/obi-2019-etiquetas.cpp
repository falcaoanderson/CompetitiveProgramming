// 21/09/19 // 1:48 PM //

#include <bits/stdc++.h>

using namespace std;

#define MAXN 10010
#define MAXK 10010
#define INF 0x3f3f3f3f

int n, k, c;
int prefix[MAXN];

int memo[MAXN][MAXK];

int solve(int i, int fit){
    if(memo[i][fit]!=-INF) return memo[i][fit];


    if(fit==0 || i>n) return memo[i][fit] = 0;
    if(fit*c == n-i+1) return memo[i][fit] = prefix[n] - prefix[i-1];

    return memo[i][fit] = min(solve(i+1, fit), solve(i+c, fit-1) + prefix[i+c-1] - prefix[i-1]);
}

int main(){

    for(int i=0; i<=MAXN-10; i++){
        for(int j=0; j<=MAXN-10; j++){
            memo[i][j] = -INF;        
        }    
    }

    cin >> n >> k >> c;

    for(int i=1; i<=n; i++){
        cin >> prefix[i];
   
        prefix[i] += prefix[i-1];
    }


    int tempp = prefix[n] - solve(1, k);

    cout << tempp << "\n";


    return 0;
}