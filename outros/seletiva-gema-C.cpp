#include <bits/stdc++.h>
 
using namespace std;
 
#define PB push_back
#define EB emplace_back
#define endl "\n"
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
 
    int m, n;
    cin >> m >> n;
 
    cout << m*m-n*n << " " << 2*m*n << " " << m*m+n*n << endl;
 
    return 0;
}