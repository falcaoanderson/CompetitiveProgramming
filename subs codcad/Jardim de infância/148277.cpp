// "att" 06/07/19 // 18:26 PM //
// 15/07/19 // 11:18 AM //

#include <iostream>
#include <cmath>

using namespace std;

struct point{
    double x, y;

    point(){}
    point(double _x, double _y){
        x = _x;
        y = _y;
    }

    point operator+(point &temp){
        return point(x + temp.x, y + temp.y);
    }
    point operator-(point &temp){
        return point(x - temp.x, y - temp.y);
    }
    double operator^(point &temp){         // produto vetorial
        return (x*temp.y - y*temp.x);
    }
    double operator~(){
        return (x*x + y*y);
    }
};
point p[20];

bool ponto_medio(){
    point p1 = (p[2]+p[3]);
    point p2 = (p[4]+p[5]);

    return (p1.x==p2.x && p1.y==p2.y);
}
double colinear(int a, int b, int c){
    point v1 = p[a] - p[b];
    point v2 = p[c] - p[b];

    return (v1^v2);
}

int sign(int x) { return (x < 0) ? -1 : 1; }

int main(){

    for(int i=1; i<=7; i++)
        cin >> p[i].x >> p[i].y;

    if( ~(p[2]-p[3])>= ~(p[1]-p[2]) + ~(p[1]-p[3]))
        cout << "N\n";
    else if( ~(p[1]-p[2]) != ~(p[1]-p[3]) )
        cout << "N\n";
    else if( colinear(3,2,4)!=0 || colinear(3,2,5)!=0)
        cout << "N\n";
    else if( !ponto_medio() )
        cout << "N\n";
    else if(~(p[2]-p[3])<=~(p[4]-p[5]))
        cout << "N\n";
    else if( (~(p[2]-p[6])!=~(p[2]-p[4]) + ~(p[4]-p[6])) || (~(p[3]-p[7])!=~(p[5]-p[3]) + ~(p[5]-p[7])))
        cout << "N\n";
    else if( ~(p[4]-p[6])!=~(p[5]-p[7]))
        cout << "N\n";
    else if( sign(colinear(3,2,1)) == sign(colinear(3,2,6)))
        cout << "N\n";
    else
        cout << "S\n";

    return 0;
}

