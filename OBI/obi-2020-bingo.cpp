// 29/05/23 //
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

const int MAXN = (1e3) + 5;
const int MAXU = (1e4) + 5;

int n, k, u, qnt[MAXN];
bool cartela[MAXN][MAXU];

int main(){
    fast_io;

    cin >> n >> k >> u;

    for(int i=0; i<n; i++){
        for(int j=0; j<k; j++){
            int num;
            cin >> num;

            cartela[i][num] = 1;
        }
        qnt[i] = k;
    }

    bool winner = 0;
    vector<int> resp;

    while(u--){
        int num;
        cin >> num;

        if(winner) continue;

        for(int i=0; i<n; i++){
            if(cartela[i][num]){
                cartela[i][num] = 0;
                qnt[i]--;

                if(qnt[i]==0){
                    winner = true;
                    resp.PB(i+1);
                }
            }   
        }
    }

    for(int i: resp) cout << i << " ";
    cout << endl;

    return 0;
}
