// 30/08/19 // 12:51 PM //

#include <bits/stdc++.h>

using namespace std;

#define MAXN 110

int n, par, impar;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;


    for(int i=0; i<n; i++){
        int temp;
        cin >> temp;

        if(temp%2==0)par++;
        else         impar++;
    }

    cout << min(par, impar) << "\n";

    return 0;
}
