// 30/08/19 // 9:50 PM //

#include <bits/stdc++.h>

using namespace std;

double l, c, r1, r2;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while(cin >> l >> c >> r1 >> r2){
        if(l==0 && c==0 && r1==0 && r2==0) break;

        double k  = r1+r2;
        double k1 = sqrt( (c-k)*(c-k) + (l-k)*(l-k));

        if( (max(r1,r2)*2) > min(l,c) || k1<k)
            cout << "N\n";
        else
            cout << "S\n";
    }

    return 0;
}
