#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, total=0, v[10010];

    cin >> n;

    for(int i=1; i<=n; i++) {
        cin >> v[i];
        if(i>=3 && v[i-2]==1 && v[i-1]==0 && v[i]==0) total++;
    }

    cout << total << "\n";

    return 0;
}