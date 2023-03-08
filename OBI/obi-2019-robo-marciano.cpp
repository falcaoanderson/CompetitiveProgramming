// 15/08/19 // 9:30 PM //

#include <bits/stdc++.h>

using namespace std;

#define MAXN 1010
#define pb push_back
#define mp make_pair
#define INF 0x3f3f3f3f

typedef pair<int, int> pii;
struct retangulo{
    int x1, y1, x2, y2;
};

int n;
int grafo[MAXN][MAXN];
int dist[MAXN];
bool visitado[MAXN];

vector<retangulo> nos;

bool sign(int i){
    if(i>=0)return 1;
    return 0;
}

void dijikstra(){

    priority_queue< pii, vector< pii >, greater< pii > > fila;

    for(int i=0; i<n+2; i++) dist[i] = INF;
    dist[0] = 0;

    fila.push( mp(dist[0], 0) ); // (dist, no);

    while(true){
        int atual=-1;

        while(!fila.empty()){
            atual = fila.top().second;

            fila.pop();

            if(!visitado[atual]) break;
            atual = -1;
        }

        if(atual==-1) break;

        visitado[atual] = 1;

        for(int i=0; i<n+2; i++){
            int temp_dist = dist[atual] + grafo[atual][i];

            if(temp_dist < dist[i]){
                dist[i] = temp_dist;

                fila.push( mp(dist[i], i) );
            }
        }

    }

}

int main(){

    retangulo tret;

    for(int i=0; i<2; i++){
        cin >> tret.x1 >> tret.y1;
        tret.x2 = tret.x1;
        tret.y2 = tret.y1;
        nos.pb(tret);
    }

    cin >> n;

    for(int i=0; i<n; i++){
        cin >> tret.x1 >> tret.y1 >> tret.x2 >> tret.y2;
        nos.pb(tret);
    }

    for(int i=0; i<n+2; i++){
        for(int j=i+1; j<n+2; j++){
            int a, b, c, d, distx, disty;

            // acho a menor distancia no eixo X

            a = nos[i].x1 - nos[j].x1;
            b = nos[i].x1 - nos[j].x2;
            c = nos[i].x2 - nos[j].x1;
            d = nos[i].x2 - nos[j].x2;

            if(sign(a)!=sign(c) || sign(b)!= sign(d) || sign(a)!=sign(b) || sign(c)!=sign(d))
                distx = 0;
            else
                distx = min( min(abs(a), abs(b)), min(abs(c), abs(d)) );

            // achor a menor distancia no eixo Y
            a = nos[i].y1 - nos[j].y1;
            b = nos[i].y1 - nos[j].y2;
            c = nos[i].y2 - nos[j].y1;
            d = nos[i].y2 - nos[j].y2;

            if( sign(a)!=sign(c) || sign(b)!= sign(d) || sign(a)!=sign(b) || sign(c)!=sign(d))
                disty = 0;
            else
                disty = min( min(abs(a), abs(b)), min(abs(c), abs(d)) );



            grafo[i][j] = grafo[j][i] = distx + disty;
        }
    }

    dijikstra();

    cout << dist[1] << "\n";

    return 0;
}
