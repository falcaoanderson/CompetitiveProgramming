// 19/04/19 // 11:02 AM //

#include <iostream>

using namespace std;

#define MAXK 50

int n, k, conj=0;
int v[MAXK];

void funcao(long long prod, int qnt, int i){
    if(i>k) return;

    funcao(prod, qnt, i+1);

    prod *= v[i];
    qnt  ++;

    if(prod<=n) funcao(prod, qnt, i+1);


    if(qnt == 0) return;

    if(qnt%2==0)
        conj -= n/prod;
    else
        conj += n/prod;
}

int main(){
    cin >> n >> k;

    for(int i=1; i<=k; i++) cin >> v[i];

    funcao(1,0,1);

    cout << n - conj << "\n";

    return 0;
}
