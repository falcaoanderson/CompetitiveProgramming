#include <iostream>
#include <set>
using namespace std;

int main(){
    set<int> estoque;
    int n, temp, total=0;

    cin >> n;

    for(int i=0; i<n; i++){
        cin >> temp;

        if(estoque.find(temp)!=estoque.end()) // se eu tenho esse modelo
            estoque.erase(temp);
        else{
            estoque.insert(temp);
            total+=2;
        }
    }

    cout << total << endl;

    return 0;
}
