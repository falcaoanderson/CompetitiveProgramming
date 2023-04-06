// 06/04/23 //
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <tuple>
 
using namespace std;

#define ll long long 
#define endl "\n"
#define PB push_back
#define EB emplace_back
#define ff first
#define ss second

typedef pair<int, int> pii;
typedef tuple<int, int, int> tiii;

bool check(vector<ll> &time, ll qnt, ll test_time){
    for(ll i: time){
        qnt -= test_time/i;

        if(qnt<=0) return 1;
    }
    return 0;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, t;
    cin >> n >> t;

    vector<ll> time(n, 0);
    for(int i=0; i<n; i++){
        cin >> time[i];
    }

    sort(time.begin(), time.end());
    
    ll start=time[0], end = time[0]*t, resp=-1;

    while(start<=end){
        ll mid = (start+end)/2;
    
        if(check(time, t, mid)){
            resp = mid;
            end = mid-1;
        }
        else{
            start = mid+1;
        }
    }

    cout << resp << endl;

 
    return 0;
}