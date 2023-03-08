// 05/10/20 // 10:14 PM //

#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string letras;
    cin >> letras;

    set<string> ant;
    string atual = letras;
    int cont=0;

    while(true){
        cont++;
        ant.insert(atual);

        next_permutation(atual.begin(), atual.end());

        if(atual==letras) break;
    }

    cout << cont << endl;
    for(string temp: ant)
        cout << temp << endl;

    return 0;
}
