#include <iostream>
using namespace std;

int main(){
    float n1,n2,n3,n4,n5,maior1,menor1,maior2,menor2,maiorf,menorf;
    cin>>n1>>n2>>n3>>n4>>n5;

    if (n1>n2){maior1=n1;menor1=n2;}
    else      {maior1=n2;menor1=n1;}

    if (n3>n4){maior2=n3;menor2=n4;}
    else      {maior2=n4;menor2=n3;}

    if(maior1>maior2){maiorf=maior1;}
    else{maiorf=maior2;}

    if(menor1<menor2){menorf=menor1;}
    else{menorf=menor2;}

    if(n5>maiorf){maiorf=n5;}
    if(n5<menorf){menorf=n5;}

    cout.precision(1);
    cout.setf(ios::fixed);

    cout<<n1+n2+n3+n4+n5-maiorf-menorf<<endl;

    return 0;
}
