// 29/04/23 //
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
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
 
inline ll max(ll a, ll b){
    return (a>b? a: b);
}

bool comp(tiii a, tiii b){
    if(get<0>(a) == get<0>(b)) return ( get<1>(a)>get<1>(b) );
    return ( get<0>(a) < get<0>(b) );
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;

    vector<tiii> v(n);
    
    for(int i=0; i<n; i++){
        cin >> get<0>(v[i]) >> get<1>(v[i]);

        get<2>(v[i]) = i;  
    }
    sort(v.begin(), v.end(), comp);
    
    multiset<int> ends;
    vector<int> contains(n), belongs(n);

    for(int i=0; i<n; i++) ends.insert(get<1>(v[i]));

    for(int i=0; i<n-1; i++){
        int a, b, ind;
        tie(a, b, ind) = v[i];

        ends.erase(ends.find(b));

        if((*ends.begin()) <= b) contains[ind]=1;
    }

    for(int i: contains){
        cout << (i) << " ";
    }
    cout << endl;

    ends.clear();    
    for(int i=0; i<n; i++) ends.insert(get<1>(v[i]));

    for(int i=n-1; i>0; i--){
        int a, b, ind;
        tie(a, b, ind) = v[i];

        ends.erase(ends.find(b));

        if((*ends.rbegin()) >= b) belongs[ind]=1;
    }

    for(int i: belongs){
        cout << (i) << " ";
    }
    cout << endl;

    return 0;
}
