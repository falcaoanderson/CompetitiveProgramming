#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    float tconta,tatual=0;
    int n;

    cin >> tconta >> n;
    pair<float,string>v[n];

    for(int i=0; i<n; i++){
        cin >> v[i].second >> v[i].first;

        tatual+=v[i].first;
    }
    sort(v , v+n);

    cout.precision(1);
    cout.setf(ios::fixed);

    cout << v[n-1].second << " pagou R$ " << v[n-1].first << endl;

    float saldo = tatual - tconta;

    if(saldo>0){
        cout << "Valor excedente: sobra R$ " << saldo <<endl;
    }
    else{
        cout << "Valor insuficiente: falta R$ " << saldo*-1;
    }

    return 0;
}
