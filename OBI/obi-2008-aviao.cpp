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
    
    int f, c, e, b;
    cin >> f >> c >> e >> b;

    if((f-e+1)*c < b) 
        cout << "PROXIMO VOO" << endl;
    else{
        cout << (b%c==0?b/c: b/c+1) + e -1 << " " << char((b%c==0?c:b%c) + 64) << endl;  
    }

    return 0;
}
