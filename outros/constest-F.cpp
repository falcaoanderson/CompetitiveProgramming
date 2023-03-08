// 04/01/20 // 21:36 PM //

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define _USE_MATH_DEFINES

const double pi = 3.1415926535897932;
const double e =  2.7182818284590452;

int main(){
    fastio;

    int n;

    cin >> n;

    if(n<=1){
        cout << 1 << endl;
    }
    else{
        double x = ((n * log10(n / e) +  log10(2 * pi * n) /2.0));

        long long resp = floor(x)+1;

        cout << resp << endl;
    }

    return 0;
}
