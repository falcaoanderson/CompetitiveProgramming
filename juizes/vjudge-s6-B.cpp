// 06/07/23 //
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

    int n, t;
    cin >> n >> t;

    vector<pii> person(n);

    for(int i=0; i<n; i++){
        cin >> person[i].ss >> person[i].ff;
    }

    sort(person.begin(), person.end());

    priority_queue< int, vector<int>, greater<int> > pq;
    
    for(pii p: person){
        int crr_time = pq.size();

        if(crr_time<t && crr_time<=p.ff){ // <---
            pq.push(p.ss);
        }
        else if(pq.top() < p.ss){
            pq.pop();
            pq.push(p.ss);
        }
    }

    int resp = 0;
    while(!pq.empty()){
        resp += pq.top();
        pq.pop();
    }

    cout << resp << endl;

    return 0;
}
