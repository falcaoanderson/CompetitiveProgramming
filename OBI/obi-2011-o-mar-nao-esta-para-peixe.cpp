// 21/10/20 // 4:48 PM //

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)

const int MAXN = 110;

int ma[MAXN][MAXN];

int main(){
    fast_io;

    int n;
    cin >> n;
    while(n--){
        int xi, xf, yi, yf;
        cin >> xi >> xf >> yi >> yf;

        for(int i=xi; i<xf; i++)
            for(int j=yi; j<yf; j++)
                ma[i][j] = 1;
    }

    int resp = 0;
    for(int i=1; i<=100; i++)
        for(int j=1; j<=100; j++)
            if(ma[i][j]==1) resp++;

    cout << resp << endl;

    return 0;
}

