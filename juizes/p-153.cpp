#include <iostream>
using namespace std;

int main(){
    int n;
    float maior=0,temp;
    cin >> n;
    float v[n],vc[n];

    for(int i=0; i<n; i++){
        cin >> v[i];
    }
    for(int i=0; i<n; i++){
        cin >> vc[i];
    }

    for(int i=0; i<n; i++){
        temp = v[i] - vc[i];

        if(temp>maior){
            maior=temp;
        }
    }

    cout.precision(2);
    cout.setf(ios::fixed);

    cout << maior << endl;

    return 0;
}
