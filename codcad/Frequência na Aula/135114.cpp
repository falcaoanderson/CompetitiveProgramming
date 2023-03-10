#include <iostream>
#include <set>
using namespace std;

int main(){
    set<int> lista;
    int n, temp;

    cin >> n;
    for(int i=0; i<n; i++){
        cin >> temp;
        lista.insert(temp);
    }

    cout << lista.size() << endl;

    return 0;
}
