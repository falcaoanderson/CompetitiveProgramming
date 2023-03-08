#include <bits/stdc++.h>

using namespace std;

const double A = (1.5 -3*sqrt(17)/34 + 6*sqrt(17)/17);
const double B = (1.5 +3*sqrt(17)/34 - 6*sqrt(17)/17);
const double X1 = (5+sqrt(17))/2;
const double X2 = (5-sqrt(17))/2;

int main(){
    int n=10;

    double f = A*pow(X1,n) + B*pow(X2, n);
    cout << f << endl;

    return 0;
}
