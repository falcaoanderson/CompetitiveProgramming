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
    int height=0;
    bool flag = true;

    for(int i=0; i<n; i++){
        int val;
        cin >> val;
    
        if(v.empty() || v.top()>val){
            v.push(val);
        }
        else if(v.top()==val){
            v.pop();

            height = max(height, val);            
        }
        else{ // v.top()<val // nao existe sol
            flag = false;
        }
    }    

    cout << (flag && (n==1 || v.empty() || (v.size()==1 && v.top()>=height))? "YES": "NO") << endl;

    return 0;
}
