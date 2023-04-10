// 10/04/23 //
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <tuple>
 
using namespace std;

#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ll long long 
#define endl "\n"
#define PB push_back
#define EB emplace_back
#define ff first
#define ss second
 
typedef pair<int, int> pii;
typedef tuple<int, int, int> tiii;

bool check(vector<ll> &v, int k, ll val){
    ll crr_sum=0LL;
    int count = 1;

    for(int i=0; i<(int)v.size(); i++){
        if(v[i]>val) return 0;
        
        if(crr_sum+v[i]<=val){
            crr_sum += v[i];
        }
        else{
            count++;
            crr_sum=v[i];
        }

        if(count>k) return 0;
    }

    return 1;
}

int main(){
    fast_io;

    int n, k;
    cin >> n >> k;

    vector<ll> v(n);

    ll sum=0LL;

    for(int i=0; i<n; i++){
        cin >> v[i];

        sum += v[i];
    }

    ll left=1, right=sum, resp=sum;

    while(left<=right){
        ll mid = (left+right)/2;

        if(check(v, k, mid)){
            resp = mid;
            right=mid-1;
        }
        else{
            left=mid+1;
        }
    }

    cout << resp << endl;
    
    return 0;   
}
