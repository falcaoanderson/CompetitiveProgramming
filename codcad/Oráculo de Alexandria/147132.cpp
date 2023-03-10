// 06/06/19 // 3:40 PM //

#include <iostream>
#include <cstring>

using namespace std;

#define MAXN 110
#define MAXK 30

long long memo[MAXN][MAXK];

long long fatorial(int n, int k){

    if(n<=1) return 1LL;

    if(memo[n][k]>=0) return memo[n][k];

    return memo[n][k] = n * fatorial(n-k, k);
}

int main(){
    memset(memo, -1, sizeof(memo));

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    for(int z=0; z<t; z++){
        string temp;
        int n=0, k=0, pot=1;

        cin >> temp;

        for(int i=temp.size()-1; i>=0; i--){
            if(temp[i]=='!')
                k++;
            else{

                int num = (temp[i]-'0');

                n   += num * pot;
                pot *= 10;
            }
        }

        cout << fatorial(n, k) << "\n";
    }

    return 0;
}
