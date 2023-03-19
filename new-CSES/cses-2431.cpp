/* terminar
#include <iostream>
#include <vector>

using namespace std;

#define endl "\n"
#define ll long long

void sol(int k){

    ll pot = 10;
    int x=1;

    while(k>=pot){
        pot *= 10;
        x++;
    }

    cout << "pot = " << pot << endl;
    cout << "x = " << x << endl;

    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int q;
    cin >> q;

    while(q--){
        int k;
        cin >> k;

        sol(k);
    }

    return 0;
}
*/