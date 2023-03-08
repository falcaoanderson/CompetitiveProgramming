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
    
    for(int i=1; i<=n; i++){
        int val;
        cin >> val;

        maxval = max(maxval, val);

        for(int j=1; j*j<=val; j++){
            if(val%j==0){
                freq[j]++;
                freq[val/j]++;
            }
            if(j*j==val) freq[j]--;
        }
    }
    
    for(int i=maxval; i>=1; i--)
        if(freq[i]>1){
            cout << i << endl;
            break;
        }

    return 0;
}
