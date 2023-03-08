// 15/02/19 // 9:53 PM //

#include <iostream>

using namespace std;

int main(){

    char letra;
    string frase, temp;

    cin >> letra;
    getchar();
    getline(cin, temp);
    frase = " " + temp + " ";

    bool tem=false;
    float cont = 0, total = 0;

    for(int i=1; i<=frase.size(); i++){

        if(frase[i]==' ' && frase[i-1]!=' '){
            total++;
            if(tem) cont++;
            tem = false;
        }

        if(frase[i]==letra) tem = true;

    }

    cout.precision(1);
    cout.setf(ios::fixed);

    cout << 100*(cont/total) << "\n";

    return 0;
}
