/*
09/01/24 
Problem: 
Complexity:
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <tuple>
#include <cstring>
#include <stack>
#include <functional>
#include <cmath>

using namespace std;

#define ll long long
#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define PB push_back
#define EB emplace_back
#define FF first
#define SS second

typedef pair<int, int> pii;
typedef tuple<int, int, int> tiii;

const int INF  = 0x3f3f3f3f;
const  ll LINF = 0x3f3f3f3f3f3f3f3f;
const int MAXN = (2e5) + 5;
const int MOD  = (1e9) + 7;

int main(){
    fast_io;

    int n;
    cin >> n;

    vector<int> v(n);
    vector<bool> chosen(n+1);

    int last=0;
    for(int i=0; i<n; i++){
        cin >> v[i];
        chosen[v[i]] = 1;
        if(v[i]==0) last=i+1;
    }

    int l=1, r=n;
    for(int i=0; i<n; i++){
        if(v[i]){
            cout << v[i] << " ";
        }
        else{
            while(chosen[l]){
                l++;
            }
            while(chosen[r]){
                r--;
            }

            if(r==i+1 || l==last){
                cout << l << " ";
                l++;
            }
            else{
                cout << r << " ";
                r--;
            }
        }
    }

    return 0;
}
