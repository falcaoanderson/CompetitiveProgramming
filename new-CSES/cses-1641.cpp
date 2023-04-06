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

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, x;
    cin >> n >> x;

    vector<pii> v(n, pii(0,0));
    for(int i=0; i<n; i++){
        cin >> v[i].ff;

        v[i].ss = i;
    }
    
    sort(v.begin(), v.end());

    for(int i=0; i<n && v[i].ff<x; i++){
        ll find = x - v[i].ff;

        int left = i+1, right = n-1;
        int a=v[i].ss+1, b=-1, c=-1;

        while(left<right){
            ll sum = v[left].ff+v[right].ff;

            if(sum==find){
                b = v[left].ss + 1;
                c = v[right].ss + 1;
                break;
            }
            else if(sum>find){
                right--;
            }
            else{
                left++;
            }
        }

        if(b!=-1){
            cout << a << " " << b << " " << c << endl;
            return 0;
        }
    }

    cout << "IMPOSSIBLE" << endl;

    

 
    return 0;
}