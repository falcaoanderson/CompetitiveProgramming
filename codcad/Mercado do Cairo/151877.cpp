// 08/12/19 // 2:28 PM //

#include <bits/stdc++.h>

using namespace std;

#define MAXN 100010
#define MAXD 1010
#define INF 0x3f3f3f3f

int n, t;
int bit[MAXD][MAXD];

void update(int x, int y, int delta){

    for(int i=x; i<MAXD; i+=(i&-i))
        for(int j=y; j<MAXD; j+=(j&-j))
            bit[i][j] = max(bit[i][j], delta);

}

int query(int x, int y){
    int mmax = 0;

    for(int i=x; i>0; i-=(i&-i))
        for(int j=y; j>0; j-=(j&-j))
            mmax = max(mmax, bit[i][j]);

    return mmax;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> t;
    while(t--){
        memset(bit, 0, sizeof(bit));

        cin >> n;

        int maior=0, maior_atual;

        for(int i=1; i<=n; i++){
            int tx, ty;

            cin >> tx >> ty;

            maior_atual = query(tx, ty) + 1;

            update(tx, ty, maior_atual);

            maior = max(maior, maior_atual);
        }

        cout << maior << "\n";
    }

    return 0;
}
