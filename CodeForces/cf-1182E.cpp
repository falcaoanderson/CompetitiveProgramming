// 10/06/20 // 2:12 am //

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define int long long

typedef matrix matrix;

const int MOD = (int)(1e9)+7;

void mprint(matrix ma){
    for(int i=0; i<(int)ma.size(); i++){
        for(int j=0; j<(int)ma[0].size(); j++){
            cout << ma[i][j] << " ";
        }
        cout << endl;
    }
}

matrix prod(matrix ma, matrix mb){
    matrix mc((int)ma.size(), vector<int>((int)mb[0].size(), 0));

    for(int i=0; i<(int)ma.size(); i++)
        for(int j=0; j<(int)mb[0].size(); j++)
            for(int k=0; k<(int)mb.size(); k++){
                if(ma[i][k]==0 || mb[k][j]==0 || ma[i][j]==0) continue;

                if(mc[i][j]==0) mc[i][j]=1;
                mc[i][j] *= (ma[i][k]*mb[k][j])%MOD;
                mc[i][j] %= MOD;
            }

    return mc;
}

matrix expo(matrix ma, int n){
    if(n==1) return ma;

    if(n&1)
        return prod(expo(matrix(ma), n-1), ma);
    else
        return expo(prod(ma, ma), n/2);
}

int32_t main(){

    int n, f1, f2, f3, c;
    cin >> n >> f1 >> f2 >> f3 >> c;

    matrix ma = {{1, 1, 1, c},
                 {1, 0, 0, 0},
                 {0, 1, 0, 0},
                 {0, 0, 0, c}};
    matrix mb = {{f3},
                 {f2},
                 {f1},
                 {1}};

    ma = expo(ma, n);

    mprint(ma);
    cout << endl;
    mprint(prod(ma, mb));

    return 0;
}
