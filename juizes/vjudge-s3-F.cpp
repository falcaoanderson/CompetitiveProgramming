// 21/06/23 //
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

using namespace std;

#define ll long long
#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define PB push_back
#define EB emplace_back
#define ff first
#define ss second

typedef pair<int, int> pii;
typedef tuple<int, int, int> tiii;

int main(){
    fast_io;

    int n;
    cin >> n;

    stack<int> v;
    for(int i=0; i<n; i++){
        int val;
        cin >> val;
    
        if(v.empty() || (val&1)!=(v.top()&1)){
            v.push(val);
        }
        else{
            v.pop();
        }
    }    

    cout << (v.size()<=1?"YES":"NO") << endl;

    return 0;
}
