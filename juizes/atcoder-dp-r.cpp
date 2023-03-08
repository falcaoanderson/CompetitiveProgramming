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

void mprint(matrix ma){
    for(int i=0; i<(int)ma.size(); i++){
        for(int j=0; j<(int)ma[0].size(); j++){
            cout << ma[i][j] << " ";
        }
        cout << endl;
    }
}

int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);	

   	int n, k;
	cin >> n >> k;
    
	matrix ma(n, vector<int>(n));
	
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			cin >> ma[i][j];	

	ma = expo(ma, k);

	int resp = 0;
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++){
			resp += ma[i][j];
			resp %= MOD;		
		}

	cout << resp << endl;

    return 0;
}
