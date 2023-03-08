// 08/06/20 // 9:54 PM //

#include <bits/stdc++.h>

using namespace std;

const int MAXN = (int)(2e5)+10;

int n, bit[MAXN];

int query(int i){
    int sum = 0;

    while(i>0){
        sum += bit[i];
        i -= (i&-i);
    }

    return sum;
}
void update(int i, int val){
    while(i<=n){
        bit[i] += val;
        i += (i&-i);
    }
}

int main(){

    cin >> n;

    for(int i=1; i<=n; i++){
        int temp;
        cin >> temp;

        update(i, temp);
    }

    int q;
    cin >> q;

    while(q--){
        int a,b;
        cin >> a >> b;

        cout << query(b) - query(a-1) << endl;
    }

    return 0;
}
