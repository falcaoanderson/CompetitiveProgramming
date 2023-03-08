// 08/06/20 // 20:04 PM //

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

const int MAXN = (int)(2e5)+10;

int n, m, k;
int ap[MAXN], tam[MAXN];

int buscab(int ini, int val){
    int fim=m, meio, pos=-1;

    while(ini<=fim){
        meio = (ini+fim)/2;

        if(tam[meio]>=val-k){
            pos = meio;

            fim = meio-1;
        }
        else{
            ini = meio+1;
        }
    }

    return pos;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> k;

    for(int i=1; i<=n; i++) cin >> ap[i];
    for(int i=1; i<=m; i++) cin >> tam[i];

    sort(ap+1, ap+n+1);
    sort(tam+1, tam+m+1);

    int resp = 0, ini=1;

    for(int i=1; i<=n; i++){
        if(ini>m) break;

        int pos = buscab(ini, ap[i]);
        if(pos == -1) break;

        if(tam[pos]<=ap[i]+k){
            resp++;
            ini = pos+1;
        }
        else{
            ini = pos;
        }
    }

    cout << resp << endl;

    return 0;
}
