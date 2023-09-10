// 10/09/23 //
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

    int a, b, c;
    cin >> a >> b >> c;

    if(a==1){
        cout << 3 << endl;
    }
    else if(b==1 || c==1){
        cout << 1 << endl;
    }
    else if(a==-1){
        cout << 2 << endl;
    }
    else{
        cout << 3 << endl;
    }

    return 0;
}
