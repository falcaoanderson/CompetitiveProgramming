// 03/11/20 // 7:41 PM //

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

int ant[MAXN][MAXN];
int aux_x[] = {-1, 0, 1, 0, 0};
int aux_y[] = {0, 1, 0, -1, 0};
char ma[MAXN][MAXN];

int main(){
    fast_io;

    int n, m;
    cin >> n >> m;

    int x=1, y=1;

    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++){
            cin >> ma[i][j];

            if(ma[i][j]=='A'){
                x = i;
                y = j;
            }
        }

    queue<pii> fila;
    fila.push(mp(x, y));
    
    while(!fila.empty()){
        x = fila.front().first;
        y = fila.front().second;
         fila.pop();

        for(int k=0; k<4; k++){
            int nx = x + aux_x[k];
            int ny = y + aux_y[k];
            
            if(nx<1 || nx>n || ny<1 || ny>m) continue;

            if(ma[nx][ny]=='.'){
                ma[nx][ny] = '#';
                ant[nx][ny] = k;

                fila.push(mp(nx, ny));  
            }
            if(ma[nx][ny]=='B'){
                ma[nx][ny] = '#';
                ant[nx][ny] = k;
                
                string caminho = "";
                while(ma[nx][ny]!='A'){
                    if(ma[nx][ny]=='.') break;
                    if(ant[nx][ny] == 0){
                        caminho += 'U';
                        nx++;
                    }
                    else if(ant[nx][ny] == 1){
                        caminho += 'R';
                        ny--;
                    }
                    else if(ant[nx][ny] == 2){
                        caminho += 'D';
                        nx--;
                    }
                    else if(ant[nx][ny] == 3){
                        caminho += 'L';
                        ny++;
                    }
                }
                
                cout << "YES" << endl;
                cout << caminho.size() << endl;
                reverse(caminho.begin(), caminho.end());
                cout << caminho << endl;

                return 0;
            }
        }
    }

    cout << "NO" << endl;

    return 0;
}
