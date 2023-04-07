// 07/04/23 //
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <tuple>
#include <map>
#include <unordered_map>
 
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
    
    cin >> n;
    
    vector<ll> v(n, 0);
    for(int i=0; i<n; i++){
        cin >> v[i];
    }
    
    ll resp=0LL, crr=0LL;

    unordered_map<ll, int> prefix;
    //prefix.reserve(1024);
    //prefix.max_load_factor(0.25);

    prefix[0] = 1;

    for(int i=0; i<n; i++){
        crr = ((crr+v[i])%n + n)%n;

        if(prefix.find(crr)!=prefix.end()){
            resp += prefix[crr];

            prefix[crr]++;
        }
        else{
            prefix[crr] = 1;    
        }
    }
    
    cout << resp << endl;

    return 0;
}