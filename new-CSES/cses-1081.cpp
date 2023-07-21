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

const int MAXX = (1e6)+5;

bool divisor[MAXX];

int main(){
    fast_io;

    int n;
    cin >> n;

    int resp = 1;

    while(n--){
        int x;
        cin >> x;

        for(int i=1; i*i<=x; i++){
            if(x%i==0){
                if(divisor[i]) resp = max(resp, i);
                if(divisor[x/i]) resp = max(resp, x/i);

                divisor[i] = divisor[x/i] = 1;
            }
        }
    }

    cout << resp << endl;

    return 0;
}
