#include <iostream>
#include <queue>
using namespace std;


int main(){  // master kung =1 // master lu = 9//
    int temp, temp_2;
    queue<int> campeonato;

    for(int i=0; i<16; i++){
        cin >> temp;
        campeonato.push(temp);
    }

    for(int i=1; i<=15; i++){
        temp=campeonato.front();
        campeonato.pop();

        temp_2=campeonato.front();
        campeonato.pop();

        if((temp==1 and temp_2==9) or (temp==9 and temp_2==1)){
            if(i<=8)      cout << "oitavas\n";
            else if(i<=12)cout << "quartas\n";
            else if(i<=14)cout << "semifinal\n";
            else          cout << "final\n";
            break;
        }
        else if(temp==1 or temp==9)
            campeonato.push(temp);
        else if(temp_2==1 or temp_2==9)
            campeonato.push(temp_2);
        else
            campeonato.push(temp);
    }

    return 0;
}
