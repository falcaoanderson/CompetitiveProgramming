/*
24/01/26

*/

#include <bits/stdc++.h>

using namespace std;

#define fast_io ios_base::sync_with_stdio(false);cin.tie(nullptr)
#define endl "\n"
#define FF first
#define SS second
#define PB push_back
#define EB emplace_back

using ll = long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;

// const int MAXVAL = 1e6 + 5;
const int MAXN = 1e5 + 5;

int main(){
    fast_io;

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        n *= 2;

        multiset<ll> odd, even;
        for(int i=0; i<n; i++){
            int x;
            cin >> x;

            if(i&1){
                odd.insert(x);
            }
            else{
                even.insert(x);
            }
        }

        ll resp = 0;

        for(int i=0; i<n/2; i++){
            ll it_omin = *odd.begin();
            ll it_omax = *odd.rbegin();
            ll it_emin = *even.begin();
            ll it_emax = *even.rbegin();

            if(abs(it_omax - it_emin) >=  abs(it_emax - it_omin)){
                resp += abs(it_omax - it_emin);

                odd.erase(odd.find(it_omax));
                even.erase(even.find(it_emin));
            }
            else{
                resp += abs(it_emax - it_omin);

                odd.erase(odd.find(it_omin));
                even.erase(even.find(it_emax));
            }   
        }

        cout << resp << endl;
    }

    return 0;
}