// 16/01/20 // 08:31 PM //

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define pb push_back
#define mp make_pair
#define int long long

const int INF  = 0x3f3f3f3f;
const int MAXN = 1e5 + 10;

int32_t main(){
    fastio;

    int t;
    cin >> t;

    while(t--){
        int n, melhorTotal=-INF, melhorAtual=-INF, soma=0, start, pval;

        cin >> n;

        for(int i=0; i<n; i++){
            int temp;
            cin >> temp;

            soma += temp;
            if(i==0) pval = temp;

            if(temp>=melhorAtual+temp){
                melhorAtual = temp;
                start = i;
            }
            else{
                melhorAtual += temp;

                if(start==0 && i==n-1)
                    melhorAtual = max(melhorAtual -pval, melhorAtual-temp);
            }

            melhorTotal = max(melhorTotal, melhorAtual);
        }

        cout << (soma > melhorTotal ? "YES" : "NO") << endl;
    }

    return 0;
}
