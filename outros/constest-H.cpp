#include <bits/stdc++.h>

using namespace std;

struct point{
    double x, y;

    point(){};
    point(double _x, double _y){
        x = _x;
        y = _y;
    }

    point operator-(point &temp){
        return point(x-temp.x, y-temp.y);
    }
};

double cross(point a, point b){
    return (a.x*b.y - a.y*b.x);
}

int main(){
    int n;

    cin >> n;

    cout.precision(3);
    cout.setf(ios::fixed);

    while(n--){
        point a, b, c, u, v;

        cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y;

        u = (a-b);
        v = (c-b);
        double area = abs(cross(u, v)/2);

        cout << area << endl;
    }

    return 0;
}
