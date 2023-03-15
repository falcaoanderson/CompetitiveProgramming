#include <iostream>
using namespace std;

const int MAXN = 2e5+5;

int n, q;
long long int v[MAXN];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> q;

    for(int i=1; i<=n; i++){
        cin >> v[i];
        v[i] += v[i-1];
    }


    int x, y;
    while(q--){
        cin >> x >> y;
        cout << v[y]-v[x-1] << endl;
    }

    return 0;
}