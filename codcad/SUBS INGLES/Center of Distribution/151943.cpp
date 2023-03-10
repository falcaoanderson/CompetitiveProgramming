// 16/12/11 // 9:11 PM //

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define int long long
#define MAXN 100010

int n, lim, mcusto;
int x[MAXN], prefix[MAXN];

int sum(int l, int r, int m){
    int tsum = 0LL;
    tsum =  (m-l)*x[m] - (prefix[m-1LL] - prefix[l-1LL]); // intervalo [l, m-1]
    tsum += prefix[r] - prefix[m] - (r-m)*x[m];     // intervalo [m+1, r]

    return tsum;
}


int32_t main(){
    cin >> n >> lim >> mcusto;

    for(int i=1; i<=n; i++){
        cin >> x[i];
        prefix[i] = prefix[i-1LL] + x[i];
    }

    int l=1LL, r=1LL, m, tsum=0LL, resp=-1LL, tam;

    while(r<=n && l<=r){
        m = (l+r)/2LL;
        tam = r-l + 1LL;

        if(tam==2LL)
            tsum = x[r] - x[l];

        else if(tam&1LL)
            tsum = sum(l, r, m);
        else
            tsum = min(sum(l, r, m), sum(l, r, m+1LL));

        if(tsum>mcusto){
            l++;
        }
        else{
            resp = max(resp, tam);
            r++;
        }
    }

    cout << resp << endl;


    return 0;
}
