// 29/09/20 // 8:56 PM //

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define mp make_pair

const int MAXN = 20;

int n, m, c, ma[MAXN][MAXN];
char cor[MAXN];

pair<int, int> ini[MAXN], fim[MAXN];
int aux_i[5] = {-1, 0, 1,  0, 0};
int aux_j[5] = { 0, 1, 0, -1, 0};

bool in_grid(int i, int j){
    return (1<=i && i<=n && 1<=j && j<=m);
}

bool dfs(int i, int j, int tcor, int faltam){
    bool resp = 0;

    for(int k=0; k<4; k++){
        int new_i = i + aux_i[k];
        int new_j = j + aux_j[k];

        if(!in_grid(new_i, new_j)) continue;

        if(ma[new_i][new_j]==0){
            ma[new_i][new_j] = tcor;

            resp = dfs(new_i, new_j, tcor, faltam-1);

            ma[new_i][new_j] = 0;
        }
        if(new_i==fim[tcor].first && new_j==fim[tcor].second){
            if(tcor==c)
                resp = (faltam==0);
            else
                resp = dfs(ini[tcor+1].first, ini[tcor+1].second, tcor+1, faltam);
        }

        if(resp) break;
    }


    return resp;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--){
        cin >> n >> m >> c;

        for(int i=1; i<=c; i++){
            cin >> cor[i];
            ini[i] = fim[i] = mp(0, 0);
        }

        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                char temp;
                cin >> temp;

                if(temp=='.')
                    ma[i][j] = 0;
                else{
                    for(int k=1; k<=c; k++)
                        if(temp==cor[k]){
                            ma[i][j] = k;

                            if(ini[k].first==0)
                                ini[k] = mp(i, j);
                            else
                                fim[k] = mp(i, j);
                        }
                }
            }
        }

        if(dfs(ini[1].first, ini[1].second, 1, n*m-2*c))
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }

    return 0;
}
