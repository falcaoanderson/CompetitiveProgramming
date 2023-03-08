// 30/08/19 // 9:22 PM //

#include <bits/stdc++.h>

using namespace std;

#define MAXN 200010
#define MAXL 500000010

int n;
int aux1[MAXL];
int aux2[MAXL];
stack<int> intervalos;

int main(){

    cin >> n;

    for(int i=1; i<=n; i++){
        int l, r;
        cin >> l >> r;

        if(l>500000000)
            aux2[l-500000000]=i;
        else
            aux1[l] = i;


        if(r>500000000)
            aux2[r-500000000]=i;
        else
            aux1[r] = i;
    }

    for(int i=1; i<=1000000000; i++){

    }

}
