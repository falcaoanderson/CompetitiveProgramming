// 20/10/20 // 5:17 PM //

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)

const int MAXN = 110;

int ma[MAXN][MAXN];

int main(){
    fast_io;

    int n, k;
    cin >> n >> k;

    while(k--){
        int x, y, d;
        cin >> x >> y >> d;

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(abs(x-i)+abs(y-j)==d)
                    ma[i][j]++;
            }
        }
    }

    int x, y, maior=-1, qnt=0;

    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++){
            if(ma[i][j]>maior){
                maior = ma[i][j];
                x = i;
                y = j;
                qnt = 1;
            }
            else if(ma[i][j]==maior)
                qnt++;
        }

    if(qnt==1)
        cout << x << " " << y << endl;
    else
        cout << "-1 -1" << endl;

    return 0;
}
