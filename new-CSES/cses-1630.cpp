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
    
    int n;
    cin >> n;

    vector<pii> task(n, pii(0,0));
    for(int i=0; i<n; i++){
        cin >> task[i].ff >> task[i].ss;
    }

    sort(task.begin(), task.end());
    
    ll time=0, total=0;

    for(int i=0; i<n; i++){
        time += (ll)task[i].ff;
        total += (ll)task[i].ss - time;
    }

    cout << total << endl;

 
    return 0;
}