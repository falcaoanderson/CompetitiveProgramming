// 29/08/19 // 1:37 PM //

#include <bits/stdc++.h>

using namespace std;

#define MAXN 100010
#define INF 0x3f3f3f3f

int n, l, r;
int v[MAXN];

int main(){
    cin >> n >> l >> r;

    for(int i=1; i<=n; i++) cin >> v[i];

    sort(v+1, v+n+1);

    if(l>=v[n]){
        cout << r-v[n] << endl;
        return 0;
    }
    else if(r<=v[1]){
        cout << v[1]-l << endl;
        return 0;
    }

    int resp = 0;
    bool ini=true;
    for(int i=1; i<=n; i++){
        if(v[i]<l) continue;
        else if(ini){
            if(i>1) resp = min(v[i]-l, l-v[i-1]);
            else    resp = v[i]-l;
            ini  = false;
        }

        if(v[i]>r) break;
        else if(i==n) resp = max(resp, r-v[i]);

        if(i==1) continue;
        resp = max(resp, min((v[i]-v[i-1])/2, (v[i]-l)/2));
    }

    cout << resp << endl;

    return 0;
}

