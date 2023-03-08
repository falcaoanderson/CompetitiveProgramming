// 04/11/20 // xx:xx PM //

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

int n, m;
char ma[MAXN][MAXN];
int dist_m[MAXN][MAXN], dist_p[MAXN][MAXN], ant[MAXN][MAXN];

int aux_x[] = {-1, 0, 1, 0, 0};
int aux_y[] = {0, 1, 0, -1, 0};

void bfsM(int x, int y){
    queue<pii> fila;
    fila.push(pii(x, y));
    dist_m[x][y] = 0;

    while(!fila.empty()){
        x = fila.front().first;
        y = fila.front().second;
        fila.pop();

        bool flag = 0;
        for(int k=0; k<4; k++){
            int nx = x + aux_x[k];
            int ny = y + aux_y[k];

            if(dist_m[nx][ny]!=-1 && dist_m[x][y]>dist_m[nx][ny]+1){
                flag = 1;
                break;
            }
        }
        if(flag) continue;

        for(int k=0; k<4; k++){
            int nx = x + aux_x[k];
            int ny = y + aux_y[k];

            if(nx<1 || nx>n || ny<1 || ny>m) continue;
            
            if(ma[nx][ny]=='.' && (dist_m[nx][ny]==-1 || dist_m[nx][ny]>dist_m[x][y]+1)){
                dist_m[nx][ny] = dist_m[x][y]+1;

                fila.push(pii(nx, ny));
            }
        }
    }
}

int main(){
    fast_io;
    memset(dist_m, -1, sizeof(dist_m));
    memset(dist_p, -1, sizeof(dist_p));

    cin >> n >> m;

    vector<pii> monster;
    pii start;

    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++){
            cin >> ma[i][j];

            if(ma[i][j]=='A') start = pii(i, j);
            if(ma[i][j]=='M'){
                dist_m[i][j] = 0;
                monster.pb(pii(i, j));
            }
        }

    for(pii pos: monster) bfsM(pos.first, pos.second);

    int x = start.first, y = start.second;
    queue<pii> fila;
    fila.push(start);
    dist_p[x][y] = 0;
    
    while(!fila.empty()){
        x = fila.front().first;
        y = fila.front().second;
        fila.pop();

        for(int k=0; k<4; k++){
            int nx = x + aux_x[k];
            int ny = y + aux_y[k];

            if(nx<1 || nx>n || ny<1 || ny>m) continue;

            if(ma[nx][ny]=='.' && (dist_p[nx][ny]==-1 || dist_p[nx][ny]>dist_p[x][y]+1)){
                dist_p[nx][ny] = dist_p[x][y]+1;
                ant[nx][ny] = k;
                fila.push(pii(nx, ny));
            }
        }
    }
    
    pii saida = pii(-1, -1);

    for(int i=1; i<=n; i++){
        if(dist_p[i][1]!=-1 && (dist_p[i][1]<dist_m[i][1] || dist_m[i][1]==-1)){
            saida = pii(i, 1);
        }
        if(dist_p[i][m]!=-1 && (dist_p[i][m]<dist_m[i][m] || dist_m[i][m]==-1)){
            saida = pii(i, m);
        }
        if(saida.first!=-1) break;
    }
    if(saida.first==-1)
    for(int j=1; j<=m; j++){
        if(dist_p[1][j]!=-1 && (dist_p[1][j]<dist_m[1][j] || dist_m[1][j]==-1)){
            saida = pii(1, j);
        }
        if(dist_p[n][j]!=-1 && (dist_p[n][j]<dist_m[n][j] || dist_m[n][j]==-1)){
            saida = pii(n, j);
        }
        if(saida.first!=-1) break;
    } 
    
    if(saida.first==-1){
        cout << "NO" << endl;
    }
    else{
        cout << "YES" << endl;

        x = saida.first;
        y = saida.second;
        
        stack<char> resp;

        while(ma[x][y]!='A'){
            if(ant[x][y]==0){
                resp.push('U');
                x++;
            }
            if(ant[x][y]==1){
                resp.push('R');
                y--;
            }
            if(ant[x][y]==2){
                resp.push('D');
                x--;
            }
            if(ant[x][y]==3){
                resp.push('L');
                y++;
            }
        }

        cout << resp.size() << endl;
        while(!resp.empty()){
            cout << resp.top();
            resp.pop();
        }
        cout << endl;
    }
    
    return 0;
}