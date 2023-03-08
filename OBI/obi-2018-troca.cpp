// 07/06/19 // 6:00 PM //
// O(N) //

#include <iostream>

using namespace std;

#define MAXN 100010

int n, t;
int cima[MAXN], baixo[MAXN], op[MAXN];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> t;

    for(int i=1; i<=n; i++) cin >> cima[i];
    for(int i=1; i<=n; i++) cin >> baixo[i];

    for(int i=0; i<t; i++){
        int a, b;

        cin >> a >> b;

        op[a]++;
        op[b+1]--;
    }


    int presum = 0;
    for(int i=1; i<=n; i++){
        presum += op[i];

        if(presum%2==0)
            cout << cima[i] << " ";
        else
            cout << baixo[i] << " ";
    }
    cout << "\n";

    return 0;
}
