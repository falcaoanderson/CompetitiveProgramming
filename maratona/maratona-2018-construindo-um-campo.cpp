#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define pb push_back
#define ll long long

const int INF  = 0x3f3f3f3f;
const int MAXN = (1e5) + 10;

int n, sum=0, v[MAXN];

int main(){
    fast_io;

    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> v[i];
        sum += v[i];
    }

    if(sum&1){
        cout << "N" << endl;
        return 0;
    }

    int atual=0, cont=0;
    
    int metade=0, temp=0;
    while(temp<=sum/2){
        metade++;
        temp+=v[metade];
    }

    for(int l=1, r=1; l<metade; l++){
        for(;r<=n && atual<sum/2; r++){
            atual += v[r];
        }

        if(atual == sum/2) cont++;
        atual -= v[l];
    }

    if(cont>=2) cout << "Y" << endl;
    else        cout << "N" << endl;

    return 0;
}
