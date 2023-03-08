// 19/10/20 // 19:15 PM //

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define pb push_back
#define mp make_pair
//#define int long long

const int MAXN = (1e5) + 10;

int main(){
    fast_io;

    int n, k;
    cin >> n;

    vector<int> v(n,0);
    for(int i=0; i<n; i++) cin >> v[i];

    cin >> k;

    vector<int>::iterator low;
    for(int i=0; i<n; i++){
        low = lower_bound(v.begin(), v.end(), k-v[i]);
        if(low!=v.end() && v[i]+(*low)==k){
            cout << v[i] << " " <<(*low) << endl;
            break;
        }
    }


    return 0;
}

