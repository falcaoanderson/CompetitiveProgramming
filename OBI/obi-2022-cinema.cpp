// 24/08/23 //
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

const int INF  = 0x3f3f3f3f;
const int MAXN = (2e5) + 5;
const int MOD  = (1e9) + 7;

int main(){
    fast_io;

    int a, b;
    cin >> a >> b;

    int resp = 0;

    if(a<=17) resp += 15;
    else if(a<=59) resp += 30;
    else resp += 20;

    if(b<=17) resp += 15;
    else if(b<=59) resp += 30;
    else resp += 20;

    cout << resp << endl;

    return 0;
}
