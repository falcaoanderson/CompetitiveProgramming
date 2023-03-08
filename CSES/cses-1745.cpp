// 01/11/20 // xx:xx PM //

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
const int MAXN = (1e2) + 10;
const int MAXV = (1e5) + 10;

int coin[MAXN], prefix[MAXN];
bool memo[MAXV];

int main(){
    fast_io;

    int n;
    cin >> n;

    for(int i=1; i<=n; i++){
        cin >> coin[i];
        prefix[i] = prefix[i-1] + coin[i];
    }
    
    memo[0] = 1;
    for(int i=1; i<=n; i++)
        for(int j=prefix[i]; j>=coin[i]; j--)
            memo[j] = memo[j] || memo[j-coin[i]];


    int cont = 0;
    for(int i=1; i<=prefix[n]; i++) if(memo[i]) cont++;

    cout << cont << endl;
    for(int i=1; i<=prefix[n]; i++) if(memo[i]) cout << i << " ";
    cout << endl;

    return 0;
}
