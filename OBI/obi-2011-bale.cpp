// 20/10/20 // 9:45 PM //

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define pb push_back
#define mp make_pair
//#define int long long

const int INF  = 0x3f3f3f3f;
const int MAXN = (1e5) + 10;

int n, bit[MAXN];

void update(int i){
    while(i<=n){
        bit[i]++;
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

int main(){
    fast_io;

    cin >> n;
    int resp = 0;

    for(int i=0; i<n; i++){
        int temp;
        cin >> temp;

        resp += query(n)-query(temp);
        update(temp);
    }

    cout << resp << endl;

    return 0;
}
