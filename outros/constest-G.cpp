#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define int long long

const int MAXN = 12 + 5+100;
int memo[MAXN][MAXN][2];

int solve(int i, int sum, int limited, string number){
    int &rmemo = memo[i][sum][limited];


    if(rmemo!=-1) return rmemo;

    if(i==(int)number.size()) return rmemo = sum;

    int limit = 9;
    rmemo = 0;

    if(limited){
        int digit = number[i]-'0';

        rmemo += solve(i+1, sum+(digit==1||digit==7), 1, number);

        limit = digit - 1;
    }

    for(int k=0; k<=limit; k++)
        rmemo += solve(i+1, sum+(k==1||k==7), 0, number);

    return rmemo;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    memset(memo, -1, sizeof(memo));

    string number;
    cin >> number;

    cout << solve(0, 0, 1, number) << endl;

    return 0;
}
