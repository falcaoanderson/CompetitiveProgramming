// 10/04/2019 // 6:11 PM //

#include <iostream>

using namespace std;

#define MAXN 110

int n, c, m, total=0;
bool eh_carimbada[MAXN];
bool ja_tenho[MAXN];


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> c >> m;

    for(int i=0; i<c; i++){
        int temp;
        cin >> temp;

        eh_carimbada[temp] = 1;
    }

    for(int i=0; i<m; i++){
        int temp;
        cin >> temp;

        if(eh_carimbada[temp]==1 && ja_tenho[temp]==0){
            ja_tenho[temp] = 1;
            total++;
        }
    }

    cout << c - total << "\n";

    return 0;
}
