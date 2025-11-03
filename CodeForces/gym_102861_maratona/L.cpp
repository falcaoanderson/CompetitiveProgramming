/*
05/10/25

*/

#include <bits/stdc++.h>

using namespace std;
#define fast_io ios_base::sync_with_stdio(0);cin.tie(0)
#define endl '\n'

const int MAXN = 40+5;

int l, c, n;
int grid[MAXN][MAXN];
int word_sz[20+5];
vector<int> word[20+5];
set<int> gridset[MAXN][MAXN];

bool in_grid(int x, int y){
    return 0<=x && x<l && 0<=y && y<c;
}

void check(int x, int y, int k){
    vector<int> freq(26, 0);

    for(int i=0; i<word_sz[k] && in_grid(x+i, y); i++){
        freq[grid[x+i][y]]++;
    }
    if(freq==word[k]){
        for(int i=0; i<word_sz[k] && in_grid(x+i, y); i++){
            gridset[x+i][y].insert(k);
        }
    }

    freq.assign(26, 0);
    for(int i=0; i<word_sz[k] && in_grid(x, y+i); i++){
        freq[grid[x][y+i]]++;
    }
    if(freq==word[k]){
        for(int i=0; i<word_sz[k] && in_grid(x, y+i); i++){
            gridset[x][y+i].insert(k);
        }
    }

    freq.assign(26, 0);
    for(int i=0; i<word_sz[k] && in_grid(x+i, y+i); i++){
        freq[grid[x+i][y+i]]++;
    }
    if(freq==word[k]){
        for(int i=0; i<word_sz[k] && in_grid(x+i, y+i); i++){
            gridset[x+i][y+i].insert(k);
        }
    }

    freq.assign(26, 0);
    for(int i=0; i<word_sz[k] && in_grid(x+i, y-i); i++){
        freq[grid[x+i][y-i]]++;
    }
    if(freq==word[k]){
        for(int i=0; i<word_sz[k] && in_grid(x+i, y-i); i++){
            gridset[x+i][y-i].insert(k);
        }
    }
}

int solve(){
    int resp = 0;

    for(int i=0; i<l; i++){
        for(int j=0; j<c; j++){
            for(int k=0; k<n; k++){
                check(i, j, k);
            }
        }
    }

    for(int i=0; i<l; i++){
        for(int j=0; j<c; j++){
            resp += (((int)gridset[i][j].size()) > 1);
        }
    }

    return resp;
}

int main() {
    fast_io;
    
    cin >> l >> c;
    
    for(int i=0; i<l; i++){
        for(int j=0; j<c; j++){
            char c;
            cin >> c;

            grid[i][j] = c - 'A';
        }
    }

    cin >> n;
    for(int i=0; i<n; i++){
        string s;
        cin >> s;

        word_sz[i] = s.size();
        word[i].assign(26, 0);
        
        for(char c: s) word[i][c-'A']++;
    }

    cout << solve() << endl;

    return 0;
}