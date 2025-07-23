/*
22/07/25 

*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define PB push_back
#define EB emplace_back
#define FF first
#define SS second
#define sz(x) (int)(x).size()

typedef pair<int, int> pii;
typedef tuple<int, int, int> tiii;

const int INF  = 0x3f3f3f3f;
const  ll LINF = 0x3f3f3f3f3f3f3f3f;
const int MAXN = (2e5) + 5;
const int MOD  = (1e9) + 7;

int main(){
    fast_io;

    int x, y, z;
    cin >> x >> y >> z;
    
    if( z!=0 && abs(x-y)<=z ){
        cout << '?' << endl;
    }
    else if(x>y){
        cout << '+' << endl;
    }
    else if(x<y){
        cout << '-' << endl;
    }
    else{
        cout << 0 << endl;
    }


    return 0;
}
