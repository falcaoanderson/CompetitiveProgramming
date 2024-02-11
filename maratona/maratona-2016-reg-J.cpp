/*
03/02/24 
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

bool isPrime(int x){
    if(x==1) return 0;
    if(x==2) return 1;

    for(int i=2; i*i<=x; i++)
        if(x%i==0) return 0;

    return 1;
}

int main(){
    fast_io;
    
    int n;
    cin >> n;

    for(int i=n; i>=2; i--){
        if(isPrime(i)){
            cout << i << endl;
            break;
        }
    }

    return 0;
}
