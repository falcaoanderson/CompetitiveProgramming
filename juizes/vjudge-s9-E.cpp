// 28/07/23 //
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

    int n, m;
    cin >> n >> m;

    vector<string> v1(n), v2(m);

    for(int i=0; i<n; i++) cin >> v1[i];
    for(int i=0; i<m; i++) cin >> v2[i];

    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());

    int a=0, b=0;
    int ist=0;

    while(a<n && b<m){
        if(v1[a]==v2[b]){
            ist++;
            a++;
            b++;
        }
        else if(v1[a]>v2[b]){
            b++;
        }
        else{
            a++;
        }
    }

    n -= ist;
    m -= ist;
    if(ist&1) n++;

    cout << (n>m? "YES": "NO") << endl;

    return 0;
}
