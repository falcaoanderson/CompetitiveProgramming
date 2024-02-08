// 29/01/23 //
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
#include <functional>
#include <cmath>

using namespace std;

#define ll long long
#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define PB push_back
#define EB emplace_back
#define FF first
#define SS second

typedef pair<int, int> pii;
typedef tuple<int, int, int> tiii;

const int INF  = 0x3f3f3f3f;
const  ll LINF = 0x3f3f3f3f3f3f3f3f;
const int MAXN = (2e5) + 5;
const int MOD  = (1e9) + 7;

bool cmp(string a, string b){
    int sza = a.size(), szb = b.size();

    if(sza==szb) return a<b;

    for(int i=0; i<max(sza, szb); i++){
        if(a[i%sza] < b[i%szb]) return 1;
        if(a[i%sza] > b[i%szb]) return 0;
    }

    return 0;
}

bool cmp1(string a, string b){
    if(a+b<b+a){
        return 1;
    }
    return 0;
}

int main(){
    fast_io;

    int n;
    cin >> n;

    vector<string> v;

    for(int i=0; i<n; i++){
        string s;
        cin >> s;

        v.PB(s);
    }

    sort(v.begin(), v.end(), cmp1);

    for(string s: v)
        cout << s;
    cout << endl;

    return 0;
}
