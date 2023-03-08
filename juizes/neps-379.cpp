// 06/06/19 // 8:23 PM //

#include <iostream>

using namespace std;

#define MAXN 210

int n, k;
int mask[MAXN];

int funcao(int i, int uniao, int iterc, int qnt){

}

int main(){

    cin >> n >> k;

    for(int i=1; i<=n; i++){
        int qnt, bit;

        cin >> qnt;

        for(int j=0; j<qnt; j++){
            cin >> bit;

            mask[i] |= (1<<(bit-1));
        }
        cout << mask[i] << "\n";
    }



    return 0;
}
