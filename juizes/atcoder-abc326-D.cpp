/*
31/10/23 
Problem: ABC Puzzle - AtCoder Beginner Contest 326
Complexity: ?
*/

#include <iostream>

using namespace std;

#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)

int n;
int r[10], c[10];
bool solved = 0;

int qnt_row[10], qnt_col[10];
bool row[10][5], col[10][5];
int grid[10][10];
string dict = ".ABC";

void solve(int x, int y){
    if(solved) return;

    if(y==n){
        bool flag = 1;
        for(int k=0; k<3; k++){
            if(row[x][k]==0) flag = 0;
        }

        if(flag) solve(x+1, 0);
        return;
    }
    if(x==n){
        solved = 1;
        cout << "Yes" << endl;

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                cout << dict[grid[i][j]+1];
            }
            cout << endl;
        } 
        return;
    }    

    if(qnt_row[x]==0 && qnt_col[y]==0){
        if(r[x]==c[y]){
            
            grid[x][y] = r[x];
            qnt_row[x]++; qnt_col[y]++;
            row[x][r[x]] = col[y][r[x]] = 1;

            solve(x, y+1);

            qnt_row[x]--; qnt_col[y]--;
            row[x][r[x]] = col[y][r[x]] = 0;
        }
        
        grid[x][y] = -1;
        solve(x, y+1);
        return;
    }
    if(qnt_row[x]==0){
        if(col[y][r[x]] == 0){
            
            grid[x][y] = r[x];
            qnt_row[x]++; qnt_col[y]++;
            row[x][r[x]] = col[y][r[x]] = 1;

            solve(x, y+1);

            qnt_row[x]--; qnt_col[y]--;
            row[x][r[x]] = col[y][r[x]] = 0;
        }
        
        grid[x][y] = -1;
        solve(x, y+1);

        return;
    }
    if(qnt_col[y]==0){
        if(row[x][c[y]] == 0){
            
            grid[x][y] = c[y];
            qnt_row[x]++; qnt_col[y]++;
            row[x][c[y]] = col[y][c[y]] = 1;

            solve(x, y+1);

            qnt_row[x]--; qnt_col[y]--;
            row[x][c[y]] = col[y][c[y]] = 0;
        }
        
        grid[x][y] = -1;
        solve(x, y+1);

        return;
    }

    if(qnt_row[x]<3 && qnt_col[y]<3){
        for(int k=0; k<3; k++){
            if(row[x][k]==0 && col[y][k]==0){
                grid[x][y] = k;
                qnt_row[x]++; qnt_col[y]++;
                row[x][k] = col[y][k] = 1;

                solve(x, y+1);

                qnt_row[x]--; qnt_col[y]--;
                row[x][k] = col[y][k] = 0;
            }
        }
    }
    
    if(n-y-1>=3-qnt_row[x] && n-x-1>=3-qnt_col[y]){
        grid[x][y] = -1;
        solve(x, y+1);
    }
}

int main(){
    fast_io;
    
    string sr, sc;
    cin >> n >> sr >> sc;

    for(int i=0; i<n; i++){
        r[i] = int(sr[i]) - int('A');
        c[i] = int(sc[i]) - int('A');
    }

    solve(0, 0);

    if(!solved){
        cout << "No" << endl;
    }

    return 0;
}