#include <iostream>

using namespace std;

const int MAXN = 2e5+10;

int n;
bool v[MAXN];

int main(){

    cin >> n;

    for(int i=0; i<n-1; i++){
        int temp;
        cin >> temp;

        v[temp] = 1;
    }

    for(int i=1; i<=n; i++){
        if(!v[i]){
            cout << i << endl;
            break;
        }
    }

    return 0;
}