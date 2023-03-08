// 22/10/20 // 7:22 PM //

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)

int aux_x[10] = {0, 1, 2, 2, 1, -1, -2, -2, -1, 0};
int aux_y[10] = {0, 2, 1, -1, -2, -2, -1, 1, 2, 0};

int main(){
    fast_io;

    int n;
    cin >> n;

    int x=4, y=3, resp=n;

    for(int i=1; i<=n; i++){
        int mov;
        cin >> mov;

        x += aux_x[mov];
        y += aux_y[mov];

        if(resp==n && ((x==1 && y==3)||(x==2 && y==3)||(x==2 && y==5)||(x==5 && y==4)))
            resp = i;
    }

    cout << resp << endl;

    return 0;
}
