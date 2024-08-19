/*
19/08/24 
Problem: 
Complexity:
*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define sz(x) (int)(x).size()

ll memo[17+5][10+5][2+5];
string limiar;

ll solve(int i, int last, bool flag){
    if(memo[i][last][flag]!=-1LL){
        return memo[i][last][flag];
    }

    if(i==sz(limiar)){
        return memo[i][last][flag] = 1LL;
    }

    int l = (int)(limiar[i]-'0');
    memo[i][last][flag] = 0LL;

    for(int k=0; k<=9; k++){
        if(flag && k>l) break;
        if(k==last) continue;

        if(flag && k==l){
            memo[i][last][flag] += solve(i+1, k, 1);
        }
        else if(k==0 && last==10){
            memo[i][last][flag] += solve(i+1, 10, 0);
        }
        else{
            memo[i][last][flag] += solve(i+1, k, 0);
        } 
    }

    return memo[i][last][flag];
}

int main(){
    fast_io;

    string a, b;
    cin >> a >> b;

    memset(memo, -1, sizeof(memo)); 
    limiar = b;
    ll resp = solve(0, 10, 1); 
    
    memset(memo, -1, sizeof(memo));
    limiar = a;
    resp -= solve(0, 10, 1) - 1; 

    for(int i=1; i<sz(a); i++){
        if(a[i]==a[i-1]){
            resp--;
            break;
        }
    }

    cout << resp << endl;

    return 0;
}
