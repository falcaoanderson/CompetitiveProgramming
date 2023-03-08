#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define int long long

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    for(int i=1; i<=n; i++){
        if(i==1) cout << "0" << endl;
        if(i==2) cout << "6" << endl;
        if(i==3) cout << "28"<< endl;
        if(i==4) cout << "96"<< endl;
        if(i<5) continue;

        int total=0;
        total += 4*(i*i-2);
        total += (4*(i-4)+4)*(i*i-4);
        total += 4*(i-4)*(i*i-6);
        total += (i-4)*(i-4)*(i*i-8);
        total += 8*(i*i-3);

        cout << total/2 << endl;
    }

    return 0;
}
