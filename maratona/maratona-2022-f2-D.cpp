// 19/09/23 //
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

    int n, h, w;
    cin >> n >> h >> w;

    while(n--){
        char c1, c2;
        cin >> c1 >> c2;

        if(c1=='Y' || w==0){
            cout << "Y ";
            h--;
            w++;
        }
        else{
            cout << "N ";
        }

        if(c2=='Y' || h==0){
            cout << "Y" << endl;
            h++;
            w--;
        }
        else{
            cout << "N" << endl;
        }
    }

    return 0;
}
