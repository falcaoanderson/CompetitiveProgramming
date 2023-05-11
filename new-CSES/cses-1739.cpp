// 11/05/23 // bit  2d // O(n^2 + q*log^2(n))
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
 
#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define PB push_back
#define ll long long
 
typedef pair<int, int> pii;
typedef tuple<int, int, int> tiii;
 
const int MAXN = (1e3) + 5;

int n;
int prefix[MAXN][MAXN], bit[MAXN][MAXN];
bool ma[MAXN][MAXN];

void update(int x, int y, int u){
    for(int i=x; i<=n; i+=(i&-i))
        for(int j=y; j<=n; j+=(j&-j))
            bit[i][j] += u;
}

int query(int x, int y){
    int sum = 0;

    for(int i=x; i>=1; i-=(i&-i))
        for(int j=y; j>=1; j-=(j&-j))
            sum += bit[i][j];

    return sum;
}

int main(){
    fast_io;
 
    int q;
    cin >> n >> q;
    
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            char temp;
            cin >> temp;
            
            ma[i][j] = (temp=='*');
            prefix[i][j] = prefix[i][j-1] + (int)(ma[i][j]);
        }
 
        for(int j=1; j<=n; j++){
            prefix[i][j] += prefix[i-1][j];
            
            int pi = (i&-i), pj= (j&-j);
            bit[i][j] = prefix[i][j] - prefix[i-pi][j] - prefix[i][j-pj] + prefix[i-pi][j-pj];
        }
    }
    
    while(q--){
        int op;
        cin >> op;

        if(op==1){
            int x, y;
            cin >> x >> y;

            if(ma[x][y]){
                ma[x][y] = 0;
                update(x, y, -1);
            }
            else{
                ma[x][y] = 1;
                update(x, y, +1);
            }
        }
        else{
            int x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;
    
            cout <<  query(x2, y2) -  query(x2, y1-1)  - query(x1-1, y2) +  query(x1-1, y1-1) << endl;
        }
    }
 
    return 0;
}