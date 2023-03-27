// 27/03/23 // 
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
 
using namespace std;

#define ll long long
#define endl "\n"
#define PB push_back

typedef pair<int, int> pii;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int n;
    cin >> n;

    vector<pii> v;

    for(int i=0; i<n; i++){
        int start, end;
        
        cin >> start >> end;

        v.PB(pii(end, start));
    }

    sort(v.begin(), v.end());

    int curr=0, total=0;

    for(int i=0; i<n; i++){
        if(v[i].second<curr) continue;

        curr = v[i].first;
        total++;
    }

    cout << total << endl;
 
    return 0;
}