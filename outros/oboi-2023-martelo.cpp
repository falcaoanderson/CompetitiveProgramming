// 13/08/23 //
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

    int d, g;
    cin >> d >> g;

    int resp = 0;

    for(int i=0; i<=g; i+=4){
        resp = max(resp, min(g-i, (d+i/4)/6));
    }
    for(int i=0; i<=d; i++){
        resp = max(resp, min(g+4*i, (d-i)/6));
    }

    cout << resp << endl;

    return 0;
}
