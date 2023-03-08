// 19/09/19 // 9:20 PM //

#include <bits/stdc++.h>

using namespace std;

int n, a, b;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    for(int i=0; i<n; i++){
        int temp;

        cin >> temp;

        if(temp<50) a++;
        else if(temp<85)b++;
    }

    cout << a << " " << b << "\n";

    return 0;
}

