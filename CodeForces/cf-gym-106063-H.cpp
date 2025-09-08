// 06/09/25

#include <bits/stdc++.h>

using namespace std;

using ll = long long;

#define fast_io ios_base::sync_with_stdio(0);cin.tie(0)
#define endl '\n'
#define PB push_back
#define FF first
#define SS second

typedef pair<int, int> pii;
typedef pair<int, pii> pip;

const int INF = 0x3f3f3f3f;
const int MAXN = 1e5+5, MAXM = 60 + 5;
const ll MOD = 1e9+7;

int n, m;
string a, b;

ll prefix[MAXN][MAXM], sufix[MAXN][MAXM];

int main() {
    fast_io;

    cin >> n >> m;
    cin >> a >> b;
    
    for(int i=0; i<n; i++){
        prefix[i][0] = (a[i]==b[0]) + (0<i? prefix[i-1][0]: 0);
    }
    for(int i=n-1; i>=0; i--){
        sufix[i][m-1] = (a[i]==b[m-1]) + (i<n-1? sufix[i+1][m-1]: 0);
    }
    for(int j=1; j<m; j++){ 
        for(int i=0; i<n; i++){
            prefix[i][j] = prefix[i-1][j] + (a[i]==b[j] && i>0? prefix[i-1][j-1]: 0);
            prefix[i][j] %= MOD;
        }
    }
    for(int j=m-2; j>=0; j--){ 
        for(int i=n-1; i>=0; i--){
            sufix[i][j] = sufix[i+1][j] + (a[i]==b[j]? sufix[i+1][j+1]: 0);
            sufix[i][j] %= MOD;
        }
    }

    vector<bool> alpha(26);
    for(char c: b) alpha[c-'a'] = 1;

    ll resp = prefix[n-1][m-1], base=prefix[n-1][m-1];
    
    for(int i=0; i<n; i++){
        ll crr=0;
        for(int j=0; j<m; j++){
            if(a[i]==b[j]) continue;

            if(i<j || m-j>n-i) continue;
            // i>=j && m-j<=n-i
            ll left  = (j>0? prefix[i-1][j-1]: 1);
            ll right = (j<m-1? sufix[i+1][j+1]: 1);

            crr += (left * right)%MOD;
            crr %= MOD;
        }
        resp = (resp+crr)%MOD; // troca ativa

        crr = base;
        if(alpha[a[i]-'a']){
            for(int j=0; j<m; j++){
                if(a[i]!=b[j]) continue;

                if(i<j || m-j>n-i) continue;
                // i>=j && m-j<=n-i
                ll left  = (j>0? prefix[i-1][j-1]: 1);
                ll right = (j<m-1? sufix[i+1][j+1]: 1);

                crr -= (left * right)%MOD;
                crr = (crr + MOD)%MOD;
            }
        }
        
        crr = (25LL * crr)%MOD; // troca passiva
        
        resp = (resp+crr)%MOD;
    }

    cout << resp << endl;

    return 0;
}