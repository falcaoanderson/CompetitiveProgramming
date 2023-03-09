#include <iostream>

using namespace std;

const int MAXN = 2e5+10;

int n, v[MAXN];

int abs(int x){
    return x>=0?x:-x;
}

int main(){

    cin >> n;

    for(int i=1; i<=n; i++){
        cin >> v[i];
    }

    int cust1=0, cust2=0;

    for(int i=1; i<=n; i++){
        cust1 = abs(v[i]-v[n/2]);
        cust2 = abs(v[i]-v[n/2 + 1]);
    }

    cout << min(cust1, cust2) << endl;

    return 0;
}