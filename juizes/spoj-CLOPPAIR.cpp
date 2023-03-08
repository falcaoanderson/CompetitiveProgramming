// 25/11/20 // 4:02 PM //

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define xx first.second
#define yy first.first
#define id second

typedef pair<pair<double, double>, int> Point;

const int INF  = 0x3f3f3f3f;
const int MAXN = (5e4) + 10;

int n;
Point point[MAXN];

bool comp(Point a, Point b){
    return (a.xx<b.xx);
}

int main(){
    fast_io;

    cin >> n;
    for(int i=0; i<n; i++){
        cin >> point[i].xx >> point[i].yy;
        point[i].id=i;
    }

    sort(point, point+n, comp); // ordena por x

    double dist = 1e9;
    int a=0, b=0, l=0;
    set<Point> prox;

    for(int i=0; i<n; i++){
    
        while(l<i && point[l].xx-point[i].xx > dist){ // retira todos os pontos com x nao pertencente a [x1-dist, x1]
            prox.erase(point[l]);
            l++;
        }

        double x1 = point[i].xx, y1 = point[i].yy;

        set<Point>::iterator it = prox.lower_bound({{y1-dist, x1-dist}, 0}); // pega o primeiro ponto com o y2 >= y1-dist

        for( ;it!=prox.end() && (*it).yy-y1<=dist; it++){ // enquanto y2 <= y1+dist eu procuro um ponto mais proximo
            double x2 = (*it).xx, y2 = (*it).yy; int id2 = (*it).id; 

            double new_dist = sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));

            if(new_dist<dist){
                dist = new_dist;
                a = id2;
                b = point[i].id;
            }
        }

        prox.insert(point[i]);
    }

    cout << min(a, b) << " " << max(a, b) << " ";

    cout.precision(6);
    cout.setf(ios::fixed);
    
    cout << dist << endl;

    return 0;
}
