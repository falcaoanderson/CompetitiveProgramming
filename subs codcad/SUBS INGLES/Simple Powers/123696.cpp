#include <iostream>
using namespace std;

#include <cmath>

int main(){
    double x,y;

    cin>>x>>y;

    cout.precision(4);
    cout.setf(ios::fixed);
    cout<< pow(x,y) <<endl;

    return 0;
}
