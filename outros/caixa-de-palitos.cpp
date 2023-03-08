// 04/07/20 // 11:28 PM //

#include <bits/stdc++.h>

using namespace std;

int n, m;

int main(){
    cin >> n >> m;

    long long cont = 0;

    for(int a=1; a<=m; a++){
        int bmin = max(n-a-m, 1);
        int bmax = min(n-a-1, m);

        if(bmax-bmin>=0)
            cont += bmax - bmin + 1;
    }

    cout << cont << endl;

    return 0;
}
