// 14/06/20 // 00:04 PM //

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

const int MAXN = (2e5)+10;

int n;
bool cont[MAXN];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    for(int i=1; i<n; i++){
        int temp;
        cin >> temp;

        cont[temp] = 1;
    }

    for(int i=1; i<=n; i++){
        if(!cont[i]){
            cout << i << endl;
            break;
        }
    }

    return 0;
}
