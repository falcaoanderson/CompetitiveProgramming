// 31/10/20 // xx:xx PM //

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define pb push_back
#define mp make_pair
#define ll long long
//#define int long long

typedef pair<int, int> pii;

const int INF  = 0x3f3f3f3f;
const int MAXN = (1e5) + 10;

int main(){
    fast_io;

    int n;
    cin >> n;
    /*
    vector<int> memo(n+1);

    for(int i=1; i<=n; i++){
        string num = to_string(i);
        memo[i] = INF;

        for(int j=0; j<(int)num.size(); j++)
            memo[i] = min(memo[i], memo[i-(num[j]-'0')] + 1);
    }

    cout << memo[n] << endl;
    */
    int cont = 0;
    while(n>0){
        string num = to_string(n);
        
        int maior = 0;
        for(int j=0; j<(int)num.size(); j++) maior = max(maior, num[j]-'0');

        n-=maior;
        
        cont++;
    }
    cout << cont << endl;

    return 0;
}
