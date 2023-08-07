// 07/08/23 //
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

    int count=0;

    while(true){
        int n;
        cin >> n;

        if(n==0) break;

        for(int i=1; i<=n; i++){
            int val;
            cin >> val;

            if(val==i){
                cout << "Teste " << (++count) << endl;
                cout << i << endl << endl;
            }
        }
    }

    return 0;
}
