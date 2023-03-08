// 15/11/20 // xx:xx PM //

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
const int MAXV = 1e6 + 5;

int freq[MAXV];

int main(){
    fast_io;

    int n, maxval=0;
    cin >> n;
    
    for(int i=0; i<n; i++){
        int val;
        cin >> val;

        maxval = max(maxval, val);

        freq[val]++;
    }

    for(int i=maxval; maxval>=1; i--){
        int count = 0;

        for(int m=i; m<=maxval; m+=i){
            if(freq[m]>1){
                cout << m << endl;
                return 0;
            }
            if(freq[m]==1) count++;
            if(count==2){
                cout << i << endl;
                return 0;
            }
        }
    }

    return 0;
}
