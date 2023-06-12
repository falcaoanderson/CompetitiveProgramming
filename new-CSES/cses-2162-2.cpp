// 12/06/23 // O(n)
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

    int n;
    cin >> n;

    queue<int> game;
    for(int i=1; i<=n; i++) game.push(i);

    while(!game.empty()){
        game.push(game.front());
        game.pop();

        cout << game.front() << " ";
        game.pop();
    }
    cout << endl;

    return 0;
}
