// 06/04/23 //
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <tuple>
#include <stack>
 
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

    vector<int> v(n, 0);
    for(int i=0; i<n; i++){
        cin >> v[i];
    }

    stack<pii> previous;

    for(int i=0; i<n; i++){
        while(!previous.empty() && v[i]<=previous.top().ff){
            previous.pop();
        }

        if(previous.empty()) cout << "0 ";
        else                 cout << previous.top().ss << " ";

        previous.emplace(v[i], i+1); 
    }
    cout << endl;
 
    return 0;
}