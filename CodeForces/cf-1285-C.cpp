// 17/01/20 // 12:50 PM //

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define pb push_back
#define mp make_pair
#define int long long

const int INF = 0x3f3f3f3f3f3f3f3f;

int32_t main(){
    fastio;

    vector<int> fator;
    int x;

    cin >> x;

    for(int i=2; i*i<=x; i++){
        if(x%i==0){
            int temp = 1;

            while(x%i==0){
                temp *= i;
                x   /= i;
            }

            fator.pb(temp);
        }
    }
    if(x!=1) fator.pb(x);
    int sz = fator.size();
    int a=INF, b=INF;

    for(int i=0; i<=(1<<sz); i++){
        int ta=1, tb=1;

        for(int j=0; j<sz; j++){
            if(i & (1<<j)) ta *= fator[j];
            else           tb *= fator[j];
        }

        if(max(ta, tb)<max(a, b)){
            a = ta;
            b = tb;
        }
    }

    cout << a << " " << b << endl;

    return 0;
}
