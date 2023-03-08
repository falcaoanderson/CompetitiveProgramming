// 08/06/20 // 8:51 PM //

#include <bits/stdc++.h>

using namespace std;

const int MAXN = (int)(2e5)+10;
int n, x, p[MAXN];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> x;
    for(int i=1; i<=n; i++) cin >> p[i];

    sort(p+1, p+n+1);

    int cont = 0, i=1, j=n;

    while(i<j){
        if(p[i]+p[j]<=x){
            cont++;
            i++; j--;
        }
        else{
            j--;
        }
    }

    cout << n-cont << endl;

    return 0;
}
