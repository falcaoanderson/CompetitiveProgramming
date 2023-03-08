// 30/05/20 // 6:00 PM //

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

int main(){

    string alfa, frase;
    cin >> alfa >> frase;

    for(char c : frase){
        cout << alfa[c-'a'];
    }
    cout << endl;

    return 0;
}
