// 28/04/19 // 1:12 PM //

#include <iostream>

using namespace std;

#define MAXN 110
#define INF 2000000000

int l, c , k;
int relogio[MAXN][MAXN];
int dist[MAXN][MAXN];
int aux_i[6] = {-1, 0, 1, 0, 0, 0};
int aux_j[6] = {0, 1, 0, -1, 0, 0};


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

void DFS(int i, int j, int tempo){
    int new_i, new_j, new_dist;
    dist[i][j] = tempo;

    //cout << "DFS: " << i << " " << j << " "<< tempo << "\n";

    for(int z=0; z<4; z++){
        new_i = i + aux_i[z];
        new_j = j + aux_j[z];

        if(borda(new_i, new_j)){
            if(relogio[new_i][new_j]==-1 && tempo+1 < dist[new_i][new_j])
                DFS(new_i, new_j, tempo+1);
            else{
                new_dist = mod( relogio[new_i][new_j] - mod(tempo, k), k);

                if(new_dist==0)new_dist=k;

                if(new_dist>1 && relogio[i][j]!=-1) continue;

                new_dist+=tempo;

                if(new_dist < dist[new_i][new_j]){
                    DFS(new_i, new_j, new_dist);
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

    DFS(1,1,0);

    if(dist[l][c]!=INF)
        cout << dist[l][c] << "\n";
    else
        cout << "-1\n";

    return 0;
}
