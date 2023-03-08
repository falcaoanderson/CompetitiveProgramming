// 06/01/20 // 4:16 PM //

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

int const MAXN = 7 + 5;
int const MAXP = 9*7+5;

int memo[MAXN][MAXN*9][2];
bool composto[MAXP];

void crivo(){
    composto[1] =  composto[0]  = 1;

    for(int i=2; i*i<MAXP; i++)
        if(!composto[i])
            for(int j=i*i; j<MAXP; j+=i)
                composto[j] = 1;
}

int solve(int i, int sum, int limited, string number, int sz){
    int &rmemo = memo[i][sum][limited];

    if(rmemo!=-1) return rmemo;

    if(i==sz) return rmemo = !composto[sum];

    int limit = 9;
    rmemo = 0;

    if(limited){
        int cdigit = number[i]-'0';

        rmemo += solve(i+1, sum+cdigit, 1, number, sz);
        limit = cdigit-1;
    }

    for(int k=0; k<=limit; k++)
        rmemo += solve(i+1, sum+k, 0, number, sz);

    return rmemo;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    crivo();

    int t;
    cin >> t;

    while(t--){
        int tempA, tempB;
        cin >> tempA >> tempB;

        if(tempB<tempA) swap(tempA, tempB);
        tempA--;

        int resp = 0;

        if(tempB>0){
            memset(memo, -1, sizeof(memo));
            resp += solve(0, 0, 1, to_string(tempB), log10(tempB)+1);
        }
        if(tempA>0){
            memset(memo, -1, sizeof(memo));
            resp -= solve(0, 0, 1, to_string(tempA), log10(tempA)+1);
        }

        cout << resp << endl;
    }

    return 0;
}
