// 05/11/20 // xx:xx PM //

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
    vector<int> v(n);

    int sum = 0, resp = -INF;

    for(int i=0; i<n; i++){
        cin >> v[i];

        
        sum += v[i];
        if(i>=4) sum -= v[i-4];

        if(i>=3) resp = max(resp, sum);
    }

    cout << resp << endl;

    return 0;
}
