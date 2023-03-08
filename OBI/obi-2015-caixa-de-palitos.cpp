// 26/05/19 // 8:10 PM //

#include <iostream>

using namespace std;

int main(){
    int n, m;
    long long total = 0LL;

    cin >> n >> m;

    for(int i=1; i<=m; i++){
        int menor, maior, falta;

        falta = n - i;

        if(falta>2*m || falta<2) continue;

        menor = max(falta-m, 1);
        maior = min(m, falta-1);

        total += (maior-menor+1);
    }

    cout << total << "\n";

    return 0;
}
