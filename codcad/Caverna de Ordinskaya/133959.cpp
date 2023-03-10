#include <iostream>
#include <algorithm>
using namespace std;

struct Medidas{
    int med1, med2;
};

int main(){
    long long n, m, total=0, anterior=-1000;
    Medidas v[10010];

    cin >> n >> m;

    for(int i=0; i<n; i++){
        cin >> v[i].med1;
        v[i].med2 = m - v[i].med1;

        if(v[i].med2 < v[i].med1) swap(v[i].med2 , v[i].med1);

    }

    for(int i=0; i<n; i++){
        if(v[i].med1 >= anterior){
            anterior = v[i].med1;
            total += v[i].med1;
        }
        else if(v[i].med2 >= anterior){
            anterior = v[i].med2;
            total += v[i].med2;
        }
        else{
            total = -1;
            break;
        }
    }

    cout << total << endl;

    return 0;
}
