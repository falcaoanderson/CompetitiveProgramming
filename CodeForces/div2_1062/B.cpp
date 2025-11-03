/*
22/10/25 

*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define PB push_back
#define EB emplace_back
#define FF first
#define SS second
#define SZ(x) (int)(x).size()

typedef pair<int, int> pii;
typedef tuple<int, int, int> tiii;

const int INF  = 0x3f3f3f3f;
const  ll LINF = 0x3f3f3f3f3f3f3f3f;
const int MAXN = (1e6) + 5;
const int MOD  = (1e9) + 7;

int main(){
    fast_io;

    ll n;
    cin >> n;

    if(n==1){
        cout << "1 0" << endl;
        return 0;
    }

    int number = 1, maxpot = -1;
    int moves = 0;

    for(int i=2; i<=n; i++){
        if((n % i) == 0){
            number *= i;

            int pot = 0;
            
            while((n % i) == 0){
                pot++;
                n /= i;
            }

            if(maxpot==-1){
                maxpot = pot;
            }
            else if(maxpot != pot){
                moves = 1;
                maxpot = max(maxpot, pot);
            }
        }
    }

    if(maxpot==1){
        cout << number << " " << moves << endl;
        return 0;
    }

    int k=0;
    while((1<<(k+1)) < maxpot) k++;
    k++;

    if((1<<k)!=maxpot) moves = 1;

    cout << number << " " << (moves + k) << endl;

    return 0;
}
