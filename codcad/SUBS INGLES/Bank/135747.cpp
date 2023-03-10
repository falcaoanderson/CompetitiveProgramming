#include <iostream>
#include <queue>
using namespace std;

int c, n, t, d, tempo=0, total=0;
priority_queue< int, vector<int>, greater<int> > atendentes;

int main(){
    cin >> c >> n;
    for(int i=0; i<c; i++) atendentes.push(0); // adiciono os atendentes

    for(int i=0; i<n; i++){
        cin >> t >> d;

        if(t>tempo)
            tempo=t;

        if(tempo >= atendentes.top()){ // se eu posso ser atendido
            if(tempo-t>20) total++;
            atendentes.pop();
            atendentes.push(tempo+d);
        }
        else{                          // se eu tenho que esperar
            tempo=atendentes.top();
            if(tempo-t>20) total++;
            atendentes.pop();
            atendentes.push(tempo+d);
        }
    }

    cout << total << endl;


    return 0;
}
