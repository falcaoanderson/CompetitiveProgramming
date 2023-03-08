// 06/01/20 // 10:00 AM //
// quantidades de numeros com a soma dos digitos == sum //

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 9;

int memo[MAXN + 10][MAXN*9 + 10][5];
int number[MAXN+10];

int solve(int i, int sum, bool limited){
    if(memo[i][sum][limited]!=-1) return memo[i][sum][limited];

    if(sum==0) return memo[i][sum][limited] = 1;
    if(i==0)   return memo[i][sum][limited] = 0;

    int &rmemo = memo[i][sum][limited];

    rmemo = 0;
    int limit = 9;

    if(limited){
        if(number[i]<=sum)
            rmemo += solve(i-1, sum-number[i], 1);

        limit = number[i]-1;
    }


    for(int k=0; k<=limit && k<=sum ; k++)
        rmemo += solve(i-1, sum-k,0);

    return rmemo;
}

int main(){
    memset(memo, -1, sizeof(memo));

    string num;
    int sum;

    cin >> num >> sum;

    int sz = num.size();
    for(int i=0; i<sz; i++)
        number[sz-i] = num[i] - '0';
    for(int i=1; i<=sz; i++) cout << number[i];
    cout << endl;
    cout << solve(sz, sum, 1) << endl;

    return 0;
}
