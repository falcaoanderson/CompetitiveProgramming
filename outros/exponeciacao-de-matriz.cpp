#include <bits/stdc++.h>

using namespace std;

#define int long long

const int MAXN = 10;
const int MOD  = (int)(1e9) + 7;

vector<vector<int>> prod(vector<vector<int>> m1, vector<vector<int>> m2){
    vector<vector<int>> ma = {{0, 0}, {0, 0}};

    for(int i=0; i<2; i++)
        for(int j=0; j<2; j++)
            for(int z=0; z<2; z++)
                ma[i][j] = (ma[i][j] + m1[i][z] * m2[z][j])%MOD;

    return ma;
}

vector<vector<int>> exp1(vector<vector<int>> ma, int n){
    vector<vector<int>> tma = ma;

    for(int p=1; p<n; p++){
       tma = prod(tma, ma);
    }

    return tma;
}

vector<vector<int>> exp2(vector<vector<int>> ma, int n){
    if(n==1) return ma;

    if(~n&1)
        return exp2(prod(ma, ma), n/2);
    else
        return prod(ma, exp2(prod(ma, ma), n/2));
}

void printM(vector<vector<int>> ma){
    for(int i=0; i<2; i++){
        for(int j=0; j<2; j++){
            cout << ma[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int32_t main(){

    vector<vector<int>> m1 = {{0, 1},{1, 1}};

    printM(m1);

    m1 = exp1(m1, 5);

    printM(m1);

    return 0;
}
