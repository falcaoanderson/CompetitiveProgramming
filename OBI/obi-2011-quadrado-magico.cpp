// 20/10/20 // 18:46 PM //

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define pb push_back
#define mp make_pair
#define int long long

const int INF  = 0x3f3f3f3f;
const int MAXN = (1e3) + 10;
const int MAXNUM = (1e6) + 10;

int n, linha[MAXN], coluna[MAXN], diagonal;
bool num[MAXNUM];

int32_t main(){
    fast_io;

    cin >> n;

    bool magico = 1;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            int temp;
            cin >> temp;

            linha[i]  += temp;
            coluna[j] += temp;
            if(i==j) diagonal += temp;

            if(temp>n*n || num[temp])
                magico = 0;
            else
                num[temp] = 1;
        }
    }

    if(!magico || diagonal!=linha[1]){
        cout << 0 << endl;
        return 0;
    }

    for(int i=1; i<=n; i++)
        if(linha[i]!=linha[1] || linha[i]!=coluna[i]) magico = false;

    if(magico)
        cout << linha[1] << endl;
    else
        cout << 0 << endl;

    return 0;
}

