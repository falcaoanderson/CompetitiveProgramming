// 05/03/20 // 09:54 AM //

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

const int MAXN = 1010;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, ma=-1, mb=-1;

    cin >> n;
    for(int i=0; i<n; i++){
        int temp;
        cin >> temp;
        ma=max(ma, temp);
    }

    cin >> n;
    for(int i=0; i<n; i++){
        int temp;
        cin >> temp;
        mb=max(mb, temp);
    }

    cout << ma << " " << mb << endl;

    return 0;
}

