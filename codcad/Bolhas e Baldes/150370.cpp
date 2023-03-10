// 17/09/19 // 5:00 PM //

#include <bits/stdc++.h>

using namespace std;

#define MAXN 100010

int n, v[MAXN];
int bit[MAXN];

void update(int i, int sum){
    while(i<=n){
        bit[i] += sum;
        i += (i & -i);
    }
}

int query(int i){
    int sum=0;

    while(i>0){
        sum += bit[i];
        i   -= (i & -i);
    }

    return sum;
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    while(cin>>n && n!=0){

        int inv=0;
        memset(bit, 0, sizeof(bit));

        for(int i=1; i<=n; i++) cin >> v[i];

        for(int i=n; i>=1; i--){
            inv += query(v[i]-1);

            update(v[i], 1);
        }

        if(inv&1) cout << "Marcelo\n";
        else      cout << "Carlos\n";

    }

    return 0;
}
