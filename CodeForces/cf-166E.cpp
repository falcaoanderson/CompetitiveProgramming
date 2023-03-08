// 10/06/20 // 00:25 PM //

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define int long long

typedef matrix matrix;

const int MOD = (int)(1e9)+7;

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
    if(n==1) return ma;

    if(n&1)
        return prod(expo(matrix(ma), n-1), ma);
    else
        return expo(prod(ma, ma), n/2);
}

int32_t main(){

    matrix ma = {{0, 1, 1, 1},
				 {1, 0, 1, 1},
				 {1, 1, 0, 1},
                 {1, 1, 1, 0}};
	int n;
	cin >> n;
    
	if(n==1) cout << 0 << endl;
	else{
		cout << expo(ma, n)[0][0] << endl;
	}

    return 0;
}
