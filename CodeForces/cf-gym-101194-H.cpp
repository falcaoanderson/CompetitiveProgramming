/*
08/08/24 
Problem: 
Complexity:
*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)

int solve(){
    int n, k;
    cin >> n >> k;

    vector<ll> v(n);
    queue<ll> fila;

    for(int i=0; i<n; i++) cin >> v[i];
    sort(v.begin(), v.end());

    int l=1, r=n/k, mid, resp=0;

    while(l<=r){
        mid = (l+r)/2;

        while(!fila.empty()) fila.pop();
        int total = 0;

        for(int i=0; i<n && total<mid*k; i++){
            if(i<mid){
                fila.push(v[i]);
                total++;
            }
            else if(2LL*fila.front() <= v[i]){
                fila.pop();
                fila.push(v[i]);
                total++;
            }
        }

        if(total == mid * k){
            resp = mid;
            l = mid+1;
        }
        else{
            r = mid-1;
        }
    }

    return resp;
}

int main(){
    fast_io;

    int t;
    cin >> t;

    for(int i=1; i<=t; i++){
        cout << "Case #" << i << ": " << solve() << endl;
    }

    return 0;
}
