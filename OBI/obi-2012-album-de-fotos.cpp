// 19/10/20 // 18:53 PM //

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define pb push_back
#define mp make_pair
//#define int long long

const int MAXN = (1e5) + 10;

int main(){
    fast_io;

    int x, y, a1, b1, a2, b2;
    cin >> x >> y >> a1 >> b1 >> a2 >> b2;

    if((a1+a2<=x && max(b1,b2)<=y)||(max(a1,a2)<=x && b1+b2<=y)||
       (b1+a2<=x && max(a1,b2)<=y)||(max(b1,a2)<=x && a1+b2<=y)||
       (a1+b2<=x && max(b1,a2)<=y)||(max(a1,b2)<=x && b1+a2<=y)||
       (b1+b2<=x && max(a1,a2)<=y)||(max(b1,b2)<=x && a1+a2<=y))
        cout << "S" << endl;
    else
        cout << "N" << endl;

    return 0;
}

