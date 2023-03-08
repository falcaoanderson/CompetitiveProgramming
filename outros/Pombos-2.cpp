// 12/08/19 7:37 PM //

#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

#define MAXN 100010

int n, xx, yy;

struct point{
    int x, y;
};

point pombo[MAXN];

bool ordX(point a, point b){
    return a.x < b.x;
}
bool ordY(point a, point b){
    return a.y < b.y;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    for(int i=0; i<n; i++)
        cin >> pombo[i].x >> pombo[i].y;

    sort(pombo, pombo+n, ordX);
    //if(n%2==0)
    //    xx = (pombo[n/2].x + pombo[n/2 + 1].x)/2;
    //else
        xx = pombo[n/2].x;
    sort(pombo, pombo+n, ordY);
    //if(n%2==0)
    //    yy = (pombo[n/2].y + pombo[n/2 + 1].y)/2;
    //else
        yy = pombo[n/2].y;



    long long resp = 0LL;
    for(int i=0; i<n; i++)
        resp += abs( xx - pombo[i].x) + abs( yy - pombo[i].y);

    cout << resp << "\n";

    return 0;
}

