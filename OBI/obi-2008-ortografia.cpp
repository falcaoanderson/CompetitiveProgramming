// 05/11/20 // 3:57 PM //

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
const int MAXN = (1e3) + 10;
const int MAXM = (1e2) + 10;


string dic[MAXN];
int n, m, memo[25][25];

int min(int a, int b, int c){
    return min(a, min(b, c));
}

int edit_distance(string a, string b){
    memset(memo, 0, sizeof(memo));
    int sa = a.size(), sb = b.size();
    a = " " + a;
    b = " " + b;

    for(int i=1; i<=sa; i++) memo[i][0] = i;
    for(int j=1; j<=sb; j++) memo[0][j] = j;

    for(int i=1; i<=sa; i++){
        for(int j=1; j<=sb; j++){
            if(a[i]==b[j]) 
                memo[i][j] = memo[i-1][j-1];
            else
                memo[i][j] = min(memo[i-1][j], memo[i][j-1], memo[i-1][j-1]) + 1;
        }
    }

    return memo[sa][sb];
}

int main(){
    fast_io;
    
    cin >> n >> m;

    for(int i=1; i<=n; i++) cin >> dic[i];
    for(int i=1; i<=m; i++){
        string palavra;
        cin >> palavra;

        for(int j=1; j<=n; j++)
            if(edit_distance(palavra, dic[j])<=2) cout << dic[j] << " ";
        cout << endl;
    }
    

    return 0;
}
