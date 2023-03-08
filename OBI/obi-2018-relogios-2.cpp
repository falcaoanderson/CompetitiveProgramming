// 28/04/19 // 1:12 PM //

#include <iostream>
#include <queue>
using namespace std;

#define MAXN 110
#define INF 2000000000
#define MP make_pair

typedef pair<int, pair<int, int>> pii;

int l, c , k;
int relogio[MAXN][MAXN];
int dist[MAXN][MAXN];
int visitado[MAXN][MAXN];

int aux_i[6] = {-1, 0, 1, 0, 0, 0};
int aux_j[6] = {0, 1, 0, -1, 0, 0};

priority_queue<pii, vector<pii>, greater<pii>> fila;

int mod(int a, int b){
    int temp = a % b;

    if(temp>=0) return temp;

    return (b + temp);
}

bool borda(int i, int j){
    if(i>l || i<1 || j>c || j<1)
        return 0;
    else
        return 1;
}


void dijikstra(){
    fila.push( MP( 0, MP(1,1) ) );
    dist[1][1] = 0;

    while(true){
        int i=-1, j=-1, new_i, new_j, new_dist;

        while(!fila.empty()){
            i = fila.top().second.first;
            j = fila.top().second.second;

            fila.pop();

            if(!visitado[i][j]) break;

            i = -1;
        }

        if(i==-1) break;

        visitado[i][j] == 1;

        for(int z=0; z<4; z++){
            new_i = i + aux_i[z];
            new_j = j + aux_j[z];

            if(borda(new_i, new_j)){
                if(relogio[new_i][new_j]==-1){
                    if(dist[i][j]+1 < dist[new_i][new_j]){
                        dist[new_i][new_j] = dist[i][j]+1;
                        fila.push( MP(dist[new_i][new_j], MP(new_i, new_j) ) );
                    }
                }
                else{
                    new_dist = mod(relogio[new_i][new_j] - mod(dist[i][j], k) ,k);
                    if(new_dist==0) new_dist=k;

                    if(new_dist>1 && relogio[i][j]!=-1) continue;

                    new_dist += dist[i][j];

                    if(new_dist<dist[new_i][new_j]){
                        dist[new_i][new_j] = new_dist;
                        fila.push( MP( new_dist, MP(new_i, new_j) ) );
                    }
                }
            }
        }
    }
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> l >> c >> k;

    for(int i=1; i<=l; i++)
        for(int j=1; j<=c; j++){
            cin >> relogio[i][j];
            dist[i][j] = INF;
        }

    dijikstra();

    if(dist[l][c]!=INF)
        cout << dist[l][c] << "\n";
    else
        cout << "-1\n";

    return 0;
}

