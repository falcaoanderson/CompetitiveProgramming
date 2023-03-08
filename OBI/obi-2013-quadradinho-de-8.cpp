// 28/07/20  // 00:09 AM //

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

int n, prefix[10];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    int resp=0, atual=0;
    prefix[0] = 1;

    for(int i=0; i<n; i++){
        int temp;
        cin >> temp;

        atual = (atual+temp)%8;

        cout << "atual: " << atual << " // need: " <<(8-atual)%8 << endl;

        resp += prefix[(8-atual)%8];

        prefix[atual]++;
    }

    cout << resp << endl;

    return 0;
}
