// 19/07/23 //
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

    int v1, v2, v3, m;
    cin >> v1 >> v2 >> v3 >> m;

    for(int i=v1; i<=2*v1; i++){
        for(int j=v2; j<=2*v2; j++){
            for(int k=v3; k<=2*v3; k++){
                if(m <= i  && 2*m<i &&
                   m <= j  && 2*m<j &&
                   m <= k  &&  k <= 2*m && 
                   i>j && j>k){
                    cout << i << endl << j << endl << k << endl;
                    return 0;
                   }
            }
        }
    }

    cout << -1 << endl;
    return 0;
}
