// 29/05/19 // 4:17 PM//

#include <iostream>

using namespace std;

int n, m;
long long total=0LL;

int main(){

    cin >> n >> m;

    for(int i=1; i<=m; i++){
        int maior=0, menor=0, falta = n-i;

        if(falta>2*m || falta<2)
            continue;

        maior = min(m, falta-1);
        menor = max(1, falta-m);

        total += maior-menor+1;
    }

    cout << total << "\n";

    return 0;
}
