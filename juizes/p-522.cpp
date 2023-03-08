#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    string ns;
    int qnt, ni;
    int v[100000];

    cin >> qnt;
    for(int j=0; j<qnt; j++){
        cin >> ns;

        for(int i=0; i<ns.size(); i++){
            v[i] = ns[i] - '0';
        }
        sort(v,v + ns.size());

        cout << "Caso " << j+1 << ": ";
        for(int i=ns.size()-1; i>=0; i--){
            cout << v[i];
        }
        cout << endl;
    }
    return 0;
}
