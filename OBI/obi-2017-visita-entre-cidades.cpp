// 22/03/19 // 9:57 AM //

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define MAXN 10010
#define PB push_back
typedef pair< int, int > par;

int n, a, b;
int dist[MAXN];
bool visitado[MAXN];
vector<par> vizinhos[MAXN];
queue<int> fila;

int BFS(){
    visitado[a] = 1;
    fila.push(a);

    while(!fila.empty()){
        int atual = fila.front();
        fila.pop();

        for(int i=0; i<vizinhos[atual].size(); i++){
            int temp_no = vizinhos[atual][i].first;
            int temp_d  = vizinhos[atual][i].second;

            if(!visitado[temp_no]){

                visitado[temp_no] = 1;
                dist[temp_no] = dist[atual] + temp_d;

                if(temp_no==b) return dist[temp_no];

                fila.push(temp_no);
            }
        }

    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> a >> b;

    for(int i=1; i<n; i++){
        int p, q, d;

        cin >> p >> q >> d;

        vizinhos[p].PB( par(q, d) );
        vizinhos[q].PB( par(p, d) );
    }

    cout << BFS() << "\n";

    return 0;
}

