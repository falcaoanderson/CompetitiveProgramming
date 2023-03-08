// 18/11/20 // xx:xx PM //

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define pb push_back
#define mp make_pair
#define ll long long
//#define int long long

typedef pair<int, int> pii;

const int INF  = 0x3f3f3f3f;
const int MAXN = (2e5) + 10;
const int MOD  = (1e9) + 7;

int n;
int v[MAXN], bit[MAXN];

void update(int i, int val){
    while(i<=n){
        bit[i] += val;
        i += (i&-i);
    }
}

int query(int i){
    int sum = 0;
    while(i>0){
        sum += bit[i];
        i -= (i&-i);
    }
    return sum;
}

int bb(int val){
    int pos = 0, sum=0;
    
    for(int i=22; i>=0; i--)
        if( (1<<i)+pos<=n && sum+bit[(1<<i)+pos]<val){
            pos += (1<<i);
            sum += bit[pos];
        }

    return pos+1;
}

int main(){
    fast_io;
    
    cin >> n;

    for(int i=1; i<=n; i++){
        cin >> v[i];
        update(i, 1);
    }

    for(int i=1; i<=n; i++){
        int pos;
        cin >> pos;

        int x = bb(pos);
        cout << v[x] << " ";
        update(x, -1);
    }

    return 0;
}
