// 31/03/19 // 12:05 PM //

#include <iostream>

using namespace std;

int v[20];
char resp = 'N';

void funcao(int n, int seq[]){

    if(n==9){
        resp='S';
        return;
    }

    for(int i=n; i<=8; i++){
        if(seq[i]!=seq[n-1] && seq[i]!=seq[n+1] && i!=n+1){
            swap(seq[n], seq[i]);
            funcao(n+1, seq);
            swap(seq[n], seq[i]);
        }
    }

    if(n!=8){
        swap(seq[n], seq[n+1]);
        if(seq[n]!=seq[n-1] && seq[n]!=seq[n+1])
            funcao(n+1, seq);
    }
}

int main(){
    v[0]=-1;v[9]=-1;

    for(int i=1; i<=8; i++) cin >> v[i];

    funcao(1,v);

    cout << resp << "\n";

    return 0;
}
