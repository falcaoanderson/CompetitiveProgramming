// 21/07/23 //
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

const int MAXX = (1e6);

bool v[MAXX + 5];

int main(){
    fast_io;

    int n;
    cin >> n;

    int resp = 1;

    while(n--){
        int x;
        cin >> x;

        if(v[x]) resp = max(resp, x);
        v[x] = 1;
    }

    for(int i=2; i<=MAXX; i++){
        bool flag=0;

        for(int j=i; j<=MAXX; j+=i){
            if(v[j]){
                if(flag){
                    resp = max(resp, i);
                    break;
                }

                flag = 1;
            }
        }
    }

    cout << resp << endl;

    return 0;
}
