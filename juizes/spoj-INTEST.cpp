// 14/01/19 // 7 PM //

#include <iostream>
using namespace std;

int n, k, t, total=0;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> k;

    for(int i=0; i<n; i++){
        cin >> t;
        if(t%k==0) total++;
    }

    cout << total << "\n";

    return 0;
}
