// 11/08/23 // largest rectangular area in histogram
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

    vector<int> v(n);
    for(int i=0; i<n; i++) cin >> v[i];

    vector<int> l_smaller(n, -1), r_smaller(n, n);
    stack<int> prev;
    prev.push(-1);

    for(int i=0; i<n; i++){
        while(!prev.empty() && prev.top()!=-1 && v[prev.top()]>v[i]){
            r_smaller[prev.top()] = i;
            prev.pop();
        }

        if(i>0 && v[i]==v[i-1]){
            l_smaller[i] = l_smaller[i-1];
        }
        else{
            l_smaller[i] = prev.top();
        }

        prev.push(i);
    }


    ll max_area = 0LL;
    for(int i=0; i<n; i++){
        max_area = max(max_area, (ll)v[i] * (ll)(r_smaller[i]-l_smaller[i]-1));
    }

    cout << max_area << endl;

    return 0;
}
