// 11/12/19 // 10:04 PM //

#include <bits/stdc++.h>

using namespace std;

#define MAXN 1010

int n, m;
int bit[MAXN][MAXN];

void update(int x, int y){
    for(int i=x; i<=n; i+=(i&-i))
        for(int j=y; j<=n; j+=(j&-j))
            bit[i][j]++;
}
int query(int x, int y){
    int tsum = 0;

    for(int i=x; i>0; i-=(i&-i))
        for(int j=y; j>0; j-=(j&-j))
            tsum += bit[i][j];

    return tsum;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    while(cin >> n >> m){
        memset(bit, 0, sizeof(bit));

        for(int i=1; i<=n; i++)
            for(int j=1; j<=n; j++){
                int num;
                cin >> num;

                if(num) update(i, j);
            }


        for(int i=0; i<m; i++){
            int xi, yi, xf, yf;

            cin >> xi >> yi;
            update(xi, yi);

            cin >> xi >> yi >> xf >> yf;

            cout << (query(xf, yf) - query(xf, yi-1) - query(xi-1, yf) + query(xi-1, yi-1)) << "\n";
        }
    }

    return 0;
}
