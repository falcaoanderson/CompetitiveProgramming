// 27/10/20 // 27:10 PM //

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

    int n, c;
    cin >> n >> c;

    int atual = 0, resp = 0;

    for(int i=0; i<n; i++){
        int a, b;
        cin >> a >> b;

        atual += b-a;

        if(atual>c) resp = 1;
    }

    if(resp)
        cout << "S" << endl;
    else 
        cout << "N" << endl;

    return 0;
}
