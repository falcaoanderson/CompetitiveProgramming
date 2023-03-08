// 22/04/19 // 9:10 PM //

#include <iostream>
#include <queue>

using namespace std;

queue<int> fila;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for(int i=0; i<16; i++){
        int temp;
        cin >> temp;
        fila.push(temp);
    }

    for(int i=1; i<=15; i++){
        int a, b;

        a = fila.front();
        fila.pop();
        b = fila.front();
        fila.pop();

        if( (a==1 && b==9) || (a==9 && b==1)){
            if(i<9)
                cout << "oitavas\n";
            else if(i<13)
                cout << "quartas\n";
            else if(i<15)
                cout << "semifinal";
            else
                cout << "final";

            break;
        }
        else if(a==1 || a==9)
            fila.push(a);
        else
            fila.push(b);
    }

    return 0;
}
