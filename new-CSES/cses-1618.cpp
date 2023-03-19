#include <iostream>

using namespace std;

#define ll long long

int main(){
    int n;
    cin >> n;


    int total = 0;
    for(int i=5; i<=n; i*=5){
        total += n/i;
    }

    cout << total << endl;

    return 0;
}