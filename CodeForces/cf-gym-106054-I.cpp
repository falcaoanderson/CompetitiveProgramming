/*
31/08/25 

*/

#include <bits/stdc++.h>

using namespace std;

const int INF = 0x3f3f3f3f;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<int> gold(n+1), op(n+1);
    for(int i=0; i<m; i++){
        int x, y;
        cin >> x >> y;

        int aux = 0;
        for(int j=1; j<=n; j++){
            cin >> op[j];

            aux += (op[j]==1);
        }

        if(x/(aux+1)>=y){
            aux++;
            gold[0] += x/aux;
        }
        else{
            gold[0] += y;
        }

        for(int j=1; j<=n; j++){
            if(op[j]==1){
                gold[j] += x/aux;
            }
            else{
                gold[j] += y;
            }
        }
    }

    for(int i=1; i<=n; i++) cout << gold[i] << " ";
    cout << gold[0] << endl;

    return 0;
}