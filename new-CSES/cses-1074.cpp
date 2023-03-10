#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 2e5+10;

int n;
long long int v[MAXN];

int main(){

    cin >> n;

    for(int i=1; i<=n; i++){
        cin >> v[i];
    }

    sort(v+1, v+n+1);

    long long int cust=0LL;
    int med = (n+1)/2;

    for(int i=1; i<=n; i++){
        cust += abs(v[i]-v[med]);
    }

    cout << cust << endl;

    return 0;
}