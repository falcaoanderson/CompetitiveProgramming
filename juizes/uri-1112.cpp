// 10/12/19 // 10:29 PM //

#include <bits/stdc++.h>

using namespace std;

#define MAXN 1010
#define MAXLOG 20

int comp, larg, p, q;
int bit[MAXN][MAXN];

void update(int x, int y, int delta){

    for(int i=x; i<=comp; i+=(i&-i))
        for(int j=y; j<=larg; j+=(j&-j))
            bit[i][j] += delta;

}

int query(int x, int y){
    int tsum=0;

    for(int i=x; i>0; i-=(i&-i))
        for(int j=y; j>0; j-=(j&-j))
            tsum += bit[i][j];

    return tsum;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while(cin >> comp >> larg >> p && comp!=0){
        memset(bit, 0, sizeof(bit));

        cin >> q;
        comp++; larg++;

        while(q--){
            char op;

            cin >> op;

            if(op=='A'){
                int n, x, y;

                cin >> n >> x >> y;

                x++; y++;

                update(x, y, n);
            }
            else{
                int xi, yi, xf, yf;

                cin >> xi >> yi >> xf >> yf;

                xi++; yi++; xf++; yf++;

                if(xi>xf) swap(xi, xf);
                if(yi>yf) swap(yi, yf);

                cout << p*(query(xf,yf) - query(xf, yi-1) - query(xi-1, yf) + query(xi-1, yi-1)) << "\n";
            }
        }

        cout << "\n";
    }

    return 0;
}
