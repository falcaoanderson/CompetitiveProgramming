// 24/03/23 // 
#include <iostream>

using namespace std;

#define ll long long
#define endl "\n"

const int MAXN = 7;

string path;
bool ma[MAXN+3][MAXN+3];
int qnt = 0;
int aux_x[] = {-1, 0, 1, 0};
int aux_y[] = {0, 1, 0, -1};

inline bool valid(int i, int j){
    return ((1<=i && i<=MAXN && 1<=j && j<=MAXN) && !ma[i][j]);
}

int solve(int x, int y){
    if(x==MAXN && y==1)
        return (int)(qnt == MAXN*MAXN-1);
    
    //otimizacao 1
    if((!valid(x, y+1) && !valid(x, y-1) && valid(x-1, y) && valid(x+1, y))|| 
        (!valid(x-1, y) && !valid(x+1, y) && valid(x, y-1) && valid(x, y+1)))
        return 0; 
    
    int total = 0;

    if(path[qnt]!='?'){
        int k=0;
        if(path[qnt]=='U'){
            k=0;
        }
        else if(path[qnt]=='R'){
            k=1;
        }
        else if(path[qnt]=='D'){
            k=2;
        }
        else if(path[qnt]=='L'){
            k=3;
        }

        int nx = x + aux_x[k];
        int ny = y + aux_y[k];

        if(valid(nx, ny)){
            ma[nx][ny] = 1; qnt++;
            total = solve(nx, ny);
            ma[nx][ny] = 0; qnt--;
        }

        return total;
    }

    for(int k=0; k<4; k++){
        int nx = x + aux_x[k];
        int ny = y + aux_y[k];

        if(valid(nx, ny)){
            ma[nx][ny] = 1; qnt++;
            total += solve(nx, ny);
            ma[nx][ny] = 0; qnt--;
        }
    }

    return total;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> path;

    ma[1][1] = true;
    cout << solve(1, 1) << endl;   

    return 0;
}