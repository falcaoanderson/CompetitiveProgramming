#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
    int l, r;
    ll sum_l=0, sum_r=0;
    
    cin >> l >> r;

    vector<ll> vl(l), vr(r);

    for(int i=0; i<l; i++){     
       cin >> vl[i];
       sum_l += vl[i];
    }
    for(int i=0; i<r; i++){
        cin >> vr[i];
        sum_r += vr[i];    
    }    
    
    int resp = 0, pr=r-1, pl=0;
    while(sum_l!=sum_r){
        if(sum_l>sum_r){
            sum_l -= vl[pl++];        
        }    
        else{
            sum_r -= vr[pr--];        
        }
        resp++;
    }

    cout << resp << endl;

    return 0;
}
