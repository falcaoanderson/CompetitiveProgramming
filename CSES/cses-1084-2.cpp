// 08/06/20 // 20:04 PM //

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

const int MAXN = (int)(2e5)+10;

int n, m, k;
int ap[MAXN], tam[MAXN];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> k;

    for(int i=1; i<=n; i++) cin >> ap[i];
    for(int i=1; i<=m; i++) cin >> tam[i];

    sort(ap+1, ap+n+1);
    sort(tam+1, tam+m+1);

    int resp = 0, i=1, j=1;

    while(i<=n && j<=m){
        if(tam[j] < ap[i]-k)
            j++;
        else if(tam[j]>ap[i]+k)
            i++;
        else{
            i++; j++; resp++;
        }
    }

    cout << resp << endl;

    return 0;
}

