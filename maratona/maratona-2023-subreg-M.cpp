// 06/08/23 //
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <tuple>
#include <cstring>
#include <stack>

using namespace std;

#define ll long long
#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define PB push_back
#define EB emplace_back
#define ff first
#define ss second

typedef pair<int, int> pii;
typedef tuple<int, int, int> tiii;

const int MAXN = 1e2+5;
const int INF = 0x3f3f3f3f;

int dist[MAXN][MAXN];

int main(){
    fast_io;

    int n;
    cin >> n;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin >> dist[i][j];
        }
    }


    bool coerente = true;
    for(int k=1; k<=n; k++){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(dist[i][k] + dist[k][j] < dist[i][j]){
                    coerente = false;
                }
            }
        }
    }

    if(!coerente){
        cout << -1 << endl;
        return 0;
    }

    int cont = 0;
    for(int k=1; k<=n; k++){
        for(int i=1; i<=n; i++){
            if(i==k) continue;
            for(int j=1; j<=n; j++){
                if(j==k) continue;

                if(dist[i][k] + dist[k][j] == dist[i][j]){
                    cont++;
                    dist[i][j] = INF;
                }
            }
        }
    }

    cout << cont/2 << endl;

    return 0;
}
