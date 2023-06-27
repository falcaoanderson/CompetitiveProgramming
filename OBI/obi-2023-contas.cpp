#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int val;
    cin >> val;

    vector<int> contas(3);

    for(int i=0; i<3; i++){
        cin >> contas[i];
    }

    sort(contas.begin(), contas.end());

    int resp = 0;
    for(int i=0; i<3; i++){
        if(contas[i]<=val){
            resp++;
            val -= contas[i];
        }
    }

    cout << resp << endl;

    return 0;
}