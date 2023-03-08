// 11/08/19 // 7:28 PM //

#include <iostream>

using namespace std;

#define MAXN 1010

int n;
int v[MAXN];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    for(int i=1; i<=n; i++) cin >> v[i];

    for(int i=2; i<n; i++)
        if(v[i]<v[i-1] && v[i]<v[i+1]){
            cout << "S\n";
            return 0;
        }


    cout << "N\n";

    return 0;
}
