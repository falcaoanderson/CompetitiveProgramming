/*
31/08/25 

*/

#include <bits/stdc++.h>

using namespace std;

const int INF = 0x3f3f3f3f;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;


    int minx=INF, maxx=-INF, miny=INF, maxy=-INF;

    for(int i=0; i<n; i++){
        int x, y;
        cin >> x >> y;

        minx = min(minx, x);
        maxx = max(maxx, x);
        miny = min(miny, y);
        maxy = max(maxy, y);
    }

    cout << (maxx-minx+2)*2 + (maxy-miny+2)*2 << endl; 

    return 0;
}