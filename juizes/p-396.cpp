#include <iostream>
using namespace std;

int main(){
    int car,casas=0;
    float total=0;

    while(true){
        cin >> car;

        if(car==999){break;}

        if(car>2){
            total+=(car-2)*12.89;
            casas++;
        }
    }
    cout.precision(2);
    cout.setf(ios::fixed);

    cout << total << endl << casas << endl;

    return 0;
}
