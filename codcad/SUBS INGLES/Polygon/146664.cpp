// 29/05/19 // 3:50 PM //

#include <iostream>
#include <algorithm>

using namespace std;

#define MAXN 100010

int n, soma=0;
int v[MAXN];

int main(){
    cin >> n;

    for(int i=1; i<=n; i++){
        cin >> v[i];
        soma += v[i];
    }

    sort(v+1, v+n+1);

    for(int i=n; i>=3; i--){
        if(soma > 2*v[i]){
            cout << i << "\n";
            return 0;
        }
        soma -= v[i];
    }

    cout << "0\n";

    return 0;
}
