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
#define ff first
#define ss second

typedef pair<int, int> pii;
typedef tuple<int, int, int> tiii;

int main(){
    fast_io;

    string s1, s2;
    cin >> s1 >> s2;

    int d = ((int)s1[0]-(int)s2[0]+26)%26;
    bool flag = 1;

    for(int i=1; i<(int)s1.size(); i++){
        if(((int)s1[i]-(int)s2[i]+26)%26 != d) flag = 0;
    }

    cout << (flag? "S": "N") << endl;

    return 0;
}
