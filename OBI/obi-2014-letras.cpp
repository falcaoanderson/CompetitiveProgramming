// 07/06/20 // 8:43 PM //

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

int main(){
    char letra;
    string texto;

    cin >> letra;
    getchar();
    getline(cin, texto);

    double total=0, x=0;

    double flag=0;
    for(int i=0; i<(int)texto.size(); i++){
        if(texto[i]==letra) flag = 1;
        if(texto[i]==' '){
            total++;
            x += flag;

            flag = 0;
        }
    }
    total++; x+=flag;

    double resp = 100*x/total;

    cout.precision(1);
    cout.setf(ios::fixed);
    cout << resp << endl;

    return 0;
}
