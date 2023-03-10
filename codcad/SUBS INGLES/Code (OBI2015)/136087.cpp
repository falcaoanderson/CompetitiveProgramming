#include <iostream>
using namespace std;

#define MAXN 10010

int n, total=0, v[MAXN];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;

    for(int i=1; i<=n; i++) cin >> v[i];

    for(int i=1; i<=n-2; i++){
        if(v[i]==1 && v[i+1]==0 && v[i+2]==0)
            total++;
    }

    cout << total << "\n";

    return 0;
}