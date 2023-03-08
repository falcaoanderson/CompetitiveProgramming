#include <iostream>
using namespace std;

int main(){
    int n,i,nota=0;
    string gab,cart;

    cin>>n>>gab>>cart;

    for(i=0; i<n;i++){
        if(gab[i]==cart[i]){
            nota++;
        }
    }
    cout<<nota<<endl;
    return 0;
}
