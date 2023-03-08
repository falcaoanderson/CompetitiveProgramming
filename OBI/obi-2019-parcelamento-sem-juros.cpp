// 05/03/20 // 08:51 AM //

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

const int MAXN = 1010;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int v, p;
    cin >> v >> p;

    for(int i=0; i<v%p; i++)   cout << v/p + 1 << endl;
    for(int i=0; i<p-v%p; i++) cout << v/p << endl;

    return 0;
}
