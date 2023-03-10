#include <iostream>
using namespace std;

int main(){
    int c,i,total=0;
    char b;
    cin>>c;

    for(i=0;i<c;i++){
        cin>>b;
        if (b=='P' or b=='C'){
            total+=2;
        }else if (b=='A'){
            total+=1;
        }else{
            total+=0;
        }
    }

    cout<<total<<endl;
    return 0;
}
