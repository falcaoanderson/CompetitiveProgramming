/*
12/01/24 
Problem: 
Complexity:
*/

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

bool available[40];

int main(){
    fast_io;

    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    for(int i=0; i<k; i++){
        string c;
        cin >> c;

        available[int(c[0]) - int('a')]=1;
    }

    ll total=0, crr=0;
    for(char c: s){
        if(available[int(c) - int('a')]){
            crr++;
        }
        else{
            total += (crr*(crr+1))/2LL;
            crr=0LL;
        }
    }
    total += (crr*(crr+1))/2LL;

    cout << total << endl;

    return 0;
}
