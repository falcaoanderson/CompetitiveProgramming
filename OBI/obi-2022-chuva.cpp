// 03/06/23 // prefix sum // O(n)
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

const int MAXVAL = (1e6) + 5;

int qnt[MAXVAL];

int main(){
    fast_io;

    int n, s;
    cin >> n >> s;

    int prefix=0, resp=0;
    qnt[0] = 1;

    for(int i=1; i<=n; i++){
        int val;
        cin >> val;

        prefix += val;

        if(prefix-s>=0){
            resp += qnt[prefix-s]; 
        }

        qnt[prefix]++;
    }

    cout << resp << endl;

    return 0;
}
