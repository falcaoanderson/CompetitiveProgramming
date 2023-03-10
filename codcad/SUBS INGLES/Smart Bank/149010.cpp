// 05/08/19 // 10:22 PM //

#include <iostream>

using namespace std;

#define MAXC 10
#define MAXS 5010

int s, qnt[MAXC], val[MAXC]={0, 2, 5, 10, 20, 50, 100, 0, 0, 0};
long long memo[MAXC][MAXS];

void solve(){

    for(int i=0; i<=6; i++)
        memo[i][0] = 1LL;

    for(int i=1; i<=6; i++){
        for(int j=1; j<=s; j++){
            for(int k=0; k<=qnt[i]; k++){

                int temp = j - k*val[i];
                if(temp>=0)
                    memo[i][j] += memo[i-1][temp];
                else
                    break;

            }
        }
    }

}

int main(){


    cin >> s;
    for(int i=1; i<=6; i++)
        cin >> qnt[i];

    solve();

    cout << memo[6][s] << "\n";

    return 0;
}
