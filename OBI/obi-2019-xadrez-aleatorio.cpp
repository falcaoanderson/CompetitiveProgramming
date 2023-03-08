// 22/03/2020/ 3:11 PM //

#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main(){
    int n, t;
    cin >> n >> t;

    if(t==0){
        cout << n << endl;
    }
    else if(t==1){
        cout << n*(n-1) << endl;
    }
    else{
        int resp = 0;
        for(int i=1; i<=n-2; i++)
            for(int j=i+1; j<=n-1; j++)
                resp += n-j;

        cout << resp << endl;
    }

    return 0;
}
