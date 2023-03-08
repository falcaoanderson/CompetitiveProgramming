// 27/11/20 // xx:xx PM //

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define pb push_back
#define mp make_pair
#define ll long long

typedef pair<int, int> pii;

const int INF  = 0x3f3f3f3f;
const int MAXN = (2e5) + 10;
const int MOD  = (1e9) + 7;

int main(){
    fast_io;

    int n, a;
    cin >> a >> n;

    int resp=0;

    while(n--){
        int f;
        cin >> f;

        if(f*a>=40000000) resp++;
    }

    cout << resp << endl;

    return 0;
}
