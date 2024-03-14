/*
14/03/24 
Problem: Atcoder ABC 343 - E 
Complexity: 
*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define PB push_back
#define EB emplace_back
#define FF first
#define SS second
#define sz(x) (int)(x).size()

typedef pair<int, int> pii;
typedef tuple<int, int, int> tiii;

const int INF  = 0x3f3f3f3f;
const  ll LINF = 0x3f3f3f3f3f3f3f3f;
const int MAXN = (2e5) + 5;
const int MOD  = (1e9) + 7;

struct Point{
    ll x=0LL, y=0LL, z=0LL;
    
    Point(){}
    Point(ll x_, ll y_, ll z_){
        x = x_;
        y = y_;
        z = z_;
    }
 
    ll norm2(){
        return x*x + y*y + z*z;
    }
    bool operator==(const Point &p){
        return (x==p.x && y==p.y && z==p.z);
    }
    Point operator+(const Point &p){
        return Point(x+p.x, y+p.y, z+p.z);
    }
    Point operator-(const Point &p){
        return Point(x-p.x, y-p.y, z-p.z);
    }
    bool operator<(const Point &p){
        return x<p.x && y<p.y && z<p.z;
    }
};
struct Retangle{
    Point a, b;
    
    Retangle(){}
    Retangle(Point a_, Point b_){
        a = a_;
        b = b_;
    }

    ll volume(){
        if((b.x-a.x)<0 || (b.y-a.y)<0 || (b.z-a.z)<0) return 0;
        return (b.x-a.x)*(b.y-a.y)*(b.z-a.z);
    }

    bool is_inside(ll x, ll y, ll z){
        return (a.x<=x && x<b.x) && (a.y<=y && y<b.y) && (a.z<=z && z<b.z);
    }
};

Point max(Point &a, Point &b){
    return Point( max(a.x, b.x), max(a.y, b.y), max(a.z, b.z) );
}
Point min(Point &a, Point &b){
    return Point( min(a.x, b.x), min(a.y, b.y), min(a.z, b.z) );
}
Retangle intersect(Retangle &r1, Retangle &r2){
    Point a = max(r1.a, r2.a), b = min(r1.b, r2.b);
    if(!(a<b)){
        a = Point(0, 0, 0);
        b = Point(0, 0, 0);
    }
    return Retangle(a, b);
}

bool possible=0;
ll v1, v2, v3;
Retangle ret[10];

void brute(int id){
    if(possible) return;

    if(id==3){
        Retangle rab  = intersect(ret[0], ret[1]);
        Retangle rac  = intersect(ret[0], ret[2]);
        Retangle rbc  = intersect(ret[1], ret[2]);
        Retangle rabc = intersect(   rab, ret[2]);

        ll va = ret[0].volume();
        ll vb = ret[1].volume();
        ll vc = ret[2].volume();
        ll vab = rab.volume();
        ll vac = rac.volume();
        ll vbc = rbc.volume();
        ll vabc = rabc.volume();

        ll pv1 =  va + vb + vc - 2*vab - 2*vac - 2*vbc + 3*vabc;
        ll pv2 = vab + vac + vbc - 3*vabc;

        possible = (pv1==v1 && pv2==v2 && vabc==v3);
        return;
    }   

    for(int i=-7; i<=7; i++){
        for(int j=-7; j<=7; j++){
            for(int k=-7; k<=7; k++){
                ret[id].a = Point(i, j, k);
                ret[id].b = Point(i+7, j+7, k+7);

                brute(id+1);
                if(possible) return;
            }
        }
    }
}

int main(){
    fast_io;

    cin >> v1 >> v2 >> v3;

    // if(v1 + v2*2 + v3*3 != 3*7*7*7){
    //     cout << "No" << endl;
    //     return 0;
    // }

    ret[0].b = Point(7, 7, 7);
    brute(1);

    if(possible){
        cout << "Yes" << endl;
        for(int i=0; i<3; i++){
            cout << ret[i].a.x << " " << ret[i].a.y << " " << ret[i].a.z << " ";
        }
    }
    else{
        cout << "No" << endl;
    }

    return 0;
}