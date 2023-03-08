// 14/06/20 // 00:04 PM //

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define int long long

const int MAXN = (2e5)+10;

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, cont=0, ant=-1;
    cin >> n;

    while(n--){
        int temp;
        cin >> temp;

        if(temp>=ant){
            ant = temp;
            continue;
        }

        cont += ant-temp;
    }

    cout << cont << endl;

    return 0;
}

