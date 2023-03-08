// 14/06/20 // 00:04 PM //

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

const int MAXN = (2e5)+10;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string dna;
    cin >> dna;

    int mcont=1, cont = 1;

    for(int i=1; i<(int)dna.size(); i++){
        if(dna[i]==dna[i-1]) cont++;
        else{
            mcont = max(cont, mcont);
            cont = 1;
        }
    }
    mcont = max(cont, mcont);

    cout << mcont << endl;

    return 0;
}

