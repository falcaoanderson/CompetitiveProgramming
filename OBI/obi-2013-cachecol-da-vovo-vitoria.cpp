// 10/06/20 // 1:50 PM //

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
    matrix mc((int)ma.size(), vector<int>((int)mb[0].size()));

    for(int i=0; i<(int)ma.size(); i++)
        for(int j=0; j<(int)mb[0].size(); j++)
            for(int k=0; k<(int)mb.size(); k++){
                mc[i][j] += (ma[i][k]*mb[k][j])%MOD;
	    	mc[i][j] %=MOD;
	    }
    return mc;
}

matrix expo(matrix ma, int n){
    if(n==0){
        for(int i=0; i<(int)ma.size(); i++)
            for(int j=0; j<(int)ma[0].size(); j++){
                if(i==j) ma[i][j] = 1;
                else     ma[i][j] = 0;
            }
        return ma;
    }
    if(n==1) return ma;

    if(n&1)
        return prod(expo(matrix(ma), n-1), ma);
    else
        return expo(prod(ma, ma), n/2);
}

int32_t main(){

    matrix ma = {{3, 2},
                 {2, 2}};
    matrix mb = {{6},
                 {6}};

    int n;
    cin >> n;

    ma = expo(ma, n-1);
    mb = prod(ma, mb);
    mprint(mb);
    cout << (mb[0][0] + mb[1][0])%MOD  << endl;

    return 0;
}
