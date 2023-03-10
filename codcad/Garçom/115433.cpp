#include <iostream>
using namespace std;

int main(){
    unsigned short int n,l,c,cd=0,i;
    cin>>n;

    for(i=0;i<n;i++){
        cin>>l>>c;
        if(l>c){
            cd+=c;
        }
    }
    cout<<cd<<endl;
    return 0;
}