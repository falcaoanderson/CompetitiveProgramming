// 24/08/24 // Virtual
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int MAXN = 1e5 + 5;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    long long n;
    cin >> n;

    vector<ll> v(n);
    for(int i=0; i<n; i++){
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    long long resp = 0, value=0;
    for(long long i=0; i<n; i++){
        if(v[i]*(n-i)>resp){
            resp = v[i]*(n-i);
            value = v[i];
        }
    }

    cout << value << " " << resp << endl;

    return 0;
}