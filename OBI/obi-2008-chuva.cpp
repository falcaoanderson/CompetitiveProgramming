// 05/11/20 // 6:23 PM //

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define pb push_back
#define mp make_pair
#define ll long long
//#define int long long

typedef pair<int, int> pii;

const int INF  = 0x3f3f3f3f;
const int MAXN = (1e3) + 10;

struct retangulo{
    int xi, yi, xf, yf;
};

int n, adj[MAXN][MAXN], dist[MAXN];

void dijkstra(){
    priority_queue<pii, vector<pii>, greater<pii>> fila;
    for(int i=0; i<n+2; i++) dist[i] = INF;

    dist[0] = 0;
    fila.push({dist[0], 0});

    while(!fila.empty()){
        int atual = fila.top().second;
        int d     = fila.top().first;
        fila.pop();

        if(d!=dist[atual]) continue;

        for(int i=0; i<n+2; i++){
            if(i==atual) continue;

            d = dist[atual] + adj[atual][i];

            if(d<dist[i]){
                dist[i] = d;

                fila.push({dist[i], i});
            }
        }
    }
}

int main(){
    fast_io;
    
    vector<retangulo> v;

    for(int i=0; i<2; i++){
        retangulo temp;
        cin >> temp.xi >> temp.yi;
        temp.xf = temp.xi;
        temp.yf = temp.yi;
        v.pb(temp);
    }

    cin >> n;

    for(int i=0; i<n; i++){
        retangulo atual;
        cin >> atual.xi >> atual.yi >> atual.xf >> atual.yf;

        if(atual.xi>atual.xf) swap(atual.xi, atual.xf);
        if(atual.yi>atual.yf) swap(atual.yi, atual.yf);

        v.pb(atual);
    }

    for(int i=0; i<n+2; i++){
        for(int j=i+1; j<n+2; j++){
            int dx=0, dy=0, a, b, c, d;
            
            // dx
            a = v[i].xi, b = v[i].xf;
            c = v[j].xi, d = v[j].xf;
            
            if((a<=c && c<=b) || (a<=d && d<=b) || (c<=a && a<=d) || (c<=b && b<=d)) 
                dx = 0;
            else 
                dx = min(abs(c-b), abs(a-d));

            //dy
            a = v[i].yi, b = v[i].yf;
            c = v[j].yi, d = v[j].yf;
            
            if((a<=c && c<=b) || (a<=d && d<=b) || (c<=a && a<=d) || (c<=b && b<=d)) 
                dy = 0;
            else 
                dy = min(abs(c-b), abs(a-d));
            

            adj[i][j] = adj[j][i] = (dx+dy);
        }
    }

    dijkstra();

    cout << dist[1] << endl;

    return 0;
}
