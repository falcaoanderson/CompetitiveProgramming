#include <iostream>
using namespace std;

int main(){
    double a,b;
    char l;
    cin>>l>>a>>b;

    cout.precision(2);
    cout.setf(ios::fixed);

    if (l=='M'){
        cout<<a*b<<endl;
    }
    else if (l=='D'){
        cout<<a/b<<endl;
    }
    return 0;
}

