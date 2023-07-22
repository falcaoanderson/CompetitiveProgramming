// 22/07/23 //
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

    string s1, s2;
    cin >> s1 >> s2;

    vector<int> pos(26);
    for(int i=0; i<(int)s2.size(); i++){
        pos[(int)s2[i] - 65] = i+1;
    }

    int a=-1, b=-1;
    for(int i=0; i<(int)s1.size(); i++){
        if(pos[(int)s1[i]-65]!=0){
            a = i+1;
            b = pos[(int)s1[i]-65];
        }
    }

    cout << a << " " << b << endl;

    return 0;
}
