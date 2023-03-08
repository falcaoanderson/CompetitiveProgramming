// 12/08/19 7:37 PM //

#include <iostream>
#include <cmath>

using namespace std;

#define MAXN 100010

int n;
pair<int, int> pombo[MAXN];
long long somax, somay;


int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    for(int i=1; i<=n; i++){
        cin >> pombo[i].first >> pombo[i].second;

        somax += pombo[i].first;
        somay += pombo[i].second;
    }

    somax = somax/n;
    somay = somay/n;

    long long resp = 0LL;

    for(int i=1; i<=n; i++)
        resp += abs(somax - pombo[i].first) + abs(somay - pombo[i].second);

    cout << resp << "\n";

    return 0;
}
