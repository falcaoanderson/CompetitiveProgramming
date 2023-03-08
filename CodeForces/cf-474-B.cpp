// 15/01/2020 // 21:23 PM //

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define pb push_back
#define mp make_pair

const int INF = 0x3f3f3f3f;
const int MAXN = 1e5 + 10;

int n, m;
int prefix[MAXN];

int bSearch(int q){
    int ini=1, fim=n, mid, resp=0;

    while(ini<=fim){
        mid = (ini+fim)/2;

        if(q<=prefix[mid]){
            resp = mid;
            fim  = mid-1;
        }
        else{
            ini = mid+1;
        }
    }

    return resp;
}

int main(){
    fastio;

    cin >> n;

    for(int i=1; i<=n; i++){
        cin >> prefix[i];
        prefix[i] += prefix[i-1];
    }

    cin >> m;

    while(m--){
        int q;
        cin >> q;

        cout << bSearch(q) << endl;
    }

    return 0;
}
