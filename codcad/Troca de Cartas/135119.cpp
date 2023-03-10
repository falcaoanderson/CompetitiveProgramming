#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

int main(){
    set<int> a_cartas, b_cartas;
    int temp, ca, cb, max_a=0, max_b=0;

    cin >> ca >> cb;

    for(int i=0; i<ca; i++){
        cin >> temp;
        a_cartas.insert(temp);
    }
    for(int i=0; i<cb; i++){
        cin >> temp;
        b_cartas.insert(temp);
    }

    set<int>::iterator it;

    for(it=a_cartas.begin(); it!=a_cartas.end(); it++){
        if(b_cartas.find(*it)==b_cartas.end())
            max_a++;
    }

    for(it=b_cartas.begin(); it!=b_cartas.end(); it++){
        if(a_cartas.find(*it)==a_cartas.end())
            max_b++;
    }

    cout << min(max_a, max_b) << endl;

    return 0;
}
