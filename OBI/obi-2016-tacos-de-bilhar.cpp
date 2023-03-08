// 07/03/20 // 11:18 PM //

#include <bits/stdc++.h>

using namespace std;

const int MAXN = (int)1e6 + 10;

int c;
bool estoque[MAXN];

int main(){
    cin >> c;

    int resp = 0;
    for(int i=0; i<c; i++){
        int temp;

        cin >> temp;

        if(estoque[temp]==true){
            estoque[temp] = false;
        }
        else{
            estoque[temp] = true;
            resp += 2;
        }
    }

    cout << resp << endl;

    return 0;
}
