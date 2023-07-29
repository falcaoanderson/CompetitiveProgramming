// 29/07/23 //
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

const int MAXN = (2e5) + 5;

int n, bit[MAXN];

int query(int pos){
    int sum = 0;
    while(pos>0){
        sum += bit[pos];
        pos -= (pos&-pos);
    }
    return sum;
}
void update(int pos, int val){
    while(pos<=n){
        bit[pos] += val;
        pos += (pos&-pos);
    }
}

int bit_lower_bound(int val){
    int pos=0, sum=0;

    for(int i=17; i>=0; i--){
        if(pos+(1<<i)<=n && sum+bit[pos+(1<<i)]<val){
            sum += bit[pos+(1<<i)];
            pos += (1<<i);
        }
    }

    return pos+1;
}

int main(){
    fast_io;

    int k;
    cin >> n >> k;

    for(int i=1; i<=n; i++) bit[i] = (i&-i);

    int ind=1, crr_n = n;
    while(crr_n>0){
        ind = (ind+k-1)%crr_n + 1;
        
        int ind_bit = bit_lower_bound(ind);

        cout << ind_bit << " ";

        update(ind_bit, -1);

        crr_n--;
    }

    return 0;
}
