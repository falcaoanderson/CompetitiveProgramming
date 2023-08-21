// 21/08/23 //
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

const int MAXN = (1e5) + 5;

int va[MAXN], vv[MAXN];

int main(){
    fast_io;

    int a, v;
    cin >> a >> v;
    
    for(int i=0; i<a; i++) cin >> va[i];
    for(int i=0; i<v; i++) cin >> vv[i];

    sort(va, va+a);
    sort(vv, vv+v);

    int resp = 0;
    if(va[a-1]>vv[v-1]){
        for(int i=a-2; i>=0 && va[i]>vv[v-1]; i--) resp++;
    }
    else{
        for(int i=v-2; i>=0 && vv[i]>va[a-1]; i--) resp++;
    }
    cout << resp << endl;

    return 0;
}
