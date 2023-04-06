// 06/04/23 //
 
#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
#define endl "\n"
#define ff first
#define ss second

typedef pair<int, int> pii; 
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int n, x;
    cin >> n >> x;
 
    vector<pii> v(n, pii(0, 0));
 
    for(int i=0; i<n; i++){
        cin >> v[i].first;
        v[i].second = i+1;
    }
    
    sort(v.begin(), v.end());
 
    int left=0, right = n-1;
    int a=-1, b=-1;

    while(left < right){
        int curr = v[left].ff + v[right].ff;
        
        if(curr == x){
            a = v[left].ss;
            b = v[right].ss;
            break;
        }
        else if(curr>x) right--;
        else left++;
    }
    
    if(a==-1) cout << "IMPOSSIBLE" << endl;
    else      cout << a << " " << b << endl;

    return 0;
}