#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, ant=2, resp=0;

    cin >> n;

    for(int i=0; i<n; i++){
        int temp;
        cin >> temp;

        if(temp!=ant){
            resp++;
            ant = temp;
        }
    }

    cout << resp << endl;

    return 0;
}
