#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define int long long

const int MAXN = 1e5 + 10;

int n;
int prefix[MAXN], sufix[MAXN];

bool buscab(int fim, int soma){
    int ini = 1, meio;

    while(ini<=fim){
        meio = (ini+fim)/2;

        if(prefix[meio]==soma)
            return 1;
        else if(prefix[meio]>soma)
            fim = meio-1;
        else
            ini = meio+1;
    }

    return 0;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    for(int i=1; i<=n; i++){
        cin >> prefix[i];
        prefix[i]+=prefix[i-1];
    }
    for(int i=1; i<=n; i++) sufix[i] = prefix[n] - prefix[i-1];

    int resp = 0;

    for(int i=n; i>=2; i--)
        if(buscab(i-1, sufix[i]))
           resp = max(resp, sufix[i]);

    cout << resp << endl;

    return 0;
}
