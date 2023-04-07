// 07/04/23 //
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
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n; 
    ll target_sum;
    
    cin >> n >> target_sum;
    
    vector<ll> v(n, 0);
    for(int i=0; i<n; i++){
        cin >> v[i];
    }
    
    int j=0, resp=0;
    ll crr_sum=0LL;

    for(int i=0; i<n && j<n; i++){
        while(j<n && (i==j || crr_sum+v[j] <= target_sum)){
            crr_sum += v[j++];
        }

        if(crr_sum==target_sum) resp++;
        
        crr_sum -= v[i];
    }
    
    cout << resp << endl;

    return 0;
}