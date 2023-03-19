#include <iostream>
#include <vector>

using namespace std;

#define endl "\n"
#define ll long long

const int MAXN_1 = 10;
const int MAXN_2 = 20;

int n;
bool ma[MAXN_1][MAXN_1], col[MAXN_1], dig1[MAXN_2], dig2[MAXN_2];

int solve(int i){
    if(i>=8){
        return 1;
    }

    int resp = 0;

    for(int j=0; j<8; j++){
        if(ma[i][j] && !col[j] && !dig1[ i-j+7 ] && !dig2[ i+j ]){
            col[j] = dig1[ i-j+7 ] = dig2[ i+j ] = 1;
            resp += solve(i+1);
            col[j] = dig1[ i-j+7 ] = dig2[ i+j ] = 0;
        }
    }

    return resp;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
            char temp;
            cin >> temp;

            ma[i][j] = (temp=='.');
        }
    }

    cout << solve(0) << endl;

    return 0;
}