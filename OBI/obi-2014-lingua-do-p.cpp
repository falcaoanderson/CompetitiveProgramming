// 28/05/19 // 6:32 //

#include <iostream>

using namespace std;

int main(){
    string frase;

    getline(cin, frase);

    frase+="  ";

    for(int i=0; i<frase.size()-2; i++){
        if(frase[i]=='p'){
            if(frase[i+1]=='p'){
                cout << "p";
                i++;
            }
            continue;
        }
        cout << frase[i];
    }
    cout << "\n";

    return 0;
}
