// 02/02/19 // 00:36 AM //

#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, acao, l1=0, l2=0;

    cin >> n;

    for(int i=0; i<n; i++){
        cin >> acao;

        if(acao==1){
            if(l1==0) l1=1;
            else      l1=0;
        }
        else{
            if(l1==0) l1=1;
            else      l1=0;
            if(l2==0) l2=1;
            else      l2=0;
        }
    }
    cout << l1 << "\n" << l2 << "\n";

    return 0;
}
