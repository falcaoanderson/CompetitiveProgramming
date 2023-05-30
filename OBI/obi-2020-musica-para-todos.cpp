// 30/05/23 //
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

//const int INF  = 0x3f3f3f3f;
const int MAXN = (1e5) + 5;
//const int MOD  = (1e9) + 7;

int n, m, c;
int adora[MAXN], detesta[MAXN];
bool musica[MAXN];

int main(){
    fast_io;

    cin >> n >> m >> c;

    for(int i=1; i<=n; i++){
        int aux;
        cin >> adora[i] >> aux;

        if(detesta[aux]==0) detesta[aux] = i;
    }

    int resp = 0;
    bool loop=false;
    
    while(detesta[c]!=0){
        musica[c] = 1;

        resp++;
        c = adora[detesta[c]];

        if(musica[c]){
            loop = 1;
            break;
        }
    }

    if(loop){
        cout << "-1" << endl;
    }
    else{
        cout << resp << endl;
    }

    return 0;
}
