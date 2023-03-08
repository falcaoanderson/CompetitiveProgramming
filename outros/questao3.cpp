#include <bits/stdc++.h>

using namespace std;

int main(){

    int maxN = 100;

    for(int i=1; i<=maxN; i++){
        for(int j=1; j<i; j++){
            if( (i * (i+1))/2 -2*j-1 == 1224){
                cout << "n = " << i << " | k = " << j << endl;
            }
        }
    }

    return 0;
}