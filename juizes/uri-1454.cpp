// 21/04/19 // 2:45 PM //

#include <iostream>

using namespace std;

#define MAXN 110
#define INF 2000000000

int n, m, k, cont=1;
int dist[MAXN][MAXN];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while(true){
        cin >> n >> m;
        if(n+m==0) break;

        cout << "Instancia " << cont << "\n";

        for(int i=1; i<=n; i++)
            for(int j=1; j<=n; j++){
                if(i==j)
                    dist[i][j] = 0;
                else
                    dist[i][j] = INF;
            }

        for(int i=0; i<m; i++){
            int a, b, h;

            cin >> a >> b >> h;

            dist[a][b] = dist[b][a] = min(dist[a][b], h);
        }

        for(int z=1; z<=n; z++)
            for(int i=1; i<=n; i++)
                for(int j=1; j<=n; j++)
                    dist[i][j] = min(dist[i][j], max(dist[i][z], dist[z][j]));


        cin >> k;

        for(int i=0; i<k; i++){
            int a, b;

            cin >> a >> b;
            if(a==b)
                cout << "0\n";
            else
                cout << dist[a][b] << "\n";
        }

        cout << "\n";

        cont++;
    }

    return 0;
}
