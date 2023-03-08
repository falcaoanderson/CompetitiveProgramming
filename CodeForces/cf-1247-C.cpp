// 05/07/20 // 9:43 PM //

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

const int MAXL = 30;
const int INF = 0x3f3f3f3f;

int n, p;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> p;

    int resp = INF;

    for(int i=1; i<=30 && 1<=n-i*p; i++){
        int ntemp = n -i*p;

        int cont=0;

        while(ntemp>0){
            ntemp -= (ntemp&-ntemp);
            cont++;
        }

        if(cont<=i && n-i*p>=i) resp = min(resp, i);
    }

    if(resp==INF) cout << -1   << endl;
    else          cout << resp << endl;

    return 0;
}
