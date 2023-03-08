// 12/06/20 // 7:03 PM //

#include<bits/stdc++.h>

using namespace std;

#define endl "\n"
#define int long long

const int MAXN = (int)(1e5) + 10;

int c, t;
int raio[MAXN];

int buscab(int x){
    int ini=1, fim=c, meio;
    int cont = -1;

    while(ini<=fim){
        meio = (ini+fim)/2;

        if(x<=raio[meio]){
            cont = meio;
            fim  = meio-1;
        }
        else{
            ini = meio+1;
        }
    }

    return (cont==-1? 0: c-cont+1);
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> c >> t;

    for(int i=1; i<=c; i++){
        cin >> raio[i];
        raio[i] *= raio[i];
    }

    int cont = 0;

    while(t--){
        int x, y, dist;
        cin >> x >> y;

        cont += buscab(x*x+y*y);
    }

    cout << cont << endl;

    return 0;
}

