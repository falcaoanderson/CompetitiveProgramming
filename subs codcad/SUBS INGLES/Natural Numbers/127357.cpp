#include <iostream>
using namespace std;

int somaN(int n){
    if (n==1){
        return 1;
    }
    return n + somaN(n-1);
}


int main(){
    int number;
    cin >> number;
    cout << somaN(number) << endl;
    return 0;
}
